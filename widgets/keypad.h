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

signals:
    void numberClicked(QString number);

private:
  Ui::keypad *ui;
  void setupConnections();

private slots:
    void onButtonClicked(); // Slot to handle button clicks

};

#endif // KEYPAD_H
