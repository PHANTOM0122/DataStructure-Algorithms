#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define TABLE_SIZE 1000
#define INPUT_SIZE 500
using namespace std;

struct Student {
	int id;
	char name[20];
};

struct Bucket {
	Student* data;
	Bucket* next;
};

void constructor(Bucket** hashTable);
void destructor(Bucket** hashTable);
int isExist(Bucket** hashTable, int id);
void add(Bucket** hashTable, Student* input);
void print(Bucket** hashTable);

int main() {
	srand(unsigned int(time(0)));
	Bucket** hashTable;
	hashTable = new Bucket * [TABLE_SIZE];
	constructor(hashTable);

	for (int i = 0; i < INPUT_SIZE; i++) {
		Student* student = new Student;
		student->id = rand() % 10000;
		sprintf_s(student->name, "���%d", student->id);
		if (!isExist(hashTable, student->id)) { // �ߺ��Ǵ� id�� ���� ��
			add(hashTable, student);
		}
	}

	print(hashTable);
	destructor(hashTable);
}

void constructor(Bucket** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

void destructor(Bucket** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			delete hashTable[i];
		}
	}
}

int isExist(Bucket** hashTable, int id)
{
	int i = id % TABLE_SIZE;
	if (hashTable[i] == NULL) return 0;
	else {
		Bucket* cur = hashTable[i];
		while (cur != NULL) {
			if (cur->data->id == id) { return i; break; }
			cur = cur->next;
		}
	}
	return 0; // not Found!
}

void add(Bucket** hashTable, Student* input) // addFront!
{
	int i = input->id % TABLE_SIZE;
	if (hashTable[i] == NULL) { // empty table�� ����
		hashTable[i] = new Bucket;
		hashTable[i]->data = input;
		hashTable[i]->next = nullptr;
	}
	else { // exist�� hash�� ����
		Bucket* cur = new Bucket;
		cur->data =input;
		cur->next = hashTable[i];
		hashTable[i] = cur;
	}
}

void print(Bucket** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			Bucket* cur = hashTable[i];
			while (cur != NULL) { // ���� hash ���� ��� linkedlist�� print�ϱ� ���ؼ�
				cout << "Ű: [" << i << "] �̸�: " << cur->data->name << endl;
				cur = cur->next;
			}
		}
	}
}




