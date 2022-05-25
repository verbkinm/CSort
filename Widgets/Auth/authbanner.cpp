#include "authbanner.h"
#include "ui_authbanner.h"

AuthBanner::AuthBanner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthBanner)
{
    ui->setupUi(this);
}

AuthBanner::~AuthBanner()
{
    delete ui;
}
