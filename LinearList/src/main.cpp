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

    /*
	SeqListTest::TestSetData();

	SeqListTest::TestSort();

	SeqListTest::TestUnion();

	SeqListTest::TestIntersection();

    DoublyLinkedListTest::TestInsert();

    DoublyLinkedListTest::TestRemove();

    DoublyLinkedListTest::TestSearch();

    DoublyLinkedListTest::TestLength();

    DoublyLinkedListTest::TestClear();

    CircularSinglyLinkedListTest::TestInsert();

    CircularSinglyLinkedListTest::TestRemove();

    CircularSinglyLinkedListTest::TestClear();

    CircularSinglyLinkedListTest::TestLength();

    CircularSinglyLinkedListTest::TestSearch();

	CircularDoublyLinkedListTest::TestInsert();

	CircularDoublyLinkedListTest::TestRemove();

	CircularDoublyLinkedListTest::TestLength();

    CircularDoublyLinkedListTest::TestGetNode();

	CircularDoublyLinkedListTest::TestEmpty();

	CircularDoublyLinkedListTest::TestSearch();

	SinglyLinkListTest::TestCopyConstructor();

	SinglyLinkListTest::TestRemove();

    SinglyLinkListTest::TestClear();

	SinglyLinkListTest::TestLocate();

	SinglyLinkListTest::TestGetDataAndSetData();

    StaticLinkedListTest::TestInsert();

    StaticLinkedListTest::TestSearch();

    StaticLinkedListTest::TestRemove();
	*/

	return 0;
}
