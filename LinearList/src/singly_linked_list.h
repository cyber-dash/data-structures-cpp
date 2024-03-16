/*!
 * @file singly_linked_list.h
 * @author CyberDash计算机考研, cyberdash@163.com(抖音id:cyberdash_yuan)
 * @brief 单向链表模板类
 * @version 0.2.1
 * @date 2020-06-06
 */

#ifndef CYBER_DASH_LINKED_LIST_H
#define CYBER_DASH_LINKED_LIST_H


#include <iostream>
#include <cstddef>
#include "linear_list.h"


using namespace std;


/*!
 * @brief **单链表结点模板结构体**
 * @tparam TData 数据项类型模板参数
 */
template<typename TData>
struct LinkedNode {
    /*!
     * @brief **构造函数(下一结点地址)**
     * @param node 下一结点(指针)
     */
    explicit LinkedNode(LinkedNode<TData>* node = NULL): next(node) {}

    /*!
     * @brief **构造函数(数据项/下一结点地址)**
     * @param data 数据项数据
     * @param node 下一结点(指针)
     */
    LinkedNode(const TData& data, LinkedNode<TData>* node = NULL): data(data), next(node) {}

    TData data;                 //!< 链表数据项
    LinkedNode<TData>* next;    //!< 下一结点
};


/*!
 * @brief **单链表模板类**
 * @tparam TData 数据项类型模板参数
 * @note
 * 单链表模板类
 * ----------
 * ----------
 *
 * head_指针指向头结点, 头结点只是用于简化操作
 *
 * ----------
 */
template<typename TData>
class SinglyLinkedList: public LinearList<TData> {
public:
    // 默认构造函数
    SinglyLinkedList();
    // 复制构造函数
    SinglyLinkedList(const SinglyLinkedList<TData>& src_linked_list);
    // 析构函数
    ~SinglyLinkedList();
    // 清空链表
    void Clear();
    /*! @brief **链表长度** */
    int Length() const { return this->length_; }
    /*! @brief **获取链表头结点** */
    LinkedNode<TData>* Head() const { return this->head_; }
    // 搜索
    LinkedNode<TData>* Search(TData data) const;
    // 获取结点
    LinkedNode<TData>* GetNode(int pos);
    // 获取结点数据
    bool GetData(int pos, TData& data) const;
    // 设置结点数据
    bool SetData(int pos, const TData& data);
    // 插入(数据)
    bool Insert(int prev_pos, const TData& data);
    // 插入(结点)
    bool Insert(int prev_pos, LinkedNode<TData>* node);
    // 删除(结点)元素
    bool Remove(int target_pos, TData& data);
    // 判断是否为空链表
    bool IsEmpty() const;
    // 打印链表
    void Print();

private:
    LinkedNode<TData>* head_; //!< **链表头结点**
    int length_;              //!< **链表长度**
};


/*!
 * @brief **默认构造函数**
 * @tparam TData 数据项类型模板参数
 * @note
 * 默认构造函数
 * ----------
 * ----------
 * 
 * <span style="color:#FF8100">
 * 我来组成头部:-)
 * </span>
 *
 * ----------
 * head_<b>(头结点)</b>分配内存, length_<b>(长度)</b>设置为0\n
 * **if** head_内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n
 *
 *
 * ----------
 */
template<typename TData>
SinglyLinkedList<TData>::SinglyLinkedList(): length_(0) {
    this->head_ = new LinkedNode<TData>();                                  // head_(头结点)分配内存, length_(长度)设置为0
    if (!this->head_) {                                                     // if head_内存分配失败
        throw bad_alloc();                                                  // 抛出bad_alloc()
    }
}


/*!
 * @brief **复制构造函数**
 * @tparam TData 数据项类型模板参数
 * @param src_linked_list 被复制链表
 * @note
 * 复制构造函数
 * ----------
 * ----------
 *
 * ----------
 * **1 头结点初始化**\n\n
 * head_(头结点)分配内存并初始化\n
 * **if** 内存分配失败 :\n
 * &emsp; 抛出bad_alloc()\n\n
 * **2 初始化指向两个链表各自头结点的遍历指针**\n\n
 * src_list_cur指向源链表头结点\n
 * cur指向自身链表头结点\n\n
 * **3 循环复制结点**\n\n
 * **while** src_list_cur->next不为NULL:\n
 * &emsp; 使用src_list_cur->next的数据项构造新结点, 赋给cur->next指向该新节点(自身链表插入新节点)\n
 * &emsp; cur向后移动1位\n
 * &emsp; src_list_cur向后移动1位\n
 * &emsp; 链表长度加1\n
 * cur->next置为NULL\n
 *
 *
 * ----------
 */
template<typename TData>
SinglyLinkedList<TData>::SinglyLinkedList(const SinglyLinkedList<TData>& src_linked_list): length_(0) {

    // ---------- 1 头结点初始化 ----------

    this->head_ = new LinkedNode<TData>();                                  // head_(头结点)分配内存并初始化
    if (this->head_ == NULL) {                                              // if 内存分配失败
        throw bad_alloc();                                                  // 抛出bad_alloc()
    }

    // ---------- 2 初始化指向两个链表各自头结点的遍历指针 ----------

    LinkedNode<TData>* src_list_cur = src_linked_list.Head();               // src_list_cur指向源链表head_
    LinkedNode<TData>* cur = this->Head();                                  // cur指向自身链表head_

    // ---------- 3 循环复制结点 ----------

    while (src_list_cur->next != NULL) {                                    // while src_list_cur->next不为NULL:

        TData data = src_list_cur->next->data;
        cur->next = new LinkedNode<TData>(data);                            // 使用src_list_cur->next的数据项构造新结点, 赋给cur->next指向该新节点(自身链表插入新节点)

        cur = cur->next;                                                    // cur向后移动1位
        src_list_cur = src_list_cur->next;                                  // src_list_cur向后移动1位

        this->length_++;                                                    // 链表长度加1
    }

    cur->next = NULL;                                                       // cur->next置为NULL
}


/*!
 * @brief **析构函数**
 * @tparam TData 数据项类型模板参数
 * @note
 * 析构函数
 * -------
 * -------
 *
 * -------
 * + **1 清空链表**\n
 * + **2 释放head_指针并置NULL**\n
 *
 *
 * -------
 */
template<typename TData>
SinglyLinkedList<TData>::~SinglyLinkedList() {
    this->Clear();                                                          // 清空链表

    delete this->head_;                                                     // 释放head_指针并置NULL
    this->head_ = NULL;
}


/*!
 * @brief **获取结点数据项**
 * @tparam TData 数据项类型模板参数
 * @param pos 结点位置
 * @param data 数据项保存变量
 * @return 执行结果
 * @note
 * 获取结点数据项
 * -----------
 * -----------
 *
 * -----------
 * **I&nbsp;&nbsp; 非法位置处理**\n\n
 * &emsp; **if** pos < 1 或者 pos > Length():\n
 * &emsp;&emsp; 返回false\n\n
 * **II&nbsp; 遍历至pos位置**\n\n
 * &emsp; 声明指针cur, 指向head_\n
 * &emsp; **while** pos > 0 (遍历pos次):\n
 * &emsp;&emsp; cur指向cur->next\n
 * &emsp;&emsp; pos减1\n\n
 * **III 获取数据项**\n\n
 * cur->data赋给参数data\n
 *
 *
 * -----------
 */
template<typename TData>
bool SinglyLinkedList<TData>::GetData(int pos, TData& data) const {

    // ---------- I 非法位置处理 ----------
    if (pos < 1 || pos > this->Length()) {                                          // if pos < 1 或者 pos > Length():
        return false;                                                               // 返回false
    }

    // ---------- II 遍历至pos位置 ----------
    LinkedNode<TData>* cur = this->head_;                                           // 声明遍历指针cur, 指向head_

    while (pos > 0) {                                                               // while pos > 0 (遍历pos次):
        cur = cur->next;                                                            // cur指向cur->next
        pos--;                                                                      // pos减1
    }

    // ---------- III 获取数据项 ----------
    data = cur->data;                                                               // cur->data赋给参数data

    return true;
}


/*!
 * @brief **设置结点数据项**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据项值
 * @return 执行结果
 * @note
 * 设置结点数据项
 * -----------
 * -----------
 *
 * -----------
 * **I&nbsp;&nbsp; 非法位置处理**\n\n
 * &emsp; **if** pos < 1 或者 pos > Length():\n
 * &emsp;&emsp; 返回false\n\n
 * **II&nbsp; 遍历至pos位置**\n\n
 * &emsp; 声明指针cur, 指向head_\n
 * &emsp; **while** pos > 0 (遍历pos次):\n
 * &emsp;&emsp; cur指向cur->next\n
 * &emsp;&emsp; pos减1\n\n
 * **III 设置数据项**\n\n
 * data赋给cur->data\n
 *
 *
 * -----------
 */
template<typename TData>
bool SinglyLinkedList<TData>::SetData(int pos, const TData& data) {

    // ----- I 非法位置处理 -----
    if (pos < 1 || pos > Length()) {                                                // if pos < 1 或者 pos > Length():
        return false;                                                               // 返回false
    }

    // ----- II 遍历至插入位置 ------
    LinkedNode<TData>* cur = this->head_;                                           // 声明指针cur, 指向head_

    while (pos > 0) {                                                               // while pos > 0 (遍历pos次):
        cur = cur->next;                                                            // cur指向cur->next
        pos--;                                                                      // pos减1
    }

    // ----- III 设置数据项 -----
    cur->data = data;                                                               // data赋给cur->data

    return true;
}


/*!
 * @brief **清空链表**
 * @tparam TData 数据项类型模板参数
 * @note
 * 清空链表
 * -------
 * -------
 *
 * <span style="color:#FF8100">
 * 保留head_结点, 删除其他所有结点
 * </span>
 *
 * -------
 * **while** head_->next存在 :\n
 * &emsp; **I**&nbsp;&nbsp; head_->next指向head_->next->next\n
 * &emsp;&emsp; 声明指针cur, 指向head_->next\n
 * &emsp;&emsp; head_->next指向cur->next\n
 * &emsp; **II**&nbsp; 删除head_->next\n
 * &emsp;&emsp; 释放cur指向的结点\n
 * &emsp; **III** 调整链表长度\n
 * &emsp;&emsp; 链表长度减1\n
 *
 *
 * -------
 */
template<typename TData>
void SinglyLinkedList<TData>::Clear() {

    while (this->head_->next != NULL) {                                                 // while head_->next存在 :

        // ----- I head_->next指向head_->next->next -----

        LinkedNode<TData>* cur = this->head_->next;                                     // 声明指针cur, 指向head_->next
        this->head_->next = cur->next;                                                  // head_->next指向cur->next

        // ----- II 删除head_->next -----

        delete cur;                                                                     // 释放cur指向的结点

        // ----- III 调整链表长度 -----

        this->length_--;                                                                // 链表长度减1
    }
}


/*!
 * @brief **打印链表**
 * @tparam TData 数据项类型模板参数
 * @note
 * 打印链表
 * -------
 * -------
 *
 * -------
 * **I&nbsp;&nbsp; 空链表打印**\n
 * &emsp; **if** head_->next为NULL:\n
 * &emsp;&emsp; 打印"Empty list"\n
 * &emsp;&emsp; return\n
 * **II&nbsp; 非空链表打印**\n
 * &emsp; 声明遍历指针cur, 并初始化指向head_->next\n
 * &emsp; **while** cur不为NULL:\n
 * &emsp;&emsp; 屏幕打印cur指向结点的数据项\n
 * &emsp;&emsp; cur指向下一结点cur->next\n
 *
 *
 * -------
 */
template<typename TData>
void SinglyLinkedList<TData>::Print() {

    // ----- I 空链表打印 -----

    if (this->head_->next == NULL) {                                                    // if head_->next为NULL:
        cout<<"Empty list"<<endl;                                                       // 打印Empty list
        return;
    }

    // ----- II 非空链表打印 -----

    LinkedNode<TData>* cur = Head()->next;                                              // 声明遍历指针cur, 并初始化指向head_->next
    while (cur != NULL) {                                                               // while cur不为NULL:
        cout << cur->data << " ";                                                       // 屏幕打印cur指向结点的数据项
        cur = cur->next;                                                                // cur指向下一结点cur->next
    }

    cout << endl;
}


/*!
 * @brief **插入(数据)**
 * @tparam TData 数据项类型模板参数
 * @param prev_pos 插入位置的前一位置
 * @param data 数据项值
 * @return 执行结果
 * @note
 * 插入(数据)
 * ---------
 * ---------
 *
 * <span style="color:#FF8100">
 * 在位置prev_pos后插入, 作为位prev_pos + 1位置的数据\n
 * prev_pos + 1和其后的数据的所有位置加1\n\n
 * 从1开始, 区别从0开始\n
 * </span>
 *
 * ---------
 * **I&nbsp;&nbsp; 非法位置处理**\n\n
 * &emsp; **if** prev_pos < 0 或者 prev_pos > Length():\n
 * &emsp;&emsp; 返回false\n\n
 * **II&nbsp; 构造插入结点**\n\n
 * &emsp; 使用插入数据初始化结点\n
 * &emsp; **if** 结点为NULL(结点分配内存失败):\n
 * &emsp;&emsp; 返回false\n\n
 * **III 遍历至插入位置**\n\n
 * &emsp; 声明指针cur, 指向head_->next\n
 * &emsp; **while** prev_pos > 0 (遍历prev_pos次):\n
 * &emsp;&emsp; cur指向cur->next\n
 * &emsp;&emsp; prev_pos减1\n\n
 * **IV 执行插入**\n\n
 * &emsp; 待插入结点的next指向cur->next\n
 * &emsp; cur->next指向待插入结点\n
 * &emsp; (此时待插入结点插入到cur后边)\n\n
 * **V&nbsp; 调整链表长度**\n\n
 * &emsp; 链表长度加1\n
 *
 *
 * ---------
 */
template<typename TData>
bool SinglyLinkedList<TData>::Insert(int prev_pos, const TData& data) {

    // ---------- I 非法位置处理 ----------

    if (prev_pos < 0 || prev_pos > Length()) {                                          // if pos < 0 或者 pos > Length():
        return false;                                                                   // 返回false
    }

    // ---------- II 构造插入结点 ----------

    LinkedNode<TData>* node = new LinkedNode<TData>(data);                              // 使用插入数据初始化结点
    if (node == NULL) {                                                                 // if 结点为NULL(结点分配内存失败):
        return false;                                                                   // 返回false
    }

    // ---------- III 遍历至插入位置 ----------

    LinkedNode<TData>* cur = this->head_;                                               // 声明指针cur, 指向head_->next
    while (prev_pos > 0) {                                                              // while pos > 0 (遍历pos次):
        cur = cur->next;                                                                // cur指向cur->next
        prev_pos--;                                                                     // pos减1
    }

    // ---------- IV 执行插入 ----------

    node->next = cur->next;                                                             // 待插入结点的next指向cur->next
    cur->next = node;                                                                   // cur->next指向待插入结点
    // (此时待插入结点插入到cur后边)

    // ---------- V 调整链表长度 ----------

    this->length_++;                                                                    // 链表长度加1

    return true;
}


/*!
 * @brief **插入(结点)**
 * @tparam TData 数据项类型模板参数
 * @param prev_pos 插入位置的前一
 * @param node 结点
 * @return 执行结果
 * @note
 * 插入(结点)
 * ---------
 * ---------
 *
 * <span style="color:#FF8100">
 * 在位置prev_pos后插入, 作为prev_pos + 1位置的结点\n
 * prev_pos + 1和其后的数据的所有位置加1\n\n
 * 从1开始, 区别从0开始\n
 * </span>
 *
 * ---------
 * **I&nbsp;&nbsp; 非法位置处理**\n\n
 * &emsp; **if** prev_pos < 0 或者 prev_pos > Length():\n
 * &emsp;&emsp; 返回false\n\n
 * **II&nbsp; 插入空节点处理**\n\n
 * &emsp; **if** 结点为NULL:\n
 * &emsp;&emsp; 返回false\n\n
 * **III 遍历至插入位置**\n\n
 * &emsp; 声明指针cur, 指向head_->next\n
 * &emsp; **while** prev_pos > 0 (遍历prev_pos次):\n
 * &emsp;&emsp; cur指向cur->next\n
 * &emsp;&emsp; prev_pos减1\n\n
 * **IV 执行插入**\n\n
 * &emsp; 待插入结点的next指向cur->next\n
 * &emsp; cur->next指向待插入结点\n
 * &emsp; (此时待插入结点插入到cur后边)\n\n
 * **V&nbsp; 调整链表长度**\n\n
 * &emsp; 链表长度加1\n
 *
 *
 * ---------
 */
template<typename TData>
bool SinglyLinkedList<TData>::Insert(int prev_pos, LinkedNode<TData>* node) {

    // ---------- I 非法位置处理 ----------

    if (prev_pos < 0 || prev_pos > this->Length()) {                                    // if pos < 0 或者 pos > Length():
        return false;                                                                   // 返回false
    }

    // ---------- II 插入空结点处理 ----------

    if (node == NULL) {                                                                 // if 结点为NULL:
        return false;                                                                   // 返回false
    }

    // ---------- III 遍历至插入位置 ----------

    LinkedNode<TData>* cur = this->head_;                                               // 声明指针cur, 指向head_->next
    while (prev_pos > 0) {                                                              // while pos > 0 (遍历pos次):
        cur = cur->next;                                                                // cur指向cur->next
        prev_pos--;                                                                     // pos减1
    }

    // ---------- IV 执行插入 ----------

    node->next = cur->next;                                                             // 待插入结点的next指向cur->next
    cur->next = node;                                                                   // cur->next指向待插入结点
    // (此时待插入结点插入到cur后边)

    // ---------- V 调整链表长度 ----------

    this->length_++;                                                                    // 链表长度加1

    return true;
}


/*!
 * @brief **判断是否为空链表**
 * @tparam TData 数据项类型模板参数
 * @return 结果
 * @note
 * 判断是否为空链表
 * -----------
 * -----------
 *
 * <span style="color:#FF8100">
 * It's a long road, when you face the world alone
 * </span>
 *
 * -----------
 * **if** head_->next为NULL:\n
 * &emsp; 则为空链表\n
 * **else**\n
 * &emsp; 不是空链表\n
 *
 *
 * -----------
 */
template<typename TData>
bool SinglyLinkedList<TData>::IsEmpty() const {
    if (this->Head()->next == NULL) {
        return true;
    } else {
        return false;
    }
}


/*!
 * @brief **搜索**
 * @tparam TData 数据项类型模板参数
 * @param data 搜索数据
 * @return 搜索结果
 * @note
 * 搜索
 * --------------------
 * --------------------
 *
 * <span style="color:#FF8100">
 * 时间复杂度O(n)
 * </span>
 *
 * --------------------
 * **I&nbsp;&nbsp; 初始化遍历指针**\n\n
 * &emsp; 声明遍历指针cur, 并初始化指向head_->next\n
 * &emsp; **if** cur为NULL:\n
 * &emsp;&emsp; 返回NULL\n\n
 * **II&nbsp; 遍历链表进行搜索**\n\n
 * &emsp; **while** cur不为NULL:\n
 * &emsp;&emsp; **if** cur->data等于搜索数据项:\n
 * &emsp;&emsp;&emsp; 搜索到相应数据, 跳出循环\n
 * &emsp;&emsp; cur指向cur->next\n\n
 * **III 返回搜索结果**\n\n
 * &emsp; 返回cur\n
 *
 *
 * --------------------
 */
template<typename TData>
LinkedNode<TData>* SinglyLinkedList<TData>::Search(TData data) const {

    // ---------- I 初始化遍历指针 ----------

    LinkedNode<TData>* cur = this->head_->next;                                         // 声明遍历指针cur, 并初始化指向head_->next
    if (cur == NULL) {                                                                  // if cur为NULL:
        return NULL;                                                                    // 返回NULL
    }

    // ---------- II 遍历链表进行搜索 ----------

    while (cur != NULL) {                                                               // while cur不为NULL:
        if (cur->data == data) {                                                        // if cur->data等于搜索数据项:
            break;                                                                      // 搜索到相应数据, 跳出循环
        }

        cur = cur->next;                                                                // cur指向cur->next
    }

    // ---------- III 返回搜索结果 ----------

    return cur;                                                                         // 返回cur
}


/*!
 * @brief **获取结点**
 * @tparam TData 数据项类型模板结点
 * @param pos 位置
 * @return 结点
 * @note
 * 获取结点
 * -------
 * -------
 *
 * <span style="color:#FF8100">
 * 时间复杂度O(n)
 * </span>
 *
 * -------
 * **I&nbsp;&nbsp; 非法位置处理**\n\n
 * &emsp; **if** pos < 1 或者 pos > Length():\n
 * &emsp;&emsp; 返回NULL(范围[1, Length()])\n\n
 * **II&nbsp; 遍历至pos位置的结点**\n\n
 * &emsp; 声明遍历指针cur, 并初始化指向Head()\n
 * &emsp; **for loop** 循环pos次:\n
 * &emsp;&emsp; cur指向cur->next\n\n
 * **III 返回结果**\n\n
 * &emsp; 返回cur\n
 *
 *
 * -------
 */
template<typename TData>
LinkedNode<TData>* SinglyLinkedList<TData>::GetNode(int pos) {

    // ---------- I 非法位置处理 ----------

    if (pos < 1 || pos > this->Length()) {                                              // if pos < 1 或者 pos > Length():
        return NULL;                                                                    // 返回NULL(范围[1, Length()])
    }

    // ---------- II 遍历至pos位置的结点 ----------

    LinkedNode<TData>* cur = this->Head();                                              // 声明遍历指针cur, 并初始化指向Head()
    for (int i = 1; i <= pos; i++) {                                                    // for loop 循环pos次:
        cur = cur->next;                                                                // cur指向cur->next
    }

    // ---------- III 返回结果 ----------

    return cur;                                                                         // 返回cur
}


/*!
 * @brief **删除(结点)元素**
 * @tparam TData 数据项类型模板参数
 * @param pos 位置
 * @param data 数据保存变量
 * @return 执行结果
 * @note
 * 删除(结点)元素
 * -------
 * -------
 *
 * 删除位置pos的结点, 该结点数据保存在参数data
 *
 * -------
 * **I&nbsp;&nbsp; 非法条件处理**\n\n
 * &emsp; **if** 空链表 或者 pos < 1 或者 pos > Length():\n
 * &emsp;&emsp; 返回false\n\n
 * **II&nbsp; 遍历至pos位置的前驱结点(pos - 1位置)**\n\n
 * &emsp; 声明遍历指针cur, 并初始化指向Head()\n
 * &emsp; **for loop** 循环pos - 1次:\n
 * &emsp;&emsp; cur指向cur->next\n\n
 * **III 执行删除**\n\n
 * &emsp; 声明指针temp, 指向pos位置的待删除结点cur->next\n
 * &emsp; 待删除结点的前驱cur, 将其next指向待删除结点的后继\n
 * &emsp; 待删除结点的数据项保存到参数data\n
 * &emsp; 删除待删除结点\n\n
 * **IV 调整链表长度**\n\n
 * &emsp; 链表长度减1\n
 *
 *
 * -------
 */
template<typename TData>
bool SinglyLinkedList<TData>::Remove(int target_pos, TData& data) {

    // ---------- I 非法条件处理 ----------

    if (this->Length() == 0 || target_pos < 1 || target_pos > this->Length()) {         // if 空链表 或者 pos < 1 或者 pos > Length():
        return false;                                                                   // 返回false
    }

    // ---------- II 遍历至pos位置的前驱结点(pos - 1位置) ----------

    LinkedNode<TData>* cur = this->head_;                                               // 声明遍历指针cur, 并初始化指向Head()
    for (int i = 1; i < target_pos; i++) {                                              // for loop 循环pos - 1次:
        cur = cur->next;                                                                // cur指向cur->next
    }

    // ---------- III 执行删除 ----------

    LinkedNode<TData>* temp = cur->next;                                                // 声明指针temp, 指向pos位置的待删除结点cur->next
    cur->next = temp->next;                                                             // 待删除结点的前驱cur, 将其next指向待删除结点的后继

    data = temp->data;                                                                  // 待删除结点的数据项保存到参数data

    delete temp;                                                                        // 删除待删除结点
    temp = NULL;

    // ---------- IV 调整链表长度 ----------

    this->length_--;                                                                    // 链表长度减1

    return true;
}


#endif // CYBER_DASH_LINKED_LIST_H
