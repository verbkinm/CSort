#pragma once

#include <QWidget>

class BaseCommand : public QWidget
{
public:
    BaseCommand() = default;
    virtual ~BaseCommand() = default;

    virtual void runCommand() = 0;
};
