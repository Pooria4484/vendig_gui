#ifndef STYLELIBRARY_H
#define STYLELIBRARY_H

#include <QWidget>
#include <QString>

namespace StyleLibrary {

// Applies a custom style sheet to a widget.
void applyStyleSheet(QWidget *widget, const QString &styleSheet);

// Applies a drop shadow effect with custom parameters.
void applyDropShadow(QWidget *widget, int blurRadius = 20, int xOffset = 5, int yOffset = 5, const QColor &color = QColor(0, 0, 0, 160));

// Returns a predefined style sheet for a dark theme.
QString darkThemeStyle();

// Returns a predefined style sheet for a light theme.
QString lightThemeStyle();

} // namespace StyleLibrary

#endif // STYLELIBRARY_H
