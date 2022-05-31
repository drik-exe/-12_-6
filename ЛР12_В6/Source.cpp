//6. � ��������� ����� ��������� ����� �� ��������, ����� ��������� ������ ����� ��������, � ����� ������� ����������� �������� �����.��� ������� � 
//����������� ��������, ��� ������� ������ ���������� ����� �����.
//������� �� ����� �����.
//���������� ���������� �������� ������� ���� � ������ � ������� ��� �� �����.
//�������� ������ �������������� ��� �� ��λ � ������ � ������� ���������� ����� � ����� ��������� ���������� �����.
//��������� � ��������� ���������� Stt ������ ��� �����.���� � ������ ��� ���� ����, �� ������� ��������������� ���������.
//�������� � ����� ������ ���������� Stt ������� �������� � - �, ������� �������� ������� ���� � ������ � ������� �� �� �����.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int CountVowes(string str, char (&vowes)[6]) {
	int count_vowes = 0;
	for (char ch1 : str) {
		for (char ch2 : vowes)
		{
			if (ch1 == ch2) {
				count_vowes++;
				break;
			}
		}
	}
	return count_vowes;
}

void Change(string str, int count_vowes) {

	int count_space = 0;
	string Stt;

	for (char i : str) {
		if (i == ' ') {
			++count_space;
		}
		if (count_space >= 2) {
			break;
		}
		Stt.push_back(i);

	}
	if (count_space >= 2) {
		for (size_t i = 0; i < count_vowes; i++)
		{
			Stt.push_back('-');
		}
		cout << "���������� Stt = " << Stt << endl;
	}
	else {
		cout << "� ������ ��� ���� ����" << endl;
	}
	

}

int main() {

	setlocale(0, "");

	fstream file("Text.txt", ios::in);

	string text;
	char ch;
	char vowes[6] = { 'a', 'e', 'u', 'i', 'o', 'y' };

	if (!file.is_open()) {
		cout << "������ �������� �����" << endl;
	}
	else {
		cout << "���� ������ �������" << endl;
		while (file.get(ch)) {
			text += ch;
		}

	}

	file.close();

	cout << "���������� ��������� ������� = " << CountVowes(text, vowes) << endl;




	int pos = -1;

	pos = text.find("Aa");
	if (pos >= 0) {
		text.erase(pos, 1);
		text.insert(pos, 1, 'o');
		text.erase(pos + 1, 1);
		text.insert(pos + 1, 1, 'O');
	}
	else {
		cout << "��� �������������� ��" << endl;
	}

	file.open("Text.txt", ios::app);

	file << text;

	file.close();

	Change(text, CountVowes(text, vowes));




}
