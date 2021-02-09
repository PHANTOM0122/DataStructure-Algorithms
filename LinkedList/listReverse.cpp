#include "DoubleLinkedList.h"
#include <iostream>

using namespace std;

void listReverse(DLinkedList& L) {
	DLinkedList T; // temp list ����
	while (!L.empty()) {
		string s = L.front();
		L.removeFront();
		T.addFront(s); // L�� T�� �ӽ� ����
	}
	while (!T.empty()) {
		string s = T.front();
		T.removeFront(); // �ٽ� T�� L�� ����!
		L.addBack(s);
	}
}
