#pragma once

#include <QWidget>

namespace Ui {
class AuthBanner;
}

class AuthBanner : public QWidget
{
    Q_OBJECT

public:
    AuthBanner(QWidget *parent = nullptr);
    ~AuthBanner();

private:
    Ui::AuthBanner *ui;
};

