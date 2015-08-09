#ifndef CONNECTIONDIALOG_H
#define CONNECTIONDIALOG_H

#include <QtCore/QItemSelection>

#include <QtWidgets/QDialog>

class GenericServer;

namespace Ui {
class PropertiesDialog;
}

class PropertiesDialog : public QDialog
{
    Q_OBJECT

public:
    enum CONNECT_STATUS {
        YES,
        FAIL,
        RESET
    };

    explicit PropertiesDialog(GenericServer **genericDb = 0, QWidget *parent = 0);
    ~PropertiesDialog();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

    void updateConnectionString();

    void on_dbTypeCb_currentIndexChanged(int index);

    void on_testConnectionBtn_clicked();

private:
    void updateConnectStatus(CONNECT_STATUS status);

    Ui::PropertiesDialog *ui;

    GenericServer  *_currentDb;
    GenericServer **_genericDb;
};

#endif // CONNECTIONDIALOG_H
