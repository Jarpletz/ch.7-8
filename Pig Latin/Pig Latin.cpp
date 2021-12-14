

#include <iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

string ConvertWord(string);
string ConvertPhrase(string);
int main()
{
	string phrase;
	string ephraserb;

	cout << "Ferb Latin Converter" << endl;
	cout << "How it works:"<<endl << "You take the first letter of every word, (Whenever someone sneezes)\nYou move it to the end and then say '-erb' (You no longer say 'bless you')\nIt's like we're adding a phonetic caboose to it(Instead you play a flugelhorn) \nDon't get confused, just get used to it (And give him your left shoe)!" << endl << endl;

	cout << "Your phrase:";
	getline(cin, phrase);
	ephraserb=ConvertPhrase(phrase);
	cout << "Your Phrase In Ferb Latin:" << ephraserb << endl;

	return 0;
}

string ConvertPhrase(string phrase) {
	phrase += " ";

	int LastSpace=0;
	int NextSpace=0;
	int numbSpaces=0;
	string word;
	string final="";

	for (int i = 0; i < static_cast<int>(phrase.length());i++) {
		if (phrase[i] == ' ') numbSpaces++;
	}
	cout << numbSpaces<<" ";
	for (int i = 0;i < (numbSpaces);i++) {
		NextSpace = phrase.find(" ", LastSpace);
		word = phrase.substr(LastSpace,NextSpace-LastSpace);
		word = ConvertWord(word);
		final += " ";
		final += word;
		LastSpace = NextSpace+1;
	}

	return final;
}
string ConvertWord(string word) {
	string newWord;
	newWord = word.substr(1,word.length()-1);
	newWord += (word[0]);
	newWord += "erb";
	return newWord;
}