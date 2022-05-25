#pragma once

#include <QMainWindow>
#include <QCloseEvent>

#include "authform.h"
#include "authbanner.h"
#include "basicwidget.h"
#include "fabrics.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    AuthForm _auth;
    QWidget *_commandsWidget;

    // QWidget interface
protected:
    virtual void closeEvent(QCloseEvent *event) override;

private slots:
    void slotSignIn(const Roles &role);
    void slotLogout();
};
