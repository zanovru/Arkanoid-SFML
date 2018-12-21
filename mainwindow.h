#pragma once
#include <QMainWindow>
#include "MyClass.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
public slots:
    void changeWindow();


private:
    Ui::MainWindow *ui;
};


