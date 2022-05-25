#include "monitorwidget.h"

MonitorWidget::MonitorWidget(const Roles &role, const QString &text) :
    BasicWidget(role, text)
{

}

void MonitorWidget::addMonitor(BaseMonitor &monitor)
{
    addWidget(monitor);
}
