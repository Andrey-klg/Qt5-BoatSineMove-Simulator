#include "my_widget.h"

my_widget::my_widget(QWidget *parent) //
    : QWidget{parent}
{
    Density = 2;
    offset = 0.1;
    currY = 0;
}

// ----------------------------------------------------

void my_widget::paintEvent(QPaintEvent *event) // рисовать
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setBrush(QColor("#ECFAFF"));
    painter.setPen(Qt::NoPen);
    painter.drawRect(this->rect());

    int startX = 0;
    int endX = width() - 0;
    int endY = height();

    QPainterPath waterPath;

    waterPath.moveTo(startX, endY);
    double w = Density*_PI/this->width();

    // Отрисовка волны
    offset += 0.1;
    for(int i = 0; i <= this->width(); i++)
    {
        double y = (double)(60 * sin(w/2*i + offset + 400*w)) + 280;
        waterPath.lineTo(i, y);

        if(i >= (shipPoint - calcDiap) && i <= (shipPoint + calcDiap))
        {
             wave_vec.append(y);
        }

        if(i==shipPoint)
            currY = y;
    }
    waterPath.lineTo(endX, endY);
    QColor waterColor = QColor("#00A2DB");
    waterColor.setAlpha(150);

    painter.setBrush(waterColor);
    painter.drawPath(waterPath);
    painter.save();

    // Построение корабля
    drawer::drawDeck(&painter,shipPoint,currY,calcDiap,calcAngle());

    painter.end();

    QWidget::paintEvent(event);
}

// ----------------------------------------------------

float my_widget::calcAngle()
{
    QPoint p1 = QPoint(0,wave_vec.first());
    QPoint p2 = QPoint(0,wave_vec.last());

    float Y_rez = abs(p1.y() - p2.y());

    float sinA = Y_rez / wave_vec.length();
    float angle = (asin(sinA)*180)/_PI;

    wave_vec.clear();

    if(p1.y() < p2.y())
        return angle;
    else
        return -angle;

    return 0;
}

// ----------------------------------------------------
