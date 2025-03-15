#include "keypad.h"
#include "ui_keypad.h"

Keypad::Keypad(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::keypad)
{
  ui->setupUi(this);
}

Keypad::~Keypad()
{
  delete ui;
}
