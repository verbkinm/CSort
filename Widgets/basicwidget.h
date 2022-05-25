#pragma once

#include <QWidget>
#include <QLayout>

#include "roles.h"

namespace Ui {
class BasicWidget;
}

class BasicWidget : public QWidget
{
    Q_OBJECT

public:
    BasicWidget(const Roles &role, const QString &text, QWidget *parent = nullptr);
    virtual ~BasicWidget();

    const Roles &role() const;

protected:
    QBoxLayout &mainLayout();
    void addWidget(QWidget &widget);

    const Roles _role;

private:
    Ui::BasicWidget *ui;

    // QWidget interface
protected:
    virtual void closeEvent(QCloseEvent *event) override;

signals:
    void signalClose();
};
