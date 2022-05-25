#include "fabrics.h"

//Auxiliary functions
void commandWidgetCreate(CommandWidget &widget, int count)
{
    for (int i = 0; i < count; ++i)
    {
        ButtonCommand *btnCmd = new ButtonCommand("Команда " + QString::number(i + 1));
        widget.addCommand(*btnCmd);
    }
}

void monitorWidgetCreate(MonitorWidget &widget, int count)
{
    for (int i = 0; i < count; ++i)
    {
        LabelMonitor *lblMonitor = new LabelMonitor("Монитор " + QString::number(i + 1));
        widget.addMonitor(*lblMonitor);
    }
}

//Commands
OperatorCommands::OperatorCommands() :
    CommandWidget(Roles(Roles::Type::OPERATOR))
{
    commandWidgetCreate(*this, 2);
}

TechnicianCommands::TechnicianCommands() :
    CommandWidget(Roles(Roles::Type::TECHNIACIAN))
{
    commandWidgetCreate(*this, 4);
}

EngineerCommands::EngineerCommands() :
    CommandWidget(Roles(Roles::Type::ENGINEER))
{
    commandWidgetCreate(*this, 6);
}

//Monitors
OperatorMonitors::OperatorMonitors() :
    MonitorWidget(Roles(Roles::Type::OPERATOR))
{
    monitorWidgetCreate(*this, 2);
}

TechnicianMonitors::TechnicianMonitors() :
    MonitorWidget(Roles(Roles::Type::TECHNIACIAN))
{
    monitorWidgetCreate(*this, 4);
}

EngineerMonitors::EngineerMonitors() :
    MonitorWidget(Roles(Roles::Type::ENGINEER))
{
    monitorWidgetCreate(*this, 6);
}

//BaseWidgetFactory
BasicWidget *BaseWidgetFactory::createLevel(const Roles &role)
{
    switch (role.type())
    {
    case Roles::Type::TECHNIACIAN:
        return createTechnicianLevel();
        break;
    case Roles::Type::ENGINEER:
        return createEngineerLevel();
        break;
    default:
        return createOperatorLevel();
        break;
    }
}

//CommandsFactory
BasicWidget *CommandsFactory::createOperatorLevel()
{
    return new OperatorCommands;
}

BasicWidget *CommandsFactory::createTechnicianLevel()
{
    return new TechnicianCommands;
}

BasicWidget *CommandsFactory::createEngineerLevel()
{
    return new EngineerCommands;
}

//MonitorsFactory
BasicWidget *MonitorsFactory::createOperatorLevel()
{
    return new OperatorMonitors;
}

BasicWidget *MonitorsFactory::createTechnicianLevel()
{
    return new TechnicianMonitors;
}

BasicWidget *MonitorsFactory::createEngineerLevel()
{
    return new EngineerMonitors;
}
