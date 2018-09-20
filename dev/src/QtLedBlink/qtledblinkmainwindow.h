#ifndef QTLEDBLINKMAINWINDOW_H
#define QTLEDBLINKMAINWINDOW_H

#include <QMainWindow>

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


private:
    Ui::QtLEDBlinkMainWindow *ui;
};

#endif // QTLEDBLINKMAINWINDOW_H
