#include <iostream>
#include <vector>

using namespace std;

void insertionSort(char* A, int n) { // n���� ������ �迭�� ����
	for (int i = 1; i < n-1; i++) { // ���� ����
		char cur = A[i]; // �����Ϸ��� ������ ����
		int j = i - 1; // �ٷ� ���� ���ڿ��� ����
		while ((j >= 0) && (A[j] > cur)) { // A[j]�� ������ ��߳� �ִ� ����
			A[j + i] = A[j]; // A[i]�� ���������� �̵�
			j--; // j�� ����
		}
		A[j + i] = cur; // �̰��� cur���� �´� ��ġ
	}
}

void InsertSort(vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n - 1; i++) {
		int j = i; // j is insert index
		while (j >= 0 && v[j] > v[j + 1]) {
			swap(v[j], v[j + 1]); // v[j]�� v[j+1]�� ���Ҹ� ��
			j--; // ���� v[j+1]�� v[j-1]�� sort!
		}
	}
}

int main() {
	char list[3] = { 'C', 'A', 'F' };
	insertionSort(list, 3);
	for (int i = 0; i < 3; i++)
		cout << list[i] << ' ';
}
