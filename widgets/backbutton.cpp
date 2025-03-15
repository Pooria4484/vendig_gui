#include "backbutton.h"
#include "ui_backbutton.h"

backButton::backButton(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::backButton)
{
  ui->setupUi(this);
}

backButton::~backButton()
{
  delete ui;
}
