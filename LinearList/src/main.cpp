//
// Created by cyberdash@163.com(: cyberdash_yuan) on 2020/7/15.
//

#include "seq_list_test.h"
#include "singly_linked_list_test.h"
#include "doubly_linked_list_test.h"
#include "circular_singly_linked_list_test.h"
#include "circular_doubly_linked_list_test.h"
#include "static_linked_list_test.h"


using namespace std;


/*!
 * @brief **main函数**
 * @return 0
 * @note
 * main函数
 * -------
 * -------
 *
 * -------
 * 测试-顺序表-插入\n
 * 测试-顺序表-复制构造\n
 * 测试-顺序表-容量\n
 * 测试-顺序表-Empty\n
 *
 *
 * -------
 */
int main() {

    /*
     */
    // 测试-顺序表-插入
	SeqListTest::TestInsert();

    // 测试-顺序表-复制构造
    SeqListTest::TestCopyConstructor();

    // 测试-顺序表-容量
    SeqListTest::TestCapacity();

    // 测试-顺序表-Empty
	SeqListTest::TestEmpty();

    // 测试-顺序表-长度
	SeqListTest::TestLength();

    // 测试-顺序表-查找
	SeqListTest::TestSearch();

    // 测试-顺序表-获取结点数据
	SeqListTest::TestGetData();

    // 测试-顺序表-设置结点数据
	SeqListTest::TestSetData();

    // 测试-顺序表-排序
	SeqListTest::TestSort();

    // 测试-顺序表-合并
	SeqListTest::TestUnion();

    // 测试-顺序表-交集
	SeqListTest::TestIntersection();

    // 测试-顺序表-删除
    SeqListTest::TestRemove();

    // 测试-双向链表-插入
    DoublyLinkedListTest::TestInsert();

    // 测试-双向链表-删除结点
    DoublyLinkedListTest::TestRemove();

    // 测试-双向链表-搜索
    DoublyLinkedListTest::TestSearch();

    // 测试-双向链表-长度
    DoublyLinkedListTest::TestLength();

    // 测试-双向链表-清空
    DoublyLinkedListTest::TestClear();

    // 测试-循环单链表-插入
    CircularSinglyLinkedListTest::TestInsert();

    // 测试-循环单链表-删除结点
    CircularSinglyLinkedListTest::TestRemove();

    // 测试-循环单链表-清空
    CircularSinglyLinkedListTest::TestClear();

    // 测试-循环单链表-长度
    CircularSinglyLinkedListTest::TestLength();

    // 测试-循环单链表-搜索
    CircularSinglyLinkedListTest::TestSearch();

    // 测试-循环双向链表-按方向插入
	CircularDoublyLinkedListTest::TestInsert();

    // 测试-循环双向链表-按方向删除
	CircularDoublyLinkedListTest::TestRemove();

    // 测试-循环双向链表-长度
	CircularDoublyLinkedListTest::TestLength();

    // 测试-双向循环链表-获取结点
    CircularDoublyLinkedListTest::TestGetNode();

    // 测试-循环双向链表-是否为空
	CircularDoublyLinkedListTest::TestEmpty();

    // 测试-循环双向链表-搜索
	CircularDoublyLinkedListTest::TestSearch();

    // 测试-单向链表-复制构造
	SinglyLinkListTest::TestCopyConstructor();

    // 测试-单向链表-删除结点
	SinglyLinkListTest::TestRemove();

    // 测试-单向链表-清空
    SinglyLinkListTest::TestClear();

    // 测试-单向链表-获取结点
    SinglyLinkListTest::TestGetNode();

    // 测试-单向链表-设置和获取数据
	SinglyLinkListTest::TestGetDataAndSetData();

    // 测试-静态链表-插入
    StaticLinkedListTest::TestInsert();

    // 测试-静态链表-搜索
    StaticLinkedListTest::TestSearch();

    // 测试-静态链表-删除
    StaticLinkedListTest::TestRemove();
    /*
	*/

	return 0;
}
