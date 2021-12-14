
#include <iostream>
#include<string>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int returnNumbSpaces(string);
void analizeWords(string);
void breakdownLetters(string);

string phrase = "";
int numbSpaces;

int main()
{
    cout << "Throckmorton phrase analysis" << endl << endl;
    do {

        cout << "Throckmorton's next phrase:";
        getline(cin, phrase);

        if (phrase != "") {
            numbSpaces = returnNumbSpaces(phrase);
            cout << "Number of spaces: " << numbSpaces << endl;
            analizeWords(phrase);

        }//do all the analysis

    } while (phrase != "STOP");


    return 0;
}

int returnNumbSpaces(string phrase) {
    int count = 0;
    for (int i = 0;i < static_cast<int>(phrase.length());i++) {
        if (phrase[i] == ' ') count++;
    }
    return count;
}

void analizeWords(string phrase) {
    int lastSpace = 0;
    string word;

    phrase += " ";//so that it will analize the last word

    for (int i = 0;i < numbSpaces + 1;i++) {
        int nextSpace = phrase.find(" ", lastSpace);
        // cout << "nextSpace:" << nextSpace << endl;
        // cout << "lastSpace:" << lastSpace << endl;
        word = phrase.substr(lastSpace, nextSpace - lastSpace);
        breakdownLetters(word);
        lastSpace = nextSpace + 1;
    }
    return;
}
void breakdownLetters(string word) {
    int vowels = 0;
    int cons = 0;
    int permutations=1;

    cout << "Word: " << word<<endl;

    for (int i = 0;i < static_cast<int>(word.length());i++) {
       // char ch = ;
       switch(toupper(word[i]))
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            vowels++;
            break;
        case 'C':
        case 'D':
        case 'F':
        case 'G':
        case 'H':
        case 'J':
        case 'K':
        case 'L':
        case 'M':
        case 'N':
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
        case 'T':
        case 'V':
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            cons++;
            break;
        default:
            break;
        }
    }
    //finds number of consonants and vowels

    for (int i = 0;i< static_cast<int>(word.length());i++) {
        permutations *= (i+1);
    }
    //finds number of permutations

    cout << setw(23) << left << "     Number of Vowels: " << vowels << endl;
    cout << setw(23) << left << "     Number of Consonants:" << cons << endl;
    cout << setw(23) << left << "     Number of Permutations:" << permutations << endl;
    return;

}

