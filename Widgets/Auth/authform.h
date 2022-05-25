#pragma once

#include <QWidget>
#include <QSettings>
#include <QFileInfo>
#include <QCryptographicHash>

#include "roles.h"

namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

private:
    Ui::AuthForm *ui;

    QSettings _settings;

signals:
    void signalSignIn(const Roles &role);
    void signalLogout();

private slots:
    void slotSignIn();
    void slotLogout();
};
