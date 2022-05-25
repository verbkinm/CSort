#pragma once

#include "commandwidget.h"
#include "monitorwidget.h"
#include "buttoncommand.h"
#include "labelmonitor.h"

//Commands
class OperatorCommands : public CommandWidget
{
public:
    OperatorCommands();
};

class TechnicianCommands : public CommandWidget
{
public:
    TechnicianCommands();
};

class EngineerCommands : public CommandWidget
{
public:
    EngineerCommands();
};

//Monitors
class OperatorMonitors : public MonitorWidget
{
public:
    OperatorMonitors();
};

class TechnicianMonitors : public MonitorWidget
{
public:
    TechnicianMonitors();
};

class EngineerMonitors : public MonitorWidget
{
public:
    EngineerMonitors();
};

//Factores
class BaseWidgetFactory
{
public:
    BasicWidget *createLevel(const Roles &role);

    virtual BasicWidget *createOperatorLevel() = 0;
    virtual BasicWidget *createTechnicianLevel() = 0;
    virtual BasicWidget *createEngineerLevel() = 0;

    virtual ~BaseWidgetFactory() = default;
};

class CommandsFactory: public BaseWidgetFactory
{
public:
    BasicWidget *createOperatorLevel() override;
    BasicWidget *createTechnicianLevel() override;
    BasicWidget *createEngineerLevel() override;
};

class MonitorsFactory: public BaseWidgetFactory
{
public:
    BasicWidget *createOperatorLevel() override;
    BasicWidget *createTechnicianLevel() override;
    BasicWidget *createEngineerLevel() override;
};
