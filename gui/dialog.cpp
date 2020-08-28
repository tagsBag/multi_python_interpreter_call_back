#include "dialog.h"

Dialog::Dialog(QWidget *parent) :QDialog(parent)
{
    setupUi(this);
}

Dialog::~Dialog()
{
}

QString Dialog::get_script()
{
    return fn_textbox->toPlainText();
}

void Dialog::set_script(std::string script)
{
    fn_textbox->setPlainText(script.c_str());
}
