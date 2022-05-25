#include "authform.h"
#include "ui_authform.h"

const auto CRYPTO_ALGORITM = QCryptographicHash::Sha3_512;

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm),
    _settings(QSettings::IniFormat, QSettings::UserScope, "CSort", "Test task")
{
    ui->setupUi(this);

    // Имитация базы данных с паролями!!!
    if (!QFileInfo::exists(_settings.fileName()))
    {
        QCryptographicHash hasher(CRYPTO_ALGORITM);
        hasher.addData("111");
        _settings.setValue("TECHNIACIAN", hasher.result());
        hasher.reset();
        hasher.addData("222");
        _settings.setValue("ENGINEER", hasher.result());
    }

    connect(ui->signIn, &QPushButton::clicked, this, &AuthForm::slotSignIn);
    connect(ui->logout, &QPushButton::clicked, this, &AuthForm::signalLogout);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::slotSignIn()
{
    if (ui->password->text().isEmpty())
        return;

    QCryptographicHash hasher(CRYPTO_ALGORITM);
    hasher.addData(ui->password->text().toStdString().c_str());

    QByteArray inputPwd = hasher.result();

    Roles role;
    // Имитация базы данных с паролями!!!
    for (const auto &key : _settings.allKeys())
    {
        if (_settings.value(key).toByteArray() == inputPwd)
        {
            role = Roles::stringToRole(key);
            break;
        }
    }

    emit signalSignIn(role);
}

void AuthForm::slotLogout()
{


}
