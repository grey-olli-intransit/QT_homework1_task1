#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

static QString a="0.0";
static QString b="0.0";
static QString c="0.0";

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
    void on_lineEdit_textEdited(const QString &arg1);

    void on_lineEdit_2_textEdited(const QString &arg1);

    void on_lineEdit_3_textEdited(const QString &arg1);

    void on_pushButton_clicked();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    double A;
    double B;
    double C;
    int calcSquareEq(int a, int b, int c, double* x1, double* x2);
};
#endif // MAINWINDOW_H
