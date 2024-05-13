#ifndef FINDWORD_H
#define FINDWORD_H

#include <QDialog>

namespace Ui {
class findWord;
}

class findWord : public QDialog
{
    Q_OBJECT

public:
    explicit findWord(QWidget *parent = nullptr);
    ~findWord();

private:
    Ui::findWord *ui;
};

#endif // FINDWORD_H
