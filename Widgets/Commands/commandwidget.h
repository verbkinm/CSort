#pragma once

#include <list>
#include <memory>

#include <QPushButton>

#include "monitorwidget.h"
#include "basecommand.h"

class CommandWidget : public BasicWidget
{
    Q_OBJECT

public:
    CommandWidget(const Roles &role, const QString &text = tr("Команды:"));
    virtual ~CommandWidget() = default;

    void addCommand(BaseCommand &command);

private:
    QPushButton _newWindowBtn;
    std::list<std::shared_ptr<BasicWidget>> _monitors;

private slots:
    void newWindow();
    void deleteWindow();
};
