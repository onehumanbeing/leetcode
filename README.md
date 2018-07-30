leetcode 生成文件工具

Usage: python tool.py -p [name] [options]

Options:
    
    -h, --h         查看帮助
    
    -p name         leetcode 题目编号，必须
   
    -a              题目类型为算法
    
    -d              题目类型为数据库
    
    -s              题目类型为Shell
    
    -c              编程语言为C++
    
    -j              编程语言为Java

    -t              统计目前录入的题目数量

Examples:

* python tool.py -p 26 -a -c

运行结果如下

```
algorithm/0026/README.md
algorithm/0026/README.md 创建成功。 2018-07-15
algorithm/0026/res.cpp
algorithm/0026/res.cpp 创建成功。 2018-07-15
finish!
algorithm/0026
algorithm/0026/res.cpp
```