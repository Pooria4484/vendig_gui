#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widgets/keypad.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Keypad *keypadWidget;
    QWidget *kypad;
    Ui::MainWindow *ui;
    void loadFonts();
    void replaceWidget(QWidget *parentPage, QWidget *oldWidget, QWidget *newWidget);
};
#endif // MAINWINDOW_H
