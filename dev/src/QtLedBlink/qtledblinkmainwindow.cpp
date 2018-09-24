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
    this->updateGpioPinState(this->mGpioPin2, this->ui->gpio02OnOffLabel,
                             QString("style_on_off.qss"));
}

/**
 * @brief Event handler called when gpio03Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio03Button_clicked()
{
    printf("on_gpio03Button_clicked\n");

    this->updateGpioPin(this->mGpioPin3);
    this->updateGpioPinState(this->mGpioPin3, this->ui->gpio03OnOffLabel,
                             QString("style_on_off.qss"));
}

/**
 * @brief Event handler called when gpio04Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio04Button_clicked()
{
    printf("on_gpio04Button_clicked\n");

    this->updateGpioPin(this->mGpioPin4);
    this->updateGpioPinState(this->mGpioPin4, this->ui->gpio04OnOffLabel,
                             QString("style_on_off.qss"));
}

/**
 * @brief Event handler called when gpio05Button is clicked.
 */
void QtLEDBlinkMainWindow::on_gpio05Button_clicked()
{
    printf("on_gpio05Button_clicked\n");

    this->updateGpioPin(this->mGpioPin17);
    this->updateGpioPinState(this->mGpioPin17, this->ui->gpio05OnOffLabel,
                             QString("style_on_off.qss"));
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

void QtLEDBlinkMainWindow::updateGpioPinState(
        CGPIOPin& gpioPin, QWidget* dstWidget, QString resourceFile)
{
    QLabel* dstLabel = dynamic_cast<QLabel*>(dstWidget);
    QString dstLabelText;

    if (1 == gpioPin.GetPinValue()) {
        dstLabelText = QString("on");
    } else {
        dstLabelText = QString("off");
    }

    dstLabel->setText(dstLabelText);
    QString styleSheetFileName = ":/qss/" + resourceFile;
    QFile styleSheetFile(styleSheetFileName);
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QString::fromLatin1(styleSheetFile.readAll());
    dstLabel->setStyleSheet(styleSheet);
    styleSheetFile.close();
}

