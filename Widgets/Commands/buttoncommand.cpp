#include "buttoncommand.h"

ButtonCommand::ButtonCommand(const QString &buttonText) :
    _layout(QBoxLayout::LeftToRight),
    _button(buttonText)
{
    _layout.addWidget(&_button);

    this->setLayout(&_layout);

    connect(&_button, &QPushButton::clicked, this, &ButtonCommand::runCommand);
}

void ButtonCommand::runCommand()
{
    QMessageBox::information(this,
                             tr("Команда"),
                             tr("Выполнена команда") + " \"" + _button.text() + "\"");
}
