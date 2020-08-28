QT += core gui
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = multi_python_interpreter_call_back #mid 指定可执行程序的名称

CONFIG += c++11
DEFINES += QT_DEPRECATED_WARNINGS

win32{#mid {要紧随其后,否则无效,1)解决界面中文乱码问题.2)解决源码文件 utf-8 编码加载问题
        QMAKE_CXXFLAGS += /utf-8
}

####################################################################################################
#mid boost_python 和 python 库说明
#mid 1) 编译器匹配
#mid boost_python,python,当前开发环境所使用的 msvc 需要版本一致
#mid 比如当前开发环境为 vs2017(14.1) ,msvc 15.9.16,所以,boost_python 和 python 都需要选对应版本 msvc 编译的
#mid 2) python 版本匹配
#mid boost_python 和 python 的版本需要匹配
#mid 比如 boost_python 如果为 3.8,则 python 的版本必须为 3.8
#mid 3) dll 说明
#mid 编译后,运行前,必须要将对应依赖的 python dll 拷贝到目标编译目标目录下,否则闪退
####################################################################################################

INCLUDEPATH += D:/boost_1_73_0_14_1_64
INCLUDEPATH += D:/mid/Python380b3/include
INCLUDEPATH += 3rdparty/
INCLUDEPATH += gui/

LIBS += -LD:/mid/Python380b3/libs
LIBS += -lpython38

LIBS += -LD:/boost_1_73_0_14_1_64/lib64-msvc-14.1
LIBS += -lboost_python38-vc141-mt-gd-x64-1_73


CONFIG(debug,debug|release){#mid 此处的相对位置为构建目标目录的相对位置
    DESTDIR = debug
    PYTHON_DLL_FILE = D:/mid/Python380b3/python38.dll
    BOOST_PYTHON_DLL_FILE = D:/boost_1_73_0_14_1_64/lib64-msvc-14.1/boost_python38-vc141-mt-gd-x64-1_73.dll
} else {
    DESTDIR = release
    PYTHON_DLL_FILE = D:/mid/Python380b3/python38.dll
    BOOST_PYTHON_DLL_FILE = D:/boost_1_73_0_14_1_64/lib64-msvc-14.1/boost_python38-vc141-mt-gd-x64-1_73.dll
}
OBJECTS_DIR = obj
MOC_DIR = moc
RCC_DIR = rc
UI_DIR = ui

win32{
    #mid 经测试 win 下拷贝有几个要求
    #mid 1) 文件路径必须没有空格
    #mid 2) 将/替换为\\才能正确识别路径(qt使用 /)
    #mid 3) 也有可能是目标文件夹没有权限
    message("当前系统:win,复制 python38")
    DIR1 =  $$PYTHON_DLL_FILE                               #mid 需要用通配符,因为 QMAKE_POST_LINK += xcopy $$DIR11 $$DIR21 /i /y 只能出现一次,两个文件分别 xcopy 会失败
    DIR2  = $$DESTDIR/                                      #mid 拷贝到程序运行目录
    DIR11 = $$replace(DIR1, /, \\)                          #mid replace函数的第一个参数必须是大写
    DIR21 = $$replace(DIR2, /, \\)

    message($$DIR11)
    message("to========")
    message($$DIR21)
    QMAKE_POST_LINK += xcopy $$DIR11 $$DIR21 /i /y
}

#typedef struct{
#    const char* name;
#    int basicsize;
#    int itemsize;
#    unsigned int flags;
##undef slots
#    PyType_Slot *slots; /* terminated by slot==0. */
##define slots Q_SLOTS
#} PyType_Spec;

HEADERS += \
    3rdparty/qcustomplot.h \
    gui/dialog.h \
    gui/mainwindow.h \
    interpreters_manager/interpreters_manager.h \
    strategy/context.h \
    strategy/strategy.h

SOURCES += \
    interpreters_manager/interpreters_manager.cpp \
    main.cpp \
    3rdparty/qcustomplot.cpp \
    gui/dialog.cpp \
    gui/mainwindow.cpp \
    strategy/context.cpp \
    strategy/strategy.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    strategy_scripts/strategy.py

