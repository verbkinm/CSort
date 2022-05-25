#pragma once

#include <QLabel>
#include <QBoxLayout>

#include "basemonitor.h"

class LabelMonitor : public BaseMonitor
{
public:
    LabelMonitor(const QString &labelText);

    void setText(const QString &labelText);
    QString text() const;

private:
    QBoxLayout _layout;
    QLabel _label;
};

