#include "DoubleLinkedList.h"

DLinkedList::DLinkedList()
{
	header = new NodeType; // ��� �տ� ���ο� ��� ����
	trailer = new NodeType; // Ʈ���� �ڿ� ���ο� ��� ����
	header->next = trailer; // ���θ� point!
	trailer->prev = header;
}

DLinkedList::~DLinkedList()
{
	while (!empty()) {removeFront();}
	delete header;
	delete trailer;
}

bool DLinkedList::empty() const
{
	return (header->next == trailer);
}

const Elem& DLinkedList::front() const
{
	return header->next->info;
}

const Elem& DLinkedList::back() const
{
	return trailer->prev->info;
}

void DLinkedList::addFront(const Elem& e)
{
	add(header->next, e); // list�ڿ��� �߰�
}

void DLinkedList::addBack(const Elem& e)
{
	add(trailer, e); // list�ڿ��� �߰�
}

void DLinkedList::removeFront()
{
	remove(header->next); // �տ��� ����
}

void DLinkedList::removeBack()
{
	remove(trailer->prev); // �ڿ��� ����
}

void DLinkedList::add(NodeType* v, const Elem& e)
{
	NodeType* NewNode = new NodeType; // e�� ���� ���ο� node ����
	NewNode->info = e;
	NewNode->next = v;
	NewNode->prev = v->prev;
	v->prev->next = v->prev = NewNode;
}

void DLinkedList::remove(NodeType* v)
{
	NodeType* NewNode1 = v->prev; // ������
	NodeType* NewNode2 = v->next; // �ļ���
	NewNode1->next = NewNode2;
	NewNode2->prev = NewNode1;
}

const Elem& DLinkedList::back() const
{
	// TODO: ���⿡ return ���� �����մϴ�.
}
