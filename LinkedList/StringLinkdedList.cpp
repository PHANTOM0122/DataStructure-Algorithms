#include "StringLinkedLIst.h"

stringLinkedLIst::stringLinkedLIst() { head = NULL; } // ������
stringLinkedLIst::~stringLinkedLIst() { while (!empty()) removeFront(); } // �Ҹ���
bool stringLinkedLIst::empty() const { return head == NULL; } // �� ����Ʈ?
const string& stringLinkedLIst::front() const { return head->elem; } // ���� ���Ҹ� ��´�

void stringLinkedLIst::addFront(const string& e) {
	stringNode* v = new stringNode;
	v->elem = e;
	v->next = head;
	head = v;
}

void stringLinkedLIst::removeFront() {
	stringNode* old = head; // ���� head ����
	head = old->next; // ���� head �ǳʶڴ�
	delete old; // ���� head ����
}