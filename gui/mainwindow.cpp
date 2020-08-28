#include "mainwindow.h"
#include "dialog.h"
#include <memory>

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),m_dialog(new Dialog(this))
{
    m_strategy = std::make_shared<Strategy>(2);
    setupUi(this);
    f_plot = widget->addGraph();
    df_plot = widget->addGraph();

    f_plot->setPen(QPen(Qt::red,1.0,Qt::SolidLine));
    df_plot->setPen(QPen(Qt::blue,1.0,Qt::DashDotDotLine));

    ///mid 使用 strategy 文本 填充 文本框
    m_dialog->set_script(m_strategy->get_script());
    connect(this->apply_btn,&QPushButton::clicked,[=]
    {
        {   ///mid 编辑后重新获取 文本 并 设置到 strategy,strategy 保存 策略 到文件
            QString fn = m_dialog->get_script();
            m_strategy->set_script(fn.toStdString());
        }

        QVector<double> keys;
        QVector<double> f_values;

        {   ///mid x 轴 范围 和 取值
            //mid 1) 获取 c++ gui 设置的参数
            double xi = xi_sbox->value();                 //mid x轴 左 值域
            double xf = xf_sbox->value();                 //mid x轴 右 值域
            double step = step_sbox->value();             //mid x轴 数据 间距

            double dx = xf-xi;
            int x_step = (int)(dx/step);

            for(int i=0; i<x_step; i++)
            {
                auto x = xi + (i*step);
                keys.push_back(x);
            }
        }

        {   ///mid y 轴 取值
            for(const auto& x : keys)
            {
                f_values.push_back(m_strategy->caculate(x));
            }
        }

        f_plot->setData(keys, f_values);

        widget->xAxis->rescale(true);
        widget->yAxis->rescale(true);
        widget->replot();
    });

    connect(actionDialog,&QAction::triggered,[=](bool checked)
    {
        if(checked && !m_dialog->isVisible())
        {
            m_dialog->show();
        }
        else if(!checked && m_dialog->isVisible())
        {
            m_dialog->close();
        }
    });
    connect(this->m_dialog,&QDialog::finished,[=]
    {
        actionDialog->setChecked(false);
    });
}

MainWindow::~MainWindow()
{
}
