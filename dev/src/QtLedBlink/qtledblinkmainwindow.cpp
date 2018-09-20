#include <QDebug>
#include <stdint.h>
#include "qtledblinkmainwindow.h"
#include "ui_qtledblinkmainwindow.h"
#include "model/cgpiopin.h"
#include "model/ciopin.h"

QtLEDBlinkMainWindow::QtLEDBlinkMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtLEDBlinkMainWindow)
{
    ui->setupUi(this);

    CIOPin::create();
    CGPIOPin gpioPin;
    gpioPin.SetupPinMode(2, 1); //GPIO2, OUTPUT

    connect(this->ui->closeAppButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

QtLEDBlinkMainWindow::~QtLEDBlinkMainWindow()
{
    delete ui;

    CIOPin::destroy();
}

/**
 * @brief Event handler called when gpio02Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio02Button_clicked()
{
    static int pinValue = 0;
    CGPIOPin gpioPin;
    gpioPin.SetPinValue(pinValue);
    if (0 == pinValue) {
        pinValue = 1;
    } else {
        pinValue = 0;
    }
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
