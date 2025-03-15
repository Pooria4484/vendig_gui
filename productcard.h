#ifndef PRODUCTCARD_H
#define PRODUCTCARD_H

#include <QWidget>

namespace Ui {
  class ProductCard;
}

class ProductCard : public QWidget
{
  Q_OBJECT

public:
  explicit ProductCard(QWidget *parent = nullptr);
  ~ProductCard();

private:
  Ui::ProductCard *ui;
};

#endif // PRODUCTCARD_H
