#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_exitButton_clicked();

    void on_solutionLine_textChanged(const QString &arg1);

    void on_firstRoot_textChanged(const QString &arg1);

    void on_secondRoot_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    double A;
    double B;
    double C;
    int calcSquareEq(int a, int b, int c, double* x1, double* x2);
};
#endif // MAINWINDOW_H
