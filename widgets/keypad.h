#ifndef KEYPAD_H
#define KEYPAD_H

#include <QWidget>

namespace Ui {
  class keypad;
}

class Keypad : public QWidget
{
  Q_OBJECT

public:
  explicit Keypad(QWidget *parent = nullptr);
  ~Keypad();

private:
  Ui::keypad *ui;
};

#endif // KEYPAD_H
