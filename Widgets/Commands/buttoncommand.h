#pragma once

#include <QPushButton>
#include <QBoxLayout>
#include <QMessageBox>

#include "basecommand.h"

class ButtonCommand : public BaseCommand
{
public:
    ButtonCommand(const QString &buttonText);

    // BaseCommand interface
public:
    virtual void runCommand() override;

private:
    QBoxLayout _layout;
    QPushButton _button;
};

