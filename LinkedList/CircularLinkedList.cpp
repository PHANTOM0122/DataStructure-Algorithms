#include "CircularLinkedList.h"
#pragma once
CircleList::CircleList()
{
	cursor = nullptr;
}

CircleList::~CircleList()
{
	while (!empty()) {
		remove(); // �Ҹ���
	}
}

bool CircleList::empty() const
{
	return (cursor == NULL);
}

const Elem& CircleList::front() const
{
	return cursor->next->info;
}

const Elem& CircleList::back() const
{
	return cursor->info;
}

void CircleList::advance()
{
	cursor = cursor->next;
}

void CircleList::add(const Elem& e) // Ŀ���� ������ �߰�
{
	NodeType* tempPtr = new NodeType;
	tempPtr->info = e;
	if (cursor == NULL) { // �� ����Ʈ�� ���
		tempPtr->next = tempPtr; // �ڱ� �ڽ��� point
		cursor = tempPtr; // Ŀ���� tempPtr�� point
	}
	else { // �� ����Ʈ�� �ƴ� ���
		tempPtr->next = cursor->next; // tempPtr�� cursor ���� ���ҿ� ����
		cursor->next = tempPtr;
	}
}

void CircleList::remove() // cursor�� ���� node ����!
{
	NodeType* old = cursor->next; // cursor�� ���� ���� point
	if (old == cursor) { // ����Ʈ�� ���Ұ� �ڱ� �ڽŹۿ� ���� ���
		cursor = nullptr; // ����Ʈ�� ����Ű�� cursor�� ����
	}
	else {
		cursor->next = old->next; // cursor�� ������ ���� ���� ���Ҹ� point
	}
	delete old; // ���� ����
}
