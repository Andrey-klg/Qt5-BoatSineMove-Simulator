#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "my_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_pauseButton_clicked();

    void onTimeout();

    void on_waveBox_valueChanged(double arg1);

    void on_timerBox_valueChanged(int arg1);

private:
    QTimer *m_pTimer;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
