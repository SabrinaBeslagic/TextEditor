#include "findword.h"
#include "ui_findword.h"

findWord::findWord(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::findWord)
{
    ui->setupUi(this);
}

findWord::~findWord()
{
    delete ui;
}
