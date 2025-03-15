#include "style_library.h"
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
namespace StyleLibrary {

void applyStyleSheet(QWidget *widget, const QString &styleSheet) {
    if (widget)
        widget->setStyleSheet(styleSheet);
}

/**
 * Applies a drop shadow effect to the given widget.
 *
 * @param widget The widget to which the shadow effect will be applied.
 * @param blurRadius The radius of the blur effect.
 * @param xOffset Horizontal offset of the shadow.
 * @param yOffset Vertical offset of the shadow.
 * @param color The color of the shadow (with alpha for transparency).
 */


void applyDropShadow(QWidget *widget, int blurRadius, int xOffset, int yOffset, const QColor &color) {
    if (!widget)
        return;

    // اندازه ویجت
    QSize widgetSize = widget->size();

    // ایجاد Pixmap برای سایه
    QPixmap shadowPixmap(widgetSize + QSize(blurRadius * 2, blurRadius * 2));
    shadowPixmap.fill(Qt::transparent);

    QPainter painter(&shadowPixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    // کشیدن سایه
    painter.setBrush(color);
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(blurRadius, blurRadius, widgetSize.width(), widgetSize.height(), 10, 10);

    // قرار دادن Pixmap در QLabel برای نمایش سایه
    QLabel *shadowLabel = new QLabel(widget->parentWidget());
    shadowLabel->setPixmap(shadowPixmap);
    shadowLabel->setGeometry(widget->x() - blurRadius + xOffset, widget->y() - blurRadius + yOffset, shadowPixmap.width(), shadowPixmap.height());
    shadowLabel->lower(); // پایین‌تر از ویجت قرار بگیرد
    shadowLabel->show();
}


/**
 * Returns a predefined dark theme style sheet.
 *
 * @return A QString containing the dark theme QSS.
 */
QString darkThemeStyle() {
    return QString(
        "QWidget {"
        "   background-color: #2d2d30;"
        "   color: #ffffff;"
        "}"
        "QPushButton {"
        "   background-color: #3e3e42;"
        "   border: none;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #505050;"
        "}"
    );
}

/**
 * Returns a predefined light theme style sheet.
 *
 * @return A QString containing the light theme QSS.
 */
QString lightThemeStyle() {
    return QString(
        "QWidget {"
        "   background-color: #f0f0f0;"
        "   color: #000000;"
        "}"
        "QPushButton {"
        "   background-color: #e0e0e0;"
        "   border: 1px solid #a0a0a0;"
        "   padding: 8px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #d0d0d0;"
        "}"
    );
}

} // namespace StyleLibrary
