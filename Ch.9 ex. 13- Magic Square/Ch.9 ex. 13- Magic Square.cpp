

#include <iostream>
#include<iomanip>
#include<string>
using namespace std;



const int listSize = 16;
const int rows = 4;
const int columns = 4;

void createArithmeticSeq(int[], int);
void matricize(int[], int[][columns]);
void printMatrix(int[][columns]);
void reverseDiagonal(int[][columns]);
void magicCheck(int[], int[][columns]);

int main()
{
    int list[listSize];
    int matrix[rows][columns];

    createArithmeticSeq(list, listSize);
    matricize(list, matrix);
    printMatrix(matrix);
    reverseDiagonal(matrix);
    printMatrix(matrix);
    magicCheck(list, matrix);

    return 0;
}

void createArithmeticSeq(int list[], int size){
    int first, diff;
    cout << "First Value of Arithmetic Sequence:";
    cin >> first;
    cout << "Arithmetic Sequence increase diffrence:";
    cin >> diff;
    cout << "\nArithmetic Sequence: ";
    for (int i = 0;i < size;i++) {
        list[i] = first + (diff * i);
        cout << list[i] << " ";
    }
    cout << endl << endl;
    return;
}

void matricize(int list[], int matrix[][columns]) {
    cout << "Original Matrix:" << endl;
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < columns;j++) {
            matrix[i][j] = list[(j+(columns*i))];
        }
    }
}

void printMatrix(int matrix[][columns]) {
    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < columns;j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void reverseDiagonal(int matrix[][columns] ) {
    cout << "Diagonals reversed:" << endl;
    int tempMatrix[rows][columns];

    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < columns;j++) {
            tempMatrix[i][j] = matrix[i][j];
        }
    }//initialize temporary matrix of old values

    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < columns;j++) {
            if (i == j|| columns - i - 1 == j){
                matrix[i][j] = tempMatrix[rows - i - 1][columns - j - 1];
            }
        }
    }//reverse diagonals of matrix

}

void magicCheck(int list[], int matrix[][columns]) {
    int magicNumber=0;
    bool failedTest = false;
    int testSum=0;

    for (int i = 0; i < listSize;i++) {
        magicNumber += list[i];
    }
    magicNumber /= 4;
    //calculate magic #
    cout << "Magic Number:" << magicNumber << endl;

    for (int i = 0;i < rows;i++) {
        for (int j = 0;j < columns;j++) {
            testSum += matrix[i][j];
        }
        cout << testSum << endl;
        if (testSum != magicNumber) {
            failedTest = true;
        }
        testSum = 0;
    }//check all rows
    
    for (int i = 0;i < columns;i++) {
        for (int j = 0;j < rows;j++) {
            testSum += matrix[j][i];
        }
        cout << testSum << endl;
        if (testSum != magicNumber) {
            failedTest = true;
        }

        testSum = 0;
    }//check all columns
    

    for (int i = 0;i < rows;i++) {
        testSum += matrix[i][i];
    }
    if (testSum != magicNumber) {
        failedTest = true;
    }//check top-to-bottom diagonals
    cout << testSum << endl;

    testSum = 0;
    
    for (int i = 0;i < rows;i++) {
        testSum += matrix[i][rows-i-1];
    }
    if (testSum != magicNumber) {
        failedTest = true;
    }//check bottom-to-top diagonals
    cout << testSum << endl;

    testSum = 0;

    if (!failedTest) {
        cout << "This is a magic square!!! :D" << endl;
        return;
    }
    cout << "This is NOT a magic square. :(" << endl;
    
}