#include "propertiesdialog.h"
#include "ui_propertiesdialog.h"

#include "drivers/genericserver.h"
#include "drivers/genericdatabase.h"
#include "drivers/mongodb.h"
#include "drivers/enumdrivers.h"

#include <QtCore/QDebug>

PropertiesDialog::PropertiesDialog(GenericServer **genericDb, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertiesDialog) {
    ui->setupUi(this);

    _currentDb = 0;
    _genericDb = genericDb;

    ui->dbTypeCb->insertItem(MONGODB.index(), MONGODB.name());
    ui->dbTypeCb->insertItem(  MYSQL.index(),   MYSQL.name());
    ui->dbTypeCb->insertItem(  MSSQL.index(),   MSSQL.name());
    ui->dbTypeCb->insertItem(  PGSQL.index(),   PGSQL.name());

    // Map fields
    {
        this->connect(ui->hostLe,      SIGNAL(textChanged(QString)),      this, SLOT(updateConnectionString()));
        this->connect(ui->hostLe,      SIGNAL(textEdited(QString)),       this, SLOT(updateConnectionString()));
        this->connect(ui->portLe,      SIGNAL(textChanged(QString)),      this, SLOT(updateConnectionString()));
        this->connect(ui->portLe,      SIGNAL(textEdited(QString)),       this, SLOT(updateConnectionString()));
        this->connect(ui->userLe,      SIGNAL(textChanged(QString)),      this, SLOT(updateConnectionString()));
        this->connect(ui->userLe,      SIGNAL(textEdited(QString)),       this, SLOT(updateConnectionString()));
        this->connect(ui->passLe,      SIGNAL(textChanged(QString)),      this, SLOT(updateConnectionString()));
        this->connect(ui->passLe,      SIGNAL(textEdited(QString)),       this, SLOT(updateConnectionString()));
        this->connect(ui->databasesCb, SIGNAL(currentIndexChanged(int)),  this, SLOT(updateConnectionString()));
    }

    ui->portLe->setValidator(new QIntValidator(1, 65535, this));
}

PropertiesDialog::~PropertiesDialog() {
    delete ui;
}

void PropertiesDialog::on_buttonBox_accepted()
{
    if (_currentDb)
        _currentDb->name(ui->nameLe->text());
    *_genericDb = _currentDb;
}

void PropertiesDialog::on_buttonBox_rejected()
{
    *_genericDb = 0;
}

void PropertiesDialog::updateConnectionString()
{
    updateConnectStatus(PropertiesDialog::RESET);
    if (_currentDb) {
        _currentDb->host(ui->hostLe->text());
        _currentDb->port(ui->portLe->text().toUShort());
        _currentDb->user(ui->userLe->text());
        _currentDb->pass(ui->passLe->text());
        ui->connectionStringLe->setText(_currentDb->toConnectionString());
    }
}

void PropertiesDialog::on_dbTypeCb_currentIndexChanged(int index)
{
    if (_currentDb)
        _currentDb->deleteLater();

    if (index == MONGODB.index())
        _currentDb = new MongoDb(parent());
    else if (index == MYSQL.index())
        _currentDb = 0;
    else if (index == MSSQL.index())
        _currentDb = 0;
    else if (index == PGSQL.index())
        _currentDb = 0;
    else
        _currentDb = 0;

    updateConnectionString();
}

void PropertiesDialog::on_testConnectionBtn_clicked()
{
    if (_currentDb) {
        updateConnectStatus( (_currentDb->connect()) ? PropertiesDialog::YES : PropertiesDialog::FAIL);
        foreach (const GenericDatabase *database , _currentDb->databases())
            ui->databasesCb->addItem(database->name());
    }
}

void PropertiesDialog::updateConnectStatus(PropertiesDialog::CONNECT_STATUS status)
{
    switch (status) {
    case YES:
        ui->testConnectionLbl->setText(tr("Succesful"));
        break;
    case FAIL:
        ui->testConnectionLbl->setText(tr("Fail"));
        break;
    case RESET:
        ui->testConnectionLbl->setText("");
        break;
    }
}
