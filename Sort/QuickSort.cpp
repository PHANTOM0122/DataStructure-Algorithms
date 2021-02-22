#include <iostream>

using namespace std;

int v[100];

void swap(int& a, int& b);
void QuickSort(int start, int end);

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	QuickSort(0, n - 1);
	for (int elem : v)
		cout << elem << ' ';
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void QuickSort(int start, int end) {
	if (start > end) return; // 
	int pivot = start, i = start + 1, j = end, temp; // ���� ������ pivot�̶� ����

	while (i <= j) { // left <= right �� ��쿡�� �۵�
		while (i <= end && v[i] <= v[pivot]) i++; // i�� left���� �����Ͽ� v[pivot] ���� ū ���� index
		while (j > start && v[j] >= v[pivot]) j--; // j�� right���� �����Ͽ� v[pivot] ���� ���� ���� index
		if (i > j) swap(v[pivot], v[j]); // left > right�� ��� pivot���� right�� swap (right�� pivot���� ���� ���̹Ƿ�!)
		else swap(v[i], v[j]); // left<=right�� ��� left, right swap
	}
}