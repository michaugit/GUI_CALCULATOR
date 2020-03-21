#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basic_operations.h"
#include "power_root.h"
#include "Complexx.h"
#include "exp_log.h"
#include "trigonometry.h"
#include "equations.h"
#include "matrix_functions.h"
#include <cmath>
#include <string>
#include <cstring>
#include <QMessageBox>
#include <cstdlib>

#if _WIN32
#define SEPARATOR '.'
#endif

#if __unix
#define SEPARATOR ','
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitializeWindow();
    ButtonConnection();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::OnlyDigits()
{
    return digits_only;
}

void MainWindow::SetDigits(bool new_state)
{
    digits_only = new_state;
}

void MainWindow::InitializeWindow()
{
    setWindowTitle("Kalkulator INPG");
    setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint);
    ui->pb_Invert->setText(QString::fromUtf8("x\u207B\u00B9"));

    ui->pb_Divide->setText(QString::fromUtf8("\u00F7"));
    ui->pb_Mult->setText(QString::fromUtf8("\u00D7"));

    ui->pb_Sqrt2->setText(QString::fromUtf8("\u221A"));
    ui->pb_Sqrt3->setText(QString::fromUtf8("\u00B3\u221A"));
    ui->pb_SqrtToN->setText(QString::fromUtf8("\u207F\u221A"));

    ui->pb_Pi->setText(QString::fromUtf8("\u03C0"));

    ui->pb_Xto2->setText(QString::fromUtf8("x\u00B2"));
    ui->pb_Xto3->setText(QString::fromUtf8("x\u00B3"));
    ui->pb_XtoN->setText(QString::fromUtf8("x\u207F"));

    ui->pb_EtoN->setText(QString::fromUtf8("e\u207F"));

    ui->pb_BackSpace->setText(QString::fromUtf8("\u232B"));

    ui->matrixResultLabel->setText(("Macierz\na b c  \nd e f  powinna zostać zapisana jako:{{a,b,c},{d,e,f},{g,h,i}}\ng h i  \n\nUżyj '*' dla mnożenia macierzy, '+' dla dodawania\nWpisanie jednej macierzy policzy wyznacznik"));
}

void MainWindow::ButtonConnection()
{
    connect(ui->pbsr,          SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb0_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb1_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb2_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb3_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb4_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb5_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb6_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb7_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb8_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pb9_2,         SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pbmin,         SIGNAL(clicked()), this, SLOT(BinFunClicked2()));
    connect(ui->pbp,           SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pbmin,         SIGNAL(clicked()), this, SLOT(BinFunClicked2()));
    connect(ui->pbdiv,         SIGNAL(clicked()), this, SLOT(BinFunClicked2()));
    connect(ui->pbmod,         SIGNAL(clicked()), this, SLOT(FunClicked2()));
    connect(ui->pbconj,        SIGNAL(clicked()), this, SLOT(FunClicked2()));
    connect(ui->pbr,           SIGNAL(clicked()), this, SLOT(EqualsClickedComp()));
    connect(ui->pb,            SIGNAL(clicked()), this, SLOT(NumberClicked2()));
    connect(ui->pbre,          SIGNAL(clicked()), this, SLOT(FunClicked2()));
    connect(ui->pbim,          SIGNAL(clicked()), this, SLOT(FunClicked2()));
    connect(ui->pbc,           SIGNAL(clicked()), this, SLOT(ClearInput2()));
    connect(ui->pbbs,          SIGNAL(clicked()), this, SLOT(BackSpace2()));
    connect(ui->pbm,          SIGNAL(clicked()), this, SLOT(NumberClicked2()));



    connect(ui->pb0,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb1,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb2,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb3,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb4,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb5,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb6,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb7,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb8,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb9,         SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb_Pi,       SIGNAL(clicked()), this, SLOT(NumberClicked()));
    connect(ui->pb_Plus,     SIGNAL(clicked()), this, SLOT(BinFunClicked()));
    connect(ui->pb_Minus,    SIGNAL(clicked()), this, SLOT(BinFunClicked()));
    connect(ui->pb_Mult,     SIGNAL(clicked()), this, SLOT(BinFunClicked()));
    connect(ui->pb_Divide,   SIGNAL(clicked()), this, SLOT(BinFunClicked()));
    connect(ui->pb_Sqrt2,    SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Invert,   SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Sin,      SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Sinh,     SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Cos,      SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Cosh,     SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Power,    SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Tg,       SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Tgh,      SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Ln,       SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Log,      SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_XtoN,     SIGNAL(clicked()), this, SLOT(BinFunClicked()));
    connect(ui->pb_Xto2,     SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Xto3,     SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Sqrt3,    SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_SqrtToN,  SIGNAL(clicked()), this, SLOT(BinFunClicked()));
    connect(ui->pb_EtoN,     SIGNAL(clicked()), this, SLOT(FunClicked()));
    connect(ui->pb_Equals,   SIGNAL(clicked()), this, SLOT(EqualsClicked()));
    connect(ui->pb_Dot,      SIGNAL(clicked()), this, SLOT(DotClicked()));
    connect(ui->pb_Clear,    SIGNAL(clicked()), this, SLOT(ClearInput()));
    connect(ui->pb_BackSpace,SIGNAL(clicked()), this, SLOT(BackSpace()));

    connect(ui->computeMatrixBtn,SIGNAL(clicked()), this, SLOT(ComputeMatrix()));
}

bool MainWindow::IsThereDot()
{
    bool ret=false;
    for(int i=0; i<ui->display->text().length(); ++i){
        if(ui->display->text().at(i) == SEPARATOR){
            ret=true;
        }
        if(ui->display->text().at(i)=='+' || ui->display->text().at(i)=='-'){
            ret=false;
        }
    }
    return ret;
}

void MainWindow::DotClicked()
{

    if (ui->display->text().length()) {

        if (!IsThereDot()){
            ui->display->setText(ui->display->text() + SEPARATOR);
        }
    } else{
        QString zero="0";
        ui->display->setText(zero + SEPARATOR + ui->display->text());
    }
}

void MainWindow::ClearInput()
{
    ui->display->clear();
    SetDigits(true);
}
void MainWindow::ClearInput2()
{
    ui->display_2->clear();
    SetDigits(true);
}



void MainWindow::BackSpace()
{
    int length = ui->display->text().length();
    if (length) {
        char last_char = ui->display->text().at(length - 1).toLatin1();
        if (!std::isdigit(last_char))
            SetDigits(true);
        ui->display->setText(ui->display->text().left(length - 1));
    }
}

void MainWindow::BackSpace2()
{
    int length = ui->display_2->text().length();
    if (length) {
        char last_char = ui->display_2->text().at(length - 1).toLatin1();
        if (!std::isdigit(last_char))
            SetDigits(true);
        ui->display_2->setText(ui->display_2->text().left(length - 1));
    }
}


void MainWindow::NumberClicked() {
    QString number = ((QPushButton*)sender())->text();
    if (number == "\u03C0") {
        double pi = 3.1415926535897932384626433832795;
        ui->display->setText(ui->display->text() + QString(std::to_string(pi).c_str()));

    }
    else
        ui->display->setText(ui->display->text() + number);
}

void MainWindow::NumberClicked2() {
    QString number = ((QPushButton*)sender())->text();
        ui->display_2->setText(ui->display_2->text() + number);
}

void MainWindow::EqualsClicked()
{
    try{
        SetDigits(true);
        std::string expression = ui->display->text().toStdString();
        std::string search_slice = expression.substr(1);
        std::string answer = "";
        if (!std::isdigit(*(expression.rbegin())))
            BackSpace();
        if (search_slice.find('+') != std::string::npos) {
            std::string::size_type position;
            double left_number  = std::stod(expression, &position);
            double right_number = std::stod(expression.substr(position + 1));
            double answer_number = plus(left_number,right_number);
            answer = std::to_string(answer_number);
            while (*(answer.rbegin()) == '0')
                answer.pop_back();
            if (*(answer.rbegin()) == SEPARATOR)
                answer.pop_back();
            ui->display->setText(QString(answer.c_str()));
        } else if (search_slice.find('-') != std::string::npos) {
            std::string::size_type position;
            double left_number  = std::stod(expression, &position);
            double right_number = std::stod(expression.substr(position + 1));
            double answer_number = minus(left_number,right_number);
            answer = std::to_string(answer_number);
            while (*(answer.rbegin()) == '0')
                answer.pop_back();
            if (*(answer.rbegin()) == SEPARATOR)
                answer.pop_back();
            ui->display->setText(QString(answer.c_str()));
        } else if (search_slice.find("\u00D7") != std::string::npos) { // *
            std::string::size_type position;
            double left_number  = std::stod(expression, &position);
            double right_number = std::stod(expression.substr(position + 2));
            double answer_number = multiply(left_number, right_number);
            answer = std::to_string(answer_number);
            while (*(answer.rbegin()) == '0')
                answer.pop_back();
            if (*(answer.rbegin()) == SEPARATOR)
                answer.pop_back();
            ui->display->setText(QString(answer.c_str()));
        } else if (search_slice.find("\u00F7") != std::string::npos) { // /
            std::string::size_type position;
            double left_number  = std::stod(expression, &position);
            double right_number = std::stod(expression.substr(position + 2));
            double answer_number = divide(left_number,right_number);
            answer = std::to_string(answer_number);
            while (*(answer.rbegin()) == '0')
                answer.pop_back();
            if (*(answer.rbegin()) == SEPARATOR)
                answer.pop_back();
            ui->display->setText(QString(answer.c_str()));
        } else if (search_slice.find(", x\u207F n = ") != std::string::npos) { // x^n
            std::string::size_type position;
            double left_number  = std::stod(expression, &position);
            double right_number = std::stod(ui->display->text().split(", x\u207F n = ")[1].toStdString());
            double answer_number = powerFunc(left_number, right_number);
            answer = std::to_string(answer_number);
            while (*(answer.rbegin()) == '0')
                answer.pop_back();
            if (*(answer.rbegin()) == SEPARATOR)
                answer.pop_back();
            ui->display->setText(QString(answer.c_str()));
        } else if (search_slice.find(", \u207F\u221Ax n = ") != std::string::npos) { // x^(1/n)
            std::string::size_type position;
            double left_number  = std::stod(expression, &position);
            double right_number = std::stod(ui->display->text().split(", \u207F\u221Ax n = ")[1].toStdString());
            double answer_number = rootFunc(left_number,right_number);
            answer = std::to_string(answer_number);
            while (*(answer.rbegin()) == '0')
                answer.pop_back();
            if (*(answer.rbegin()) == SEPARATOR)
                answer.pop_back();
            ui->display->setText(QString(answer.c_str()));
        }
    }
    catch(DivideByZero){
        QMessageBox::warning(this, "BŁĄD!", "Nie dziel przez 0! :)");
    }
    catch(...){
        QMessageBox::warning(this, "UPSSSSSS!", "Coś poszło nie tak! :( \nUpewnij się, że wszystko dobrze wprowadzasz! :)");
    }
}

void MainWindow::BinFunClicked()
{
    if (OnlyDigits()) {
        QString symbol = ((QPushButton*)sender())->text();
        if (ui->display->text().length()) {
            if (symbol == "x\u207F") // x^n
                ui->display->setText(ui->display->text() + ", x\u207F n = ");
            else if (symbol == "\u207F\u221A") // x^(1/n)
                ui->display->setText(ui->display->text() + ", \u207F\u221Ax n = ");
            else
                ui->display->setText(ui->display->text() + symbol);
            SetDigits(false);
        } else if (symbol == "-")
            ui->display->setText(symbol + ui->display->text());
    }

}

void MainWindow::BinFunClicked2()
{
    if (OnlyDigits()) {
        QString symbol = ((QPushButton*)sender())->text();
        if (ui->display_2->text().length()) {
            //if (symbol == "x\u207F") // x^n
              //  ui->display->setText(ui->display->text() + ", x\u207F n = ");
            //else if (symbol == "\u207F\u221A") // x^(1/n)
              //  ui->display->setText(ui->display->text() + ", \u207F\u221Ax n = ");
            //if//else
                ui->display_2->setText(ui->display_2->text() + symbol);
            SetDigits(false);
        } else if (symbol == "-")
            ui->display_2->setText(symbol + ui->display_2->text());
    }

}
void MainWindow::FunClicked2()
{
    try {
        SetDigits(true);
        QString symbol = ((QPushButton*)sender())->text();
        std::string expression=ui->display_2->text().toStdString();
         if(expression=="")return;
        double b,m;
            std::size_t offset = 0;
            m = std::stod(&expression[0], &offset);
            b = std::stod(&expression[offset + 1]);
           // y = std::stod(&expression[offset + 2]);
          //  x = std::stod(&expression[offset + 3]);
        Complexx z(m,b);
        if(symbol=="Mod")
            m=z.mod();
        else if(symbol=="Re")
            m=z.Re();
        else if(symbol=="Im")
            m=z.Im();
        else if (symbol=="Conj")
           m=z.argument();


        expression = std::to_string(m);
        ui->display_2->setText(QString(expression.c_str()));
    } catch (...) {
        QMessageBox::warning(this, "UPSSSSSS!", "Coś poszło nie tak! :( \nUpewnij się, że wszystko dobrze wprowadzasz! :)");

    }

}

void MainWindow::FunClicked()
{
    try{
        SetDigits(true);
        QString symbol = ((QPushButton*)sender())->text();
        std::string expression = ui->display->text().toStdString();
        if (expression == "")
            return;

        double number = std::stod(expression);

        if (symbol == "\u221A") // sqrt
            number = rootFunc(number,2);
        else if (symbol == "sin")
            number = sinCalc(number);
        else if (symbol == "sinh")
            number = sinhCalc(number);
        else if (symbol == "e\u207F") // exp
            number = expCalc(number);
        else if (symbol == "x\u00B2") // x^2
            number = powerFunc(number, 2);
        else if (symbol == "cosh")
            number = coshCalc(number);
        else if (symbol == "cos")
            number = coshCalc(number);
        else if (symbol == "ln")
            number = lnCalc(number);
        else if (symbol == "\u00B3\u221A") // x^(1/3)
            number = cbrtCalc(number);
        else if (symbol == "x\u00B3") // x^3
            number = powerFunc(number,3);
        else if (symbol == "tgh")
            number = tanhCalc(number);
        else if (symbol == "tan")
            number = tanCalc(number);
        else if (symbol == "log")
            number = log10Calc(number);
        else if (symbol == "n!") {
            if (std::floor(number) != number) {
                ui->display->setText(QString("nan"));
                return;
            }
            else
                number = factorial(number);
        }else if (symbol == "x\u207B\u00B9"){
            number = 1 / number;
            expression = std::to_string(number);
            while (*(expression.rbegin()) == '0')
                expression.pop_back();
            if (*(expression.rbegin()) == SEPARATOR)
                expression.pop_back();
            ui->display->setText(QString(expression.c_str()));
        }
        expression = std::to_string(number);
        while (*(expression.rbegin()) == '0')
            expression.pop_back();
        if (*(expression.rbegin()) == SEPARATOR)
            expression.pop_back();
        ui->display->setText(QString(expression.c_str()));
    }
    catch(NegativeFactorial){
        QMessageBox::warning(this, "BŁĄD!", "Nie można obliczyć silnii z ujemnej liczby! :)");
    }
    catch(...){
        QMessageBox::warning(this, "UPSSSSSS!", "Coś poszło nie tak! :( \nUpewnij się, że wszystko dobrze wprowadzasz! :)");
    }
}

void MainWindow::ComputeMatrix()
{
    std::string s = ui->matrixInputLabel->text().toUtf8().constData();
    std::string s1;
    try {
        s1 = matrixCheckInput(s);
    } catch (std::string ex) {
        ui->matrixResultLabel->setText(QString::fromStdString(ex));
    }
    catch(...){
        ui->matrixResultLabel->setText(QString::fromStdString("Computing Error"));
    }
    if(s1 != "")
        ui->matrixResultLabel->setText(QString::fromStdString(s1));
}
void MainWindow::on_solvelinear_clicked()
{
    double a = std::atof(ui->alinear->text().toStdString().c_str());
    double b = std::atof(ui->blinear->text().toStdString().c_str());
    QMessageBox::information(this, "ROZWIĄZANIE", QString::fromStdString(solve_linear_equation(a, b)));
}

void MainWindow::on_solvequadratic_clicked()
{
    double a = std::atof(ui->aquadratic->text().toStdString().c_str());
    double b = std::atof(ui->bquadratic->text().toStdString().c_str());
    double c = std::atof(ui->cquadratic->text().toStdString().c_str());
    QMessageBox::information(this, "ROZWIĄZANIE", QString::fromStdString(solve_quadratic_equation(a, b, c)));
}

void MainWindow::on_solvecubic_clicked()
{
    double a = std::atof(ui->acubic->text().toStdString().c_str());
    double b = std::atof(ui->bcubic->text().toStdString().c_str());
    double c = std::atof(ui->ccubic->text().toStdString().c_str());
    double d = std::atof(ui->dcubic->text().toStdString().c_str());
    QMessageBox::information(this, "ROZWIĄZANIE", QString::fromStdString(solve_cubic_equation(a, b, c, d)));
}
void MainWindow::EqualsClickedComp()
{
    try{
    SetDigits(true);
    Complexx z1,z2;
    std::string expression = ui->display_2->text().toStdString();
    int size=expression.size();
    double re1,im1,re2,im2,pos,pos2,ctr;
    std::string liczba1,liczba2,liczba3,liczba4;
    for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == ';')++ctr;
        }
        if (ctr != 2) throw("Blad");

    for (int i = 0; i < expression.length(); i++)
        {
            if (expression[i] == ';')
            {
                pos = i;
                for (int j = 0; j < pos; j++)
                {
                    liczba1 += expression[j];
                }
                for (int k = pos + 1; k < expression.length(); k++)
                {
                    if (expression[k] == '+'|| expression[k] == '-' || expression[k] == '*' || expression[k] == '/' )
                    {
                        pos2 = k;
                        for (int l = pos + 1; l < pos2; l++)
                        {
                            liczba2 += expression[l];
                        }
                    }
                }
                goto next;
            }
        }

    next:
        for (int i = pos2; i <= expression.length(); i++)
        {
            if (expression[i] == ';')
            {
                pos = i;
                for (int j = pos2+1; j < pos; j++)
                {
                    liczba3 += expression[j];
                }
                for (int k = pos + 1; k < expression.length(); k++)
                {
                            liczba4 += expression[k];


                }
            }
        }
z1.SetRe(std::stod(liczba1));
z1.SetIm(std::stod(liczba2));
z2.SetRe(std::stod(liczba3));
z2.SetIm(std::stod(liczba4));
if(expression[pos2]=='+') z1=z1+z2;
else if(expression[pos2]=='-') z1=z1-z2;
else if(expression[pos2]=='x') z1=z1*z2;
else if(expression[pos2]=='/') z1=z1/z2;


    //z1=z1+z2;
    std::string solution=std::to_string(z1.Re())+'+'+std::to_string(z1.Im());
   //std::string out=std::to_string(expression[pos2]);
    ui->display_2->setText(QString(solution.c_str()));
}
    catch(std::invalid_argument){
        QMessageBox::warning(this, "BŁĄD!", "Nie dziel przez 0! :)");
    }
    catch(...)
    {
        QMessageBox::warning(this, "UPSSSSSS!", "Coś poszło nie tak! :( \nUpewnij się, że wszystko dobrze wprowadzasz! :)");

    }
}
