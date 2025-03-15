#include "productcard.h"
#include "ui_productcard.h"

ProductCard::ProductCard(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ProductCard)
{
  ui->setupUi(this);
}

ProductCard::~ProductCard()
{
  delete ui;
}
