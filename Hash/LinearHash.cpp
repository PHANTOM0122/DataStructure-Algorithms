#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <stdio.h>
#define TABLE_SIZE 1000
#define INPUT_SIZE 500

using namespace std;

struct Student {
	int id;
	string name;
};

void init(Student** hashTable); // Constructor
void destructor(Student** hashTable); // Destructor
int findEmpty(Student** hashTable, int id); // ���� ����� Ž��
int search(Student** hashTable, int id); // Ư���� ID���� match data return!
void add(Student** hashTable, Student* input, int key); // Ư���� Ű �ε����� ������ ����
Student* getValue(Student** hashTable, int key); // �ؽ� ���̺� Ư���� Ű�� ������ ��ȯ
void print(Student** hastTable);

int main() {
	//srand(unsigned int(ctime(0))); // Get seed
	Student** hashTable = new Student* [TABLE_SIZE];
	init(hashTable);

	for (int i = 0; i < INPUT_SIZE; i++) {
		Student* student = new Student;
		student->id = rand() % 1000000;
		student->name = "���";
		if (search(hashTable, student->id) == -1) { // �ߺ��Ǵ� ID�� �������� ������
			int index = findEmpty(hashTable, student->id);
			add(hashTable, student, index);
		}
	}

	print(hashTable);
	destructor(hashTable);
}


void init(Student** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		hashTable[i] = NULL;
	}
}

void destructor(Student** hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL)
			delete hashTable[i];
	}
}

// Empty ������ index return
int findEmpty(Student** hashTable, int id)
{
	int i = id % TABLE_SIZE;
	while (1) {
		if (hashTable[i] == NULL) { // Break; 
			return i % TABLE_SIZE;
			break;
		}
		i++; // if hashTable[i] isn't empty!
	}
}

int search(Student** hashTable, int id)
{
	int i = id & TABLE_SIZE;
	while (1) {
		if (hashTable[i % TABLE_SIZE] == NULL) return -1; // empty!
		else if (hashTable[i % TABLE_SIZE]->id == id) return i; // id�� �ƴ� hash���� ���� id�� �����ϴ� ��� ����
		i++;
	}
}

void add(Student** hashTable, Student* input, int key)
{
	hashTable[key] = input;
}

Student* getValue(Student** hashTable, int key) {
	return hashTable[key];
}

void print(Student** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		if (hashTable[i] != NULL) {
			cout << "Ű: [" << i << "].  �̸�: " << hashTable[i]->name << endl;
		}
	}
}


