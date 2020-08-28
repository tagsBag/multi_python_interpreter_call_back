#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "strategy.h"
#include "context.h"

Strategy::Strategy(double x) : m_x(x)
{
    m_interpreter_state = m_interpreter.interpreter_state();    ///mid 用 策略 特有 解释器 执行
    m_interpreter_state = PyThreadState_Get()->interp;          ///mid 用当前 解释器 执行

    m_file_name = "C:/Users/admin/Desktop/uploaded_to_github.com/multi_python_interpreter_call_back/strategy_scripts/strategy.py";
    m_script = read_file(m_file_name);

    m_context = std::make_shared<Context>(this);
}


double Strategy::caculate(double x)
{   ///mid 将 x 参数传递给 python,python计算后将结果保存在 y 中
    m_x = x;

    ReleaseGIL t;                                           ///mid 1) 释放 当前占用 GIL 的 线程
    BindThreadWithInterpreter scope(m_interpreter_state);   ///mid 2) 当前 线程 占用 GIL

    try
    {
        {   ///mid 执行 文本 python,传入 参数 字典 namespace_


            boost::python::exec(m_script.c_str(),m_main_namespace);     ///mid 此语句 执行时,会将 m_main_namespace 中的数据 传入 python 文件执行环境,同时将 python 文件 的执行数据 存入 m_main_namespace
            //boost::python::object rand = boost::python::eval("sin(3)", m_main_namespace);    ///mid python 文件 若 定义 有 _add(a,b)函数,则此处调用成功
            //std::cout <<"**************"<< boost::python::extract<double>(rand) << std::endl;
        }
    }
    catch(boost::python::error_already_set& e)
    {
        PyErr_PrintEx(0);
    }
    return m_y;
}

std::string Strategy::read_file(const std::string& file_path)
{
    std::stringstream output;
    std::ifstream file;
    file.open(file_path.c_str());
    std::string line;
    while(std::getline(file,line))
    {
        output << line << std::endl;
    }
    return output.str();
}

void Strategy::save_file(const std::string& file_path,std::string script)
{
    QFile file(file_path.c_str());
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out<<script.c_str();
        file.close();
    }
}

void Strategy::set_script(std::string script)
{   ///mid 设置 被编辑后的 python 程序
    m_script = script;
    save_file(m_file_name,m_script);
}

std::string Strategy::get_script()
{
    return m_script;
}
