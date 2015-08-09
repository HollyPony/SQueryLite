#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class BaseDbListModel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionConnect_triggered();

private:
    Ui::MainWindow *ui;

    BaseDbListModel *_baseDbListModel;
};

#endif // MAINWINDOW_H
