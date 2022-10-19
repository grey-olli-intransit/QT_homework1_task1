#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "math.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    a = ui->lineEdit->text();

    this->A = a.toDouble();

}


void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    b = ui->lineEdit->text();
    this->B = b.toDouble();
}


void MainWindow::on_lineEdit_3_textEdited(const QString &arg1)
{
    c = ui->lineEdit->text();
    this->C = c.toDouble();
}

// эта функция взята из Си, из дз что я когда-то делал. Теперь это С++ метод
int calcSquareEq(int a, int b, int c, double* x1, double* x2) {
    if(a==0 && b!=0) {
        // вырождение до линейного уравнения, один корень x=-c/b
        *x1=(double)-c/b;
     return 0;

    }
    if (a==0 && b==0) {
    //не имеет смысла(кроме c=0), вырождение до c=0, этому
    //удовлетворит любое x, так что возвращаем -1, как будто
    //нет корней - не генерировать же рандомные числа в x1 и x2!
    return -1;

    }
    if ( (b*b - 4*a*c) < 0 ) {
       // комплексные числа не рассматриваем, а без них корни из отрицательных
       // извлекать нельзя, так что решений нет.
       return -1;
    }
    if ((b*b-4*a*c) == 0) {
        // единственный корень
    *x1 = -b/(2*a);
        return 0;
    }
    // в остальных случаях два корня:
    *x1=((double)-b+sqrt((double)b*b - 4*a*c))/(2*a);
    *x2=((double)-b-sqrt((double)b*b - 4*a*c))/(2*a);
    return 1;
}


void MainWindow::on_pushButton_clicked()
{
    double root1, root2;
    qreal root1_aprox, root2_aprox;
    QString root1_str, root2_str, no_roots;

    // это основной метод в котором идёт обработка результатов рассчета
    int retval = calcSquareEq(A,B,C,&root1,&root2);
    if (retval == -1) {
       no_roots = "Решений нет/Бессмысленно";
        ui->lineEdit_5->text().clear();
        ui->lineEdit_5->text().append(no_roots);
    }
    else if (retval == 0) {
        root1_str = QString::number(root1,'g',6); // до 6 знаков после запятой
        ui->lineEdit_6->text().append(root1_str);
        ui->lineEdit_4->text().append("только один корень");
    }
    else if(retval == 1) {
        root1_str = QString::number(root1,'g',6); // до 6 знаков после запятой
        ui->lineEdit_6->text().append(root1_str);

        root2_str = QString::number(root2,'g',6); // до 6 знаков после запятой
        ui->lineEdit_4->text().append(&root2_str);
    }
    else {QString bugtriggered = "You triggered a bug - shouldn't be printed!";
          qDebug() << bugtriggered;
    }
}


void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    return;
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    this->A=arg1;
}

