#pragma once
#include <iostream>
using namespace std;

typedef int Elem; // �⺻ ���� Ÿ��
class ArrayVector {
public:
	ArrayVector();
	int size() const;
	bool empty() const;
	Elem& operator[](int i);
	Elem& at(int i) throw(out_of_range);
	void erase(int i);
	void insert(int i);
private:
	int capacity; // �迭�� ũ��
	int n; // ���Ϳ� ����� ���ҵ��� ��
	Elem* A; // ���Ҹ� �����ϴ� �迭
};

