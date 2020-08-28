# math-py-test
  Python embedding demo
  This project shows how to embed python script in c++ program using boost.python library
  以上 是 界面框架来源 readme


# c++调用python子解释器示例
  ## 1.c++通过python.h提供方法调用python代码
    c++ call python
    调用时使用 python 子解释器,为了 隔离(此实例只是示例,本身没有此需求,当多线程 执行 多策略时会有此需求)
  
  ## 2.c++通过boost::python封装c++对象给python代码回调
    c++ call python,python call c++
  
  ## 3.运行中编写 python代码,执行结果 通过 qcustomplot 绘制
    图形输出展示 的 是 c++ 调用 python 函数计算并返回结果.
    python 回调 c++ 方法 没有展示(只是通过 std::cout 输出到 调试环境)
  
![alt text](https://github.com/tagsBag/multi_python_interpreter_call_back/blob/master/%E6%8D%95%E8%8E%B7.PNG "GUI Preview")
