#include <QDebug>
#include "qtledblinkmainwindow.h"
#include "ui_qtledblinkmainwindow.h"

QtLEDBlinkMainWindow::QtLEDBlinkMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtLEDBlinkMainWindow)
{
    ui->setupUi(this);
}

QtLEDBlinkMainWindow::~QtLEDBlinkMainWindow()
{
    delete ui;
}

/**
 * @brief Event handler called when gpio02Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio02Button_clicked()
{
    qDebug() << "QtLEDBlinkMainWindow::on_gpio02Button_clicked() called";
}

/**
 * @brief Event handler called when gpio03Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio03Button_clicked()
{
    qDebug() << "QtLEDBlinkMainWindow::on_gpio03Button_clicked() called";
}

/**
 * @brief Event handler called when gpio04Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio04Button_clicked()
{
    qDebug() << "QtLEDBlinkMainWindow::on_gpio04Button_clicked() called";
}

/**
 * @brief Event handler called when gpio05Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio05Button_clicked()
{
    qDebug() << "QtLEDBlinkMainWindow::on_gpio05Button_clicked() called";
}
