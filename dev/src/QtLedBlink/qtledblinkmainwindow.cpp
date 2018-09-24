#include <QDebug>
#include <QFile>
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

    this->mGpioPin2.SetupPinMode(6, 1);
    this->mGpioPin3.SetupPinMode(13, 1);
    this->mGpioPin4.SetupPinMode(19, 1);
    this->mGpioPin17.SetupPinMode(26, 1);

    connect(this->ui->closeAppButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QFile styleSheetFile(":/qss/style.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(styleSheetFile.readAll());
    qApp->setStyleSheet(styleSheet);
    styleSheetFile.close();
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
    printf("on_gpio02Button_clicked\n");

    this->updateGpioPin(this->mGpioPin2);
}

/**
 * @brief Event handler called when gpio03Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio03Button_clicked()
{
    printf("on_gpio03Button_clicked\n");

    this->updateGpioPin(this->mGpioPin3);
}

/**
 * @brief Event handler called when gpio04Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio04Button_clicked()
{
    printf("on_gpio04Button_clicked\n");

    this->updateGpioPin(this->mGpioPin4);
}

/**
 * @brief Event handler called when gpio05Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio05Button_clicked()
{
    printf("on_gpio05Button_clicked\n");

    this->updateGpioPin(this->mGpioPin17);
}

void QtLEDBlinkMainWindow::updateGpioPin(CGPIOPin& gpioPin)
{
    int pinValue = gpioPin.GetPinValue();
    if (1 == pinValue) {
        pinValue = 0;
    } else {
        pinValue = 1;
    }
    printf("SET PIN = %d, LEVEL = %d\n", gpioPin.GetPin(), pinValue);
    gpioPin.SetPinValue(pinValue);
}
