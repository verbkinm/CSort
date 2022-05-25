#include "basicwidget.h"
#include "ui_basicwidget.h"

BasicWidget::BasicWidget(const Roles &role, const QString &text, QWidget *parent) :
    QWidget(parent),
    _role(role),
    ui(new Ui::BasicWidget)
{
    ui->setupUi(this);

    setWindowTitle(text);

    ui->groupBox->setTitle(text);
}

BasicWidget::~BasicWidget()
{
    delete ui;
}

void BasicWidget::addWidget(QWidget &widget)
{
    ui->groupBoxLayout->addWidget(&widget);
}

const Roles &BasicWidget::role() const
{
    return _role;
}

QBoxLayout &BasicWidget::mainLayout()
{
    return *ui->mainLayout;
}

void BasicWidget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    emit signalClose();
}
