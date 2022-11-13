//
// Created by cyberdash@163.com(: cyberdash_yuan) on 2020/7/15.
//

#include "singly_linked_list_test.h"
#include "seq_list_test.h"
#include "circular_doubly_linked_list_test.h"


using namespace std;


int main() {

    /*
	SeqListTest::TestInsert();

	SeqListTest::TestSize();

	SeqListTest::TestEmpty();

	SeqListTest::TestLength();

	SeqListTest::TestSearch();

	SeqListTest::TestGetNode();

	SeqListTest::TestGetData();

	SeqListTest::TestSetData();

	SeqListTest::TestSort();

	SeqListTest::TestUnion();

	SeqListTest::TestIntersection();
     */

	DoublyLinkedListTest::TestInsertByDirection();

	DoublyLinkedListTest::TestRemoveByDirection();

	DoublyLinkedListTest::TestLength();

    DoublyLinkedListTest::TestGetNode();

	DoublyLinkedListTest::TestEmpty();

	DoublyLinkedListTest::TestSearch();

	DoublyLinkedListTest::TestGetDataAndSetData();


    /*
	LinkListTest::TestCopyConstructor();

	LinkListTest::TestRemove();

	LinkListTest::TestMakeEmpty();

	LinkListTest::TestLocate();

	LinkListTest::TestGetDataAndSetData();
     */

	return 0;
}