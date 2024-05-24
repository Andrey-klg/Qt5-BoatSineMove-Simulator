#ifndef PAINTPROCEDURE_H
#define PAINTPROCEDURE_H

#include "QPainter"
#include <QDebug>

class drawer
{

public:
    static void drawDeck(QPainter *painter, int x, int y, int shift, float angle = 0)
    {
         QPolygon pol;

         QColor color;
         QPen qpen;
         color.setRgb(0, 0, 0, 255);

         if(angle != 0)
         {
            painter->translate(x,y);
            painter->rotate(angle);
            painter->translate(-x,-y);
         }

         QBrush brush;
         brush.setStyle(Qt::SolidPattern);
         painter->setBrush(brush);

         // Строим основной корпус лодки
         brush.setColor(Qt::lightGray);
         painter->setBrush(brush);
         pol.clear();
         pol << QPoint(x-shift+40,y-40) << QPoint(x+shift-20,y-40) << QPoint(x+shift-5,y-10) << QPoint(x-shift+40,y-10) << QPoint(x-shift+40,y-40);
         painter->drawPolygon(pol);

         // Строим основание лодки
         qpen.setWidth(2);
         qpen.setColor(color);
         painter->setPen(qpen);

         brush.setColor(QColor("#634631"));
         painter->setBrush(brush);
         pol.clear();
         pol << QPoint(x-shift,y-10) << QPoint(x+shift,y-10) << QPoint(x+shift-10, y+10) << QPoint(x-shift+10, y+10) << QPoint(x-shift,y-10);

         painter->drawPolygon(pol);

         // Строим окно
         qpen.setWidth(1);
         qpen.setColor(color);
         painter->setPen(qpen);

         brush.setColor(QColor("#b1f2ff"));
         painter->setBrush(brush);
         pol.clear();
         pol << QPoint(x-shift+70,y-35) << QPoint(x+shift-25,y-35) << QPoint(x+shift-25, y-25) << QPoint(x-shift+70, y-25) << QPoint(x-shift+70,y-35);
         painter->drawPolygon(pol);

         painter->save();

         qpen.setWidth(1);
         qpen.setColor(color);
         painter->setPen(qpen);

         // Строим флаг (белый)
         brush.setColor(QColor("#ffffff"));
         painter->setBrush(brush);
         pol.clear();
         pol << QPoint(x-shift+10,y-80) << QPoint(x-shift+30,y-80) << QPoint(x-shift+30,y-75) << QPoint(x-shift+10,y-75) << QPoint(x-shift+10,y-75);
         painter->drawPolygon(pol);

         // Строим флаг (Синий)
         brush.setColor(Qt::darkBlue);
         painter->setBrush(brush);
         pol.clear();
         pol << QPoint(x-shift+10,y-75) << QPoint(x-shift+30,y-75) << QPoint(x-shift+30,y-70) << QPoint(x-shift+10,y-70) << QPoint(x-shift+10,y-75);
         painter->drawPolygon(pol);

         // Строим флаг (Красный)
         brush.setColor(Qt::red);
         painter->setBrush(brush);
         pol.clear();
         pol << QPoint(x-shift+10,y-70) << QPoint(x-shift+30,y-70) << QPoint(x-shift+30,y-65) << QPoint(x-shift+10,y-65) << QPoint(x-shift+10,y-70);
         painter->drawPolygon(pol);
         painter->save();

         qpen.setWidth(2);
         painter->setPen(qpen);

         QLineF flagline;
         flagline.setP1(QPointF(x-shift+10,y-80));
         flagline.setP2(QPointF(x-shift+10,y-10));
         painter->drawLine(flagline);
         painter->save();

         // Гребной винт
         qpen.setWidth(3);

         QLineF engineLine;
         engineLine.setP1(QPointF(x-shift+3,y+6));
         engineLine.setP2(QPointF(x-shift+10,y+6));
         painter->drawLine(engineLine);
         painter->save();

         brush.setColor(QColor("#000000"));
         painter->setBrush(brush);
         pol.clear();
         pol << QPoint(x-shift-3,y+6) << QPoint(x-shift+3,y+6) << QPoint(x-shift-3,y+12) << QPoint(x-shift-3,y+6);
         painter->drawPolygon(pol);

         painter->save();

    }
};

#endif // PAINTPROCEDURE_H
