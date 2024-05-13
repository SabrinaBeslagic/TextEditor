#include "pretraga.h"
#include "ui_pretraga.h"

Pretraga::Pretraga(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Pretraga)
{
    ui->setupUi(this);
}

Pretraga::~Pretraga()
{
    delete ui;
}
