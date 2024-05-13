#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFileDialog>
#include "findword.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Dodavanje centralnog widgeta
    this->setCentralWidget(ui->textEdit);

 }

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionNew_triggered()
{
    // New file
    nazivDatoteke ="";
    ui->textEdit->setPlainText("");

}

void MainWindow::on_actionOpen_triggered()
{
    // Open file
    QString datoteka = QFileDialog::getOpenFileName(this,"Otvorite datoteku");
    if(!datoteka.isEmpty()){
        QFile radnaDatoteka(datoteka);
        if(radnaDatoteka.open(QFile::ReadOnly | QFile::Text)){
            nazivDatoteke = datoteka;
            QTextStream upis(&radnaDatoteka);
            QString tekst = upis.readAll();
            radnaDatoteka.close();
            ui->textEdit->setPlainText(tekst);
        }
    }

}

void MainWindow::on_actionSave_triggered()
{
    //Save file
    QFile radnaDatoteka(nazivDatoteke);
    if(radnaDatoteka.open(QFile::WriteOnly | QFile::Text)){
        QTextStream ispis(&radnaDatoteka);
        ispis<<ui->textEdit->toPlainText();
        radnaDatoteka.flush();
        radnaDatoteka.close();
    }

}

void MainWindow::on_actionSave_As_triggered()
{
    //Save as file
    QString datoteka = QFileDialog::getSaveFileName(this,"Sacuvaj datoteku");
    if(!datoteka.isEmpty()){
        nazivDatoteke = datoteka;
        on_actionSave_triggered();

    }

}

void MainWindow::on_actionCut_triggered()
{
    // Cut tekst
    ui->textEdit->cut();

}

void MainWindow::on_actionCopy_triggered()
{
    //Copy tekst
    ui->textEdit->copy();

}

void MainWindow::on_actionPaste_triggered()
{
    //Paste tekst
    ui->textEdit->paste();

}

void MainWindow::on_actionUndo_triggered()
{
    //Undo
    ui->textEdit->undo();

}

void MainWindow::on_actionRedo_triggered()
{
    //Redo
    ui->textEdit->redo();


}

void MainWindow::on_actionBold_triggered()
{
    //Bold text
    // Get the current text format
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->textEdit->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);

    // Apply the formatting to the selected text
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.mergeCharFormat(fmt);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actionItalic_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();

    // Check if the selected text is already italicized
    bool isItalic = cursor.charFormat().fontItalic();

    // Create a text format object
    QTextCharFormat fmt;
    fmt.setFontItalic(!isItalic);  // Toggle the italic state

    // Apply the formatting to the selected text
    cursor.mergeCharFormat(fmt);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actionUnderline_triggered()
{
    QTextCursor cursor = ui->textEdit->textCursor();

    // Check if the selected text is already underlined
    bool isUnderlined = cursor.charFormat().fontUnderline();

    // Create a text format object
    QTextCharFormat fmt;
    fmt.setFontUnderline(!isUnderlined);  // Toggle the underline state

    // Apply the formatting to the selected text
    cursor.mergeCharFormat(fmt);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}






