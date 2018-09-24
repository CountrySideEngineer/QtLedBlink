#ifndef QTLEDBLINKMAINWINDOW_H
#define QTLEDBLINKMAINWINDOW_H

#include <QMainWindow>
#include <model/cgpiopin.h>

namespace Ui {
class QtLEDBlinkMainWindow;
}

class QtLEDBlinkMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtLEDBlinkMainWindow(QWidget *parent = nullptr);
    ~QtLEDBlinkMainWindow();

protected slots:
    void on_gpio02Button_clicked();
    void on_gpio03Button_clicked();
    void on_gpio04Button_clicked();
    void on_gpio05Button_clicked();

protected:
    void updateGpioPin(CGPIOPin& gpioPin);
    void updateGpioPinState(CGPIOPin& gpioPin, QWidget* dstWidget, QString resourceFile);

protected:
    CGPIOPin mGpioPin2;
    CGPIOPin mGpioPin3;
    CGPIOPin mGpioPin4;
    CGPIOPin mGpioPin17;

private:
    Ui::QtLEDBlinkMainWindow *ui;
};

#endif // QTLEDBLINKMAINWINDOW_H
