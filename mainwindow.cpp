#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style_library.h"
#include <QGraphicsDropShadowEffect>
#include <QStackedWidget>
#include <QDebug>
#include <QFontDatabase>
#include <QLayout>
#include <QBoxLayout>

void MainWindow::loadFonts()
{
    int fontId = QFontDatabase::addApplicationFont(":/assets/font/Vazir.ttf");
    if (fontId == -1) {
        qDebug() << "❌ Font loading failed!";
        return;
    }

    QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).first();
    qDebug() << "✅ Loaded font:" << fontFamily;

    QString styleSheet = QString(
        "QWidget { font-family: '%1'; }"
    ).arg(fontFamily);

    this->setStyleSheet(styleSheet);
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   keypadWidget = new Keypad();
   replaceWidget(ui->login ,ui->keypad, keypadWidget);
   connect(keypadWidget, &Keypad::numberClicked, this, [](QString number){
//       qDebug() << "Received number from keypad:" << number;
   });
   StyleLibrary::applyDropShadow(keypadWidget);
}



void MainWindow::replaceWidget(QWidget *parentPage, QWidget *oldWidget, QWidget *newWidget) {
    if (!parentPage || !oldWidget || !newWidget) {
        qDebug() << "Error: One of the widgets is null!";
        return;
    }

    QRect geo = oldWidget->geometry();
    oldWidget->setParent(nullptr);
    oldWidget->deleteLater();

    newWidget->setParent(parentPage);
    newWidget->setGeometry(geo);
    newWidget->setEnabled(true);
    newWidget->setFocus();
    newWidget->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    newWidget->setAttribute(Qt::WA_OpaquePaintEvent, true);

    // Ensure it is the active widget in QStackedWidget
    QStackedWidget *stackedWidget = qobject_cast<QStackedWidget*>(parentPage->parentWidget());
    if (stackedWidget) {
        stackedWidget->setCurrentWidget(newWidget);
    }

    newWidget->update();
    newWidget->repaint();
}





MainWindow::~MainWindow()
{
    delete ui;
}


