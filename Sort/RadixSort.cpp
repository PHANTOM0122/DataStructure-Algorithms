#include <iostream>
#define MAX 100
using namespace std;

void radixsort(int*, int);
int main() {
	int a[MAX];
	int i, n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	radixsort(a, n);
	for (i = 0; i < n; i++)
		cout << a[i] << ' ';
}

void radixsort(int* a, int n) {
	int result[MAX], maxValue = 0;
	int exp = 1; // �ڸ��� 1�� �ڸ�����
	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i]; // find Maxvalue
	}

	while (maxValue / exp > 0) { // 1�� �ڸ����� �ְ� �ڸ������� ���
		int bucket[10] = { 0 }; // �ڸ��� �迭
		for (int i = 0; i < n; i++) bucket[(a[i] / exp) % 10]++; // �ڸ��� �迭 ó��
		for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1]; // ���� ��� ó��
		for (int i = n - 1; i >= 0; i--) { // ���� �ڸ��� ������ ������ ����. ���� ���Һ��� ����
			result[--bucket[(a[i] / exp) % 10]] = a[i]; // result [ �����迭�� ��-1 ]�� value�Է�
		}
		for (int i = 0; i < n; i++) a[i] = result[i]; // �⺻ �迭�� result�迭�� ����
		exp *= 10; // �ڸ��� ����
	}
}