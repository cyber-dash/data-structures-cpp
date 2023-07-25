## 1 环境与代码规范

### 1.1 代码运行环境  
目前在Windows, Linux和Mac环境已经测试通过。

**Linux测试环境**

    kernel >= 3.10
    cmake：3.13
    doxygen: 1.9.2
**Mac测试环境**

    MAC OS BigSur（11.2.1）
    cmake：3.13
    doxygen: 1.9.2


### 1.2 代码规范与风格
**代码规范**  
标准编码规范，参考文档连接:  
https://github.com/zh-google-styleguide/zh-google-styleguide/tree/master/google-cpp-styleguide

**使用STL**  
很多内容使用STL, 参考C++官方文档或者<C++ Primer>

**C++特性**  
考虑很多读者是学生和初学者, 使用C++98为主

## 2 使用方式
为了方便分类, 项目主目录下, 每个目录对应一个独立的项目
### 2.1 构建与运行
    git clone https://gitee.com/cyberdash/data-structure-cpp.git
    # 进入目录
    cd data-structure-cpp/<某数据结构目录>
    # 构建
    cmake3 .
    make
    # 执行程序
    ./main


## 3 Doxygen生成文档
### 3.1 Doxygen配置文件
每个代码目录下的CyberDash_DataStructuresCpp_doxygen_config文件为doxygen的配置文件
### 3.2 Doxygen生成文件
可以使用doxygen命令生成每个测试项目的文档
    doxygen CyberDash_DataStructuresCpp_doxygen_config
执行成功之后可以去html目录下打开index.html阅读使用说明

### 3.3 生成PDF文件
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