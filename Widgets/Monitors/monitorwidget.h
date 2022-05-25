#pragma once

#include "basicwidget.h"
#include "basemonitor.h"

class MonitorWidget : public BasicWidget
{
public:
    MonitorWidget(const Roles &role, const QString &text = tr("Мониторы:"));
    virtual ~MonitorWidget() = default;

    void addMonitor(BaseMonitor &monitor);
};
