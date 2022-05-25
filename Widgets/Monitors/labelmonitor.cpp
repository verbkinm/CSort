#include "labelmonitor.h"

LabelMonitor::LabelMonitor(const QString &labelText) :
    _layout(QBoxLayout::LeftToRight),
    _label(labelText)
{
    _label.setAlignment(Qt::AlignCenter);
    _layout.addWidget(&_label);

    this->setLayout(&_layout);
}

void LabelMonitor::setText(const QString &labelText)
{
    _label.setText(labelText);
}

QString LabelMonitor::text() const
{
    return _label.text();
}
