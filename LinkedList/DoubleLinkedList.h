#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <string>

using namespace std;

typedef std::string Elem;
struct NodeType{
	Elem info;
	NodeType* prev;
	NodeType* next;
};

class DLinkedList {
public:
	DLinkedList();
	~DLinkedList();
	bool empty()const;
	const Elem& front() const;
	const Elem& back() const;
	void addFront(const Elem& e);
	void addBack(const Elem& e);
	void removeFront();
	void removeBack();
private:
	NodeType* header;
	NodeType* trailer;
protected:
	void add(NodeType* v, const Elem& e); // v���� ���ο� node����
	void remove(NodeType* v); // v��� ����
};
#endif DOUBLELINKEDLIST_H
