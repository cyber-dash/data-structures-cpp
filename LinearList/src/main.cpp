//
// Created by cyberdash@163.com(: cyberdash_yuan) on 2020/7/15.
//

#include "linked_list_test.h"
#include "seq_list_test.h"
#include "doubly_linked_list_test.h"


using namespace std;


int main() {

	SeqListTest::TestInsert();

	SeqListTest::TestSize();

	SeqListTest::TestEmpty();

	SeqListTest::TestLength();

	SeqListTest::TestSearch();

	SeqListTest::TestLocate();

	SeqListTest::TestGetData();

	SeqListTest::TestSetData();

	SeqListTest::TestSort();

	SeqListTest::TestUnion();

	SeqListTest::TestIntersection();

	DoublyLinkedListTest::TestInsertByDirection();

	DoublyLinkedListTest::TestRemoveByDirection();

	DoublyLinkedListTest::TestLength();

	DoublyLinkedListTest::TestLocate();

	DoublyLinkedListTest::TestEmpty();

	DoublyLinkedListTest::TestSearch();

	DoublyLinkedListTest::TestGetDataAndSetData();


	LinkListTest::TestCopyConstructor();

	LinkListTest::TestRemove();

	LinkListTest::TestMakeEmpty();

	LinkListTest::TestLocate();

	LinkListTest::TestGetDataAndSetData();

	return 0;
}