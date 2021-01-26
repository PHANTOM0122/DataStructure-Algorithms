#include "ArrayVector.h"

using namespace std;

ArrayVector::ArrayVector() : capacity(0), n(0), A(nullptr) {}

int ArrayVector::size() const
{
	return n;
}

bool ArrayVector::empty() const
{
	return size() == 0;
}

Elem& ArrayVector::operator[](int i)
{
	return A[i];
}

Elem& ArrayVector::at(int i) throw(out_of_range)
{
	if (i<0 || i>capacity)
		throw out_of_range("Invalid index");
	return A[i];
		
}

void ArrayVector::erase(int i)
{
	for (int j = i + 1; j < n; j++) // �ε����� ���Ҹ� ����
		A[j - 1] = A[j]; // ���Ҹ� ������ �̵�
	n--; // ���� ���� 1 ����
}

void ArrayVector::insert(int i, const Elem& e)
{
	if (n > capacity || n < 0)
		throw out_of_range("Invalid index");
	for (int j = i; j <= n; j++) {
		A[j + 1] = A[j];
	}
	A[i] = e; // ����ִ� ���� ���� ����
	n++; // ���� ���� 1����
}


