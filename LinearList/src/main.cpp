//
// Created by cyberdash@163.com(: cyberdash_yuan) on 2020/7/15.
//

#include "seq_list_test.h"
#include "singly_linked_list_test.h"
#include "doubly_linked_list_test.h"
#include "circular_singly_linked_list_test.h"
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

    /*
    DoublyLinkedListTest::TestInsert();

    DoublyLinkedListTest::TestRemove();
     */

    CircularSinglyLinkedListTest::TestInsert();

    CircularSinglyLinkedListTest::TestRemove();

    CircularSinglyLinkedListTest::TestClear();

    CircularSinglyLinkedListTest::TestLength();

    CircularSinglyLinkedListTest::TestSearch();

    /*
	CircularDoublyLinkedListTest::TestInsert();

	CircularDoublyLinkedListTest::TestRemove();

	CircularDoublyLinkedListTest::TestLength();

    CircularDoublyLinkedListTest::TestGetNode();

	CircularDoublyLinkedListTest::TestEmpty();

	CircularDoublyLinkedListTest::TestSearch();

	CircularDoublyLinkedListTest::TestGetDataAndSetData();
     */

    /*
	LinkListTest::TestCopyConstructor();

	LinkListTest::TestRemove();

	LinkListTest::TestMakeEmpty();

	LinkListTest::TestLocate();

	LinkListTest::TestGetDataAndSetData();
     */

	return 0;
}