#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plotWidget->setWaveStep(ui->waveBox->value());

    this->setWindowTitle("Симулятор движения лодки по волнам");
    m_pTimer = new QTimer(this);
    m_pTimer->setInterval(30);

    connect(m_pTimer,SIGNAL(timeout()), this, SLOT(onTimeout()));
}

// ----------------------------------------------------

MainWindow::~MainWindow()
{
    delete ui;
}

// ----------------------------------------------------

void MainWindow::onTimeout()
{
    ui->plotWidget->update();
}

// ----------------------------------------------------

void MainWindow::on_startButton_clicked()
{
    m_pTimer->start();
}

// ----------------------------------------------------

void MainWindow::on_pauseButton_clicked()
{
     m_pTimer->stop();
}

// ----------------------------------------------------

void MainWindow::on_waveBox_valueChanged(double arg1)
{
    ui->plotWidget->setWaveStep(arg1);
}

// ----------------------------------------------------

void MainWindow::on_timerBox_valueChanged(int arg1)
{
    m_pTimer->setInterval(arg1);
}

