# CyberDash数据结构开源代码  
## 1 简介
### 1.1 配套书籍
清华大学出版社《数据结构(用面向对象方法与C++语言描述)(第2版)》(殷人昆主编)

![image.png](https://gitee.com/L_Dash/cloud-images/raw/master/img/datastructure.jpg)

**需要强调的是**  
本项目代码并不是将书中代码抄写下来, 而是进行了大量的调整, 涉及代码规范, 解决Bug,
增加边界条件等大量优化. 完成代码的过程中经过了反复地讨论, 力争在教科书的基础上, 
提高代码的规范性健壮性.

### 1.2 代码运行环境  
目前在Linux和Mac环境已经测试通过。

**Linux测试环境**

    kernel >= 3.10
    cmake：3.13
    doxygen: 1.9.2
**Mac测试环境**

    MAC OS BigSur（11.2.1）
    cmake：3.13
    doxygen: 1.9.2


### 1.3 代码规范与风格
**代码规范**  
Google编码规范，参考文档连接:  
https://github.com/zh-google-styleguide/zh-google-styleguide/tree/master/google-cpp-styleguide

**使用STL**  
部分代码(例如图)(大量)使用STL, 参考文档或者<C++ Primer>

**C++特性**  
考虑很多读者是学生和初学者, 使用C++98

## 2 使用方式
为了方便分类学习, 项目主目录下, 每个目录对应一个独立的项目
### 2.1 编译与运行
    git clone https://gitee.com/cyberdash/data-structure-cpp.git
    # 进入目录
    cd data-structure-cpp/<dir>
    # 编译
    cmake3 .
    make
    # 执行程序
    ./main


## 3 内容简介
**Array: 稀疏矩阵**  

**GeneralizedList: 广义表**  

**Graph: 图**  
矩阵图, 邻接表图, 深度优先, 广度优先, 连通分量, 最小生成树, 最短路径

**LinearList: 线性表**  
顺序表, 单链表, 双向链表

**Queue: 队列**  

**Search: 搜索**   
二叉搜索树, AVL树

**Sort: 排序**  
冒泡, 插入, 选择, 堆, 归并, 快速

**Stack: 栈**  

**String: 字符串**  
BF, KMP

**Tree: 树**  
二叉树, 二叉线索树, 哈夫曼树

## 4 Doxygen生成文档
### 4.1 Doxygen配置文件
每个代码目录下的cyber_dash_doxygen_config文件为doxygen的配置文件
### 4.2 Doxygen生成文件
可以使用doxygen命令生成每个测试项目的文档
    doxygen cyber_dash_doxygen_config
执行成功之后可以去html目录下打开index.html阅读使用说明

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
我们是拥有十多年开发经验的开发工程师, 长期就职于各传统与互联网大厂.  
目前在做计算机考研相关的内容, 如果想更多了解我们，欢迎关注抖音：cyberdash_yuan

**Y_Dash(元哥)**

用过很多语言, 做过很多项目, 从底层到应用层, 安全/服务/社区/IoT/...  
写代码能剪裁kernel, 吹拉谈唱能去欧洲做展会讲解, 从外太空到内XX, 五花八门什么都略懂一些

**G_Dash(磊哥)**

10多年安全/系统工程师, 专注C/Linux/网络/安全, 某互联网基础架构部资深工程师, 元哥身后稳如磐石的男人

**L_Dash**

资深测试开发工程师, 热爱数据结构和算法

## 6 感谢名单

**感谢下列朋友发现代码bug**

LLcu2019205455@163.com 鲁子傲
1723004698@qq.com 蔡博文

## 7 你好有缘人

