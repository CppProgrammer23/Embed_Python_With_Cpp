#include "Python.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(nullptr);
    Py_Initialize();

    //1st method to set pat
    const char* scriptDirectoryName = "the path where the python scripts reside";
    PyObject* sysPath = PySys_GetObject("path");
    PyObject* path = PyUnicode_FromString(scriptDirectoryName);
    PyList_Insert(sysPath, 0, path);
    //2nd method to set path
    //PySys_SetPath(L"the path where the python scripts reside");


}

MainWindow::~MainWindow()
{
    Py_Finalize();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    PyObject* mod = PyImport_ImportModule("func");
    PyObject* pFunc = PyObject_GetAttrString(mod, "mul");
    PyObject* args = Py_BuildValue("(dd)", 2.3,4.1);
    //PyObject* args = PyTuple_Pack(2, 2.3,4.1); //don't use this, it will throw a seg fault
    PyObject* pVal = PyObject_CallObject(pFunc,args);
    double result = PyFloat_AsDouble(pVal);
    ui->label->setNum(result);
}

void MainWindow::on_btnTalk_clicked()
{
    PyObject* mod = PyImport_ImportModule("txtSpe");
    PyObject* pTalk = PyObject_GetAttrString(mod, "talk");
    PyObject* args = Py_BuildValue("(s)", "I\'m listening");
    //PyObject* pVal =
    PyObject_CallObject(pTalk,args);

    PyObject* pGetAudio = PyObject_GetAttrString(mod, "getAudio");
    //PyObject* args = Py_BuildValue("()");

    PyObject* pAudio = PyObject_CallObject(pGetAudio,NULL);
    QString ret = PyBytes_AS_STRING(pAudio);
    ui->talkText->setText(ret);
}

void MainWindow::on_btnQrcode_clicked()
{
    PyObject* mod = PyImport_ImportModule("qrc");
    PyObject* pTalk = PyObject_GetAttrString(mod, "qr");
    PyObject* args = Py_BuildValue("(s)", "https://www.qt.io");
    //PyObject* pVal =
    PyObject_CallObject(pTalk,args);
    QPixmap p;
    p.load("path to a qrcode",nullptr,Qt::AutoColor);// <- path to image file
    ui->labelqrcode->setPixmap(p);
    ui->labelqrcode->setScaledContents(true);
}

void MainWindow::on_btnReset_clicked()
{
    ui->labelqrcode->clear();
    ui->label->clear();
    ui->talkText->clear();
}


