
#include <iostream>
#include<cstdlib>
#include<string>
using namespace std;

void outputNames();
void inputNames();
void changeOneName(int, string);
void modifyNames();

const int nameLength = 5;
char names[nameLength][500];

int main()
{
    inputNames();
    outputNames();

    bool doneEditing = false;

    while (!doneEditing) {
        cout << "Would you like to change someone's name? (Y/N)";
        char choice;
        cin >> choice;
        switch (toupper(choice))
        {
        case'Y':
            modifyNames();
            outputNames();
            break;
        case'N':
            cout << "Ok! Final edits complete!";
            outputNames();
            doneEditing = true;
            break;
        default:
            cout << "ERROR: Please enter 'Y' or 'N'! " << endl;
            break;
        }

    }


    return 0;
}
void inputNames() {
    cout << "Please enter Names of family members:" << endl;
    for (int i = 0;i < nameLength;i++) {
        cout << "Name of Family Member #" << i + 1 << ":";
        string nextName;
        getline(cin, nextName);
        changeOneName(i, nextName);

    }
}
void outputNames() {
    cout << "\nYour Family Members:" << endl;
    for (int i = 0;i < nameLength;i++) {
        cout << "#" << i + 1 << ":";
        for (int j = 0;j < 500;j++) {
            cout << names[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void modifyNames() {
    cout << "Whose name would you like to change? (Please input their number):";
    int nameIndex;
    cin >> nameIndex;
    nameIndex -= 1;//determine index of name changed
    cout << nameIndex;
    cout << "What would you like to change their name to?";
    string nextName;
    cin.ignore();
    getline(cin, nextName);
    changeOneName(nameIndex, nextName);
    

}
void changeOneName(int index, string newName) {
    for (int i = 0;i < 500;i++) {
        names[index][i] = '\0';
    }
    for (int j = 0;j < static_cast<int>(newName.length());j++) {
        names[index][j] = newName[j];
    }

}