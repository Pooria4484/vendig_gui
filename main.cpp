#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include "mainwindow.h"
#include <QWidget>
#include <QGraphicsDropShadowEffect>
#include <QColor>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow *mainWindow = new MainWindow();
    mainWindow->setWindowState(Qt::WindowFullScreen);

    QGraphicsScene scene;
    QGraphicsProxyWidget *proxy = scene.addWidget(mainWindow);

    proxy->setTransformOriginPoint(proxy->boundingRect().center());

    proxy->setRotation(270);

    QGraphicsView view(&scene);
    view.setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setWindowState(Qt::WindowFullScreen);
    view.show();


    return app.exec();
}
