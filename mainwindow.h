#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool OnlyDigits();
    void SetDigits(bool);

private:
    bool digits_only = true;

    Ui::MainWindow *ui;
    void InitializeWindow();
    void ButtonConnection();
    bool IsThereDot();

public slots:
    void DotClicked();
    void EqualsClicked();
    void EqualsClickedComp();
    void BinFunClicked();
    void BinFunClicked2();
    void FunClicked();
    void FunClicked2();
    void NumberClicked();
    void NumberClicked2();
    void ClearInput();
    void BackSpace();
    void ClearInput2();
    void BackSpace2();
private slots:
    void on_solvelinear_clicked();
    void on_solvequadratic_clicked();
    void on_solvecubic_clicked();

    void ComputeMatrix();
};

#endif // MAINWINDOW_H
