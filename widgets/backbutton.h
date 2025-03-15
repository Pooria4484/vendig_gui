#ifndef BACKBUTTON_H
#define BACKBUTTON_H

#include <QWidget>

namespace Ui {
  class backButton;
}

class backButton : public QWidget
{
  Q_OBJECT

public:
  explicit backButton(QWidget *parent = nullptr);
  ~backButton();

private:
  Ui::backButton *ui;
};

#endif // BACKBUTTON_H
