#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _commandsWidget(new AuthBanner)
{
    ui->setupUi(this);
    ui->mainLayout->addWidget(_commandsWidget);

    connect(ui->authForm, &AuthForm::signalSignIn, this, &MainWindow::slotSignIn);
    connect(ui->authForm, &AuthForm::signalLogout, this, &MainWindow::slotLogout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotSignIn(const Roles &role)
{
    {
        auto basicWidget = qobject_cast<BasicWidget*>(_commandsWidget);
        if (basicWidget && basicWidget->role().type() == role.type())
            return;
    }

    CommandsFactory factory;
    BasicWidget *basicWidget = factory.createLevel(role);

    ui->mainLayout->replaceWidget(_commandsWidget, basicWidget);

    if (_commandsWidget)
        delete _commandsWidget;

    _commandsWidget = basicWidget;

    statusBar()->showMessage(Roles::roleName(role));
}

void MainWindow::slotLogout()
{   
    {
        AuthBanner banner;
        if (_commandsWidget->metaObject()->className() == banner.metaObject()->className())
            return;
    }

    QWidget *widget = new AuthBanner;

    ui->mainLayout->replaceWidget(_commandsWidget, widget);

    if (_commandsWidget)
        delete _commandsWidget;

    _commandsWidget = widget;

    statusBar()->clearMessage();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    auto res = QMessageBox::question(this,
                                     tr("Выход"),
                                     tr("Вы уверены?"),
                                     QMessageBox::Yes | QMessageBox::No,
                                     QMessageBox::No);

    if (res != QMessageBox::Yes)
    {
        event->ignore();
        return;
    }

    QApplication::exit(0);
}
