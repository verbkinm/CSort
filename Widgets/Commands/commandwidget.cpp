#include "commandwidget.h"
#include "fabrics.h"

CommandWidget::CommandWidget(const Roles &role, const QString &text) : BasicWidget(role, text),
    _newWindowBtn(tr("Новое окно"))
{
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addSpacerItem(new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Minimum));
    layout->addWidget(&_newWindowBtn);
    mainLayout().addLayout(layout);

    connect(&_newWindowBtn, &QPushButton::clicked, this, &CommandWidget::newWindow);
}

void CommandWidget::addCommand(BaseCommand &command)
{
    addWidget(command);
}

void CommandWidget::newWindow()
{
    MonitorsFactory monFactory;
    auto basicWidget = _monitors.emplace_front(monFactory.createLevel(_role));

    basicWidget->setWindowTitle(Roles::roleName(_role));
    basicWidget->show();

    connect(basicWidget.get(), &BasicWidget::signalClose, this, &CommandWidget::deleteWindow);
}

void CommandWidget::deleteWindow()
{
    auto basicWidget = dynamic_cast<BasicWidget*>(sender());

    if (basicWidget == nullptr)
        return;

    auto it = std::find_if(_monitors.begin(), _monitors.end(),
                           [&](auto shPtr){ return shPtr.get() == basicWidget;});

    if (it != _monitors.end())
        _monitors.remove(*it);
}
