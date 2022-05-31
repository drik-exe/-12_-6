//6. В текстовом файле находится текст на латинице, слова разделены только одним пробелом, в конце каждого предложения ставится точка.Нет ведущих и 
//завершающих пробелов, нет никаких знаков препинания кроме точки.
//Считать из файла текст.
//Определить количество строчных гласных букв в тексте и вывести его на экран.
//Заменить первое словосочетание «Аа» на «оО» в тексте и вывести измененный текст в конец исходного текстового файла.
//Поместить в отдельную переменную Stt первые два слова.Если в тексте нет двух слов, то вывести соответствующее сообщение.
//Добавить в конец строки переменной Stt столько символов « - », сколько строчных гласных букв в тексте и вывести ее на экран.

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
		cout << "Переменная Stt = " << Stt << endl;
	}
	else {
		cout << "В тексте нет двух слов" << endl;
	}
	

}

int main() {

	setlocale(0, "");

	fstream file("Text.txt", ios::in);

	string text;
	char ch;
	char vowes[6] = { 'a', 'e', 'u', 'i', 'o', 'y' };

	if (!file.is_open()) {
		cout << "Ошибка открытия файла" << endl;
	}
	else {
		cout << "Файл открыт успешно" << endl;
		while (file.get(ch)) {
			text += ch;
		}

	}

	file.close();

	cout << "Количество строчныйх гласных = " << CountVowes(text, vowes) << endl;




	int pos = -1;

	pos = text.find("Aa");
	if (pos >= 0) {
		text.erase(pos, 1);
		text.insert(pos, 1, 'o');
		text.erase(pos + 1, 1);
		text.insert(pos + 1, 1, 'O');
	}
	else {
		cout << "Нет словосочетания Аа" << endl;
	}

	file.open("Text.txt", ios::app);

	file << text;

	file.close();

	Change(text, CountVowes(text, vowes));




}
