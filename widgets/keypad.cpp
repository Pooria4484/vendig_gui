#include "keypad.h"
#include "ui_keypad.h"
#include <QDebug>

Keypad::Keypad(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::keypad)
{
  ui->setupUi(this);
  this->setEnabled(true);
  this->setAttribute(Qt::WA_TransparentForMouseEvents, false);
  setupConnections();
}

Keypad::~Keypad()
{
  delete ui;
}

// Method to connect numeric buttons to the click handler slot
void Keypad::setupConnections()
{
    QList<QPushButton*> numeralButtons = {
        ui->pb0, ui->pb1, ui->pb2, ui->pb3, ui->pb4,
        ui->pb5, ui->pb6, ui->pb7, ui->pb8, ui->pb9,ui->pb_bs, ui->pb_clear
    };

    for (QPushButton *button : numeralButtons) {
        if (!button) {
            qDebug() << "Error: A button is NULL!";
            continue;
        }
//        qDebug() << "Connecting button:" << button->objectName();
        connect(button, &QPushButton::clicked, this, &Keypad::onButtonClicked);
    }
}



// Slot triggered when a numeric button is clicked
void Keypad::onButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        try {
            QPushButton *button = qobject_cast<QPushButton*>(sender());
            if (!button) {
                throw std::runtime_error("Error: sender() is not a QPushButton");
            }

            QString number = button->text();
            emit numberClicked(number); // Emit signal with the clicked number
        }
        catch (const std::exception &e) {  // Catch standard exceptions
            qDebug() << "Exception caught:" << e.what();
        }
        catch (...) {  // Catch any other unknown exceptions
            qDebug() << "Unknown error occurred in button click handler!";
        }

//        qDebug() << "Button clicked:" << number;

    }
}
