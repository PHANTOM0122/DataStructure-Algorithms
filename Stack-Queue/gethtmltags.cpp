#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

vector<string> getHtmlTags() {
	vector<string> tags;
	string line;
	while (getline(cin, line)) {// ���� ������ �д´�.
		; // �ؽ�Ʈ�� �� ���� �Է��Ѵ�
		cin >> line;
		int pos = 0;
		int ts = line.find("<", pos); // �±��� ����
		while (ts != string::npos) { // ���ڿ��� ������ �ݺ��Ѵ�. npos - ���๮��
			int te = line.find(">", ts + 1);
			tags.push_back(line.substr(ts, te - ts + 1));// �±� ���� ���ڿ��� ���Ϳ� �߰�
			pos = te + 1; // ���� ��ġ�� ����!
			ts = line.find("<", pos);
		}
	}
	return tags;
}

bool isHtmlMatched(const vector<string>& tags) { // �±� ¦���� Ȯ��
	stack<string> S;
	typedef vector<string>::const_iterator Iter; // Iterator type!

	for (Iter p = tags.begin(); p != tags.end(); p++) {
		if (p->at(1) != '/') // ���� �±��϶�
			S.push(*p); // ���� �±��̸� ���ÿ� push
		else { // �ݴ� �±��϶�
			if (S.empty()) return false; // ¦�� ����!
			string open = S.top().substr(1); // '<'�� ������ ���� �±�
			string close = S.top().substr(2); // '</'�� ������ �ݴ� �±�
			if (open.compare(close) != 0) // �������� ����!
				return false;
			else S.pop(); // ������ ���, ¦�� �´� ���Ҹ� pop!
		}
	}
	if (S.empty()) return true; // ������ ��������� ��� ¦�� �´� ���
	else return false; // ���� �ʴ� ���� �ִ�!
}

// Test Driver
int main() {
	if (isHtmlMatched(getHtmlTags())) // Read Tags!
		cout << "The input file is a matched Html Tags!" << endl;
	else
		cout << "The input file is not a matched Html Tags!" << endl;
}