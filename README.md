﻿# CyberDash数据结构开源代码
## 1 简介
### 1.1 配套书籍
清华大学出版社《数据结构(用面向对象方法与C++语言描述)(第2版)》(殷人昆主编)  

**需要强调的是**  
本项目代码并不是将书中代码抄写下来, 而是进行了大量的调整, 涉及代码规范, 解决Bug,
增加边界条件等大量优化. 完成代码的过程中经过了反复地讨论, 力争在教科书的基础上, 
提高代码的规范性健壮性.

希望还在上学的同学, 通过这份代码, 不仅仅学好《数据结构》这门课程, 同时培养软件工程,
程序设计等实战能力, 与校园外真实的社会工作要求接轨.

希望各位, 尽早尽快完成学生到专业人士的转变  
希望各位, 多给我们提建议, 使这套代码更加完善  

### 1.2 代码运行环境
目前在Linux和Mac环境已经测试通过。

**Linux测试环境**

    kernel >= 3.10
    cmake版本：3.13
**Mac测试环境**

    MAC OS BigSur（11.2.1）
    cmake版本：3.13


### 1.3 升级与优化
**编程规范**

https://github.com/zh-google-styleguide/zh-google-styleguide/tree/master/google-cpp-styleguide

**使用STL**

**函数设计与封装**

**C++特性**

**代码风格**


## 2 使用方式
为了方便分类学习, 项目主目录下, 每个目录对应一个独立的项目
### 2.1 编译与运行
    # 进入目录
    cd <dir>
    # 编译
    cmake3 .
    make
    # 执行程序
    ./main
### 2.2 使用CMake
### 2.3 复制代码文件

## 3 内容简介
**generalizedList**: 广义表

**graph**: 图

**link**: 链表

**pointer**: 指针(用于新手熟悉)

**queue**: 队列

**search**: 搜索

**seqList**: 线性表

**sort**: 排序

**stack**: 栈

**string**: 字符串

**tree**: 树

## 4 Doxygen生成文档
### 4.1 Doxygen配置文件
### 4.2 Doxygen生成文件
### 4.3 生成PDF文件
doxygen配置文件将GENERATE_LATEX/LATEX_OUTPUT/USE_PDFLATEX/PDF_HYPERLINKS设置为YES

打开latex目录中的refman.tex,  
找到"\begin{document}"这一行, 改为
```
\usepackage{CJKutf8}
\begin{document}
\begin{CJK}{UTF8}{gbsn}
```
找到"\end{document}"这一行, 改为
```
\end{CJK}
\end{document}
```


## 5 关于我们
我们是拥有十多年开发经验的开发工程师，长期就职于各传统与互联网大厂，目前在做数据结构与算法讲解教学，如果想更多了解我们，欢迎关注抖音：cyberdash_yuan

**Y_Dash(元哥)**

用过很多语言, 做过很多项目, 从底层到应用层, 安全/服务/社区/IoT太多了.
写代码能剪裁kernel, 吹拉谈唱能去欧洲做展会讲解, 五花八门什么都略懂一些

**G_Dash(磊哥)**

写了快10年C语言, 专注底层开发, 计算机网络/操作系统/安全/C语言资深程序员, 元哥身后稳如磐石的男人

**L_Dash**

北邮在读研究生, 资深测试开发工程师
