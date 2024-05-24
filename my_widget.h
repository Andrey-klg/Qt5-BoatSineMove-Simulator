#ifndef MY_WIDGET_H
#define MY_WIDGET_H

#define _PI 3.1415

#include "math.h"
#include "paintProcedure.h"

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QPen>
#include <QDebug>

class my_widget : public QWidget
{
    Q_OBJECT
public:
    explicit my_widget(QWidget *parent = nullptr);

signals:

public:
    void setWaveStep(float value) { Density = value; }

private:
    float Density; // Плотность распределения волн
    float offset;  // смещение

    const int shipPoint = 200; // Не должно быть меньше 100!
    const int calcDiap = 80;   // Размах относительно ЦМ для расчёта угла наклона катера

    QList<float> wave_vec;
    float currY;


private slots:
    void paintEvent(QPaintEvent *event);

    float calcAngle(); // Функция динамического расчёта угла
};

#endif // MY_WIDGET_H
