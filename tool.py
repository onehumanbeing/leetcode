#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Henry

'''
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

Examples:
    python tool.py -p 26 -c
'''

import sys
import getopt
import os
import shutil
import time


BASE_DIR = os.path.dirname(__file__)
TEMPLATES = os.path.join(BASE_DIR, "templates")

def create_file(newfile):
    t = time.strftime('%Y-%m-%d',time.localtime())  #将指定格式的当前时间以字符串输出
    if not os.path.exists(newfile):
        f = open(newfile,'w')
        print newfile
        f.close()
        print(newfile + " 创建成功。 " + t)
    else:
        print(newfile + " 已经存在。 " + t)
    return

def problem_code_validate(item):
    if not item:
        return None
    l = len(item)
    return item if l >= 4 else ("0" * (4-l)) + item

if __name__ == '__main__':
    try:
        opts, argvs = getopt.getopt(sys.argv[1:], 'p:adsh:cj', ['help'])
    except:
        print(__doc__)
        exit()

    problem_type = None
    problem_code = None
    code_type = None

    for opt, argv in opts:
        if opt in ['-h', '--h', '--help']:
            print(__doc__)
            exit()
        elif opt == '-p':
            problem_code = problem_code_validate(argv)
        elif opt == '-a':
            problem_type = "algorithm"
        elif opt == '-d':
            problem_type = "database"
        elif opt == '-s':
            problem_type = "shell"
        elif opt == '-c':
            code_type = "C++"
        elif opt == '-j':
            problem_type = "Java"

    if not (problem_type and problem_code):
        print("缺少参数")
        exit()
    problem_path = os.path.join(BASE_DIR, problem_type, problem_code)
    os.mkdir(problem_path)
    create_file(os.path.join(problem_path, "README.md"))
    res = "res"
    if problem_type == "shell":
        res += ".sh"
    if problem_type == "algorithm":
        if not code_type:
            code_type = "C++"
        if code_type == "C++":
            res += ".cpp"
        if code_type == "Java":
            res += ".java"
    code_path = os.path.join(problem_path, res)
    create_file(code_path)
    if problem_type == "algorithm":
        if code_type == "C++":
            shutil.copyfile(os.path.join(TEMPLATES, "res.cpp"), code_path)
    print("finish!")
    print(problem_path)
    print(code_path)    
    