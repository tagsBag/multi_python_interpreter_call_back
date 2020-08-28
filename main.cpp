#include <QApplication>
#include "mainwindow.h"


#include "interpreters_manager/interpreters_manager.h"


#if PY_MAJOR_VERSION >= 3
#define INIT_MODULE PyInit_strategy     ///mid 对应 BOOST_PYTHON_MODULE(strategy),"strategy"是个后缀,可以任意,但是必须一致
extern "C" PyObject* INIT_MODULE();
#else
#define INIT_MODULE initfunction
extern "C" void INIT_MODULE();
#endif

void init(const std::string& module, PyObject*(*initfunc)())
{
    try
    {
        PyImport_AppendInittab(module.c_str(),initfunc);    ///mid 这个必须有
        Py_Initialize();

        //m_thread_state = Py_NewInterpreter();

        //boost::python::object main_module = boost::python::import("__main__");
        //boost::python::import(module.c_str());              ///mid 这个必须有,否则 按 apply 后奔溃

        //m_main_namespace = boost::python::extract<boost::python::dict>(main_module.attr("__dict__"));


        boost::python::exec("import funddddction00"); //导入os 模块

    }
    catch(boost::python::error_already_set& e)
    {
        PyErr_PrintEx(0);
    }
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ///mid ---------------------------------------------------------------------------------------
    ///mid 以下将 c++运行环境 中 的 模块 导入 到 python 运行环境
    std::string module = "funddddction00";      ///mid 名称任意取
    PyImport_AppendInittab(module.c_str(),INIT_MODULE);    ///mid 这个必须有
    Initializer init;
    boost::python::import(module.c_str());              ///mid 这个必须有,否则 按 apply 后奔溃
    ///mid ---------------------------------------------------------------------------------------

    MainWindow w;

    w.show();

    return app.exec();
}
