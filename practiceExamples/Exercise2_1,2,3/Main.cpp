#include <iostream>
#include <cstdlib>

using namespace std;

void insertSpaces(int numOfSpaces) {
    for(int i = 0; i < numOfSpaces; i++) {
        cout << " ";
    }
}

void exercise2_1() {
    for(int row = 0; row < 4; row++) {
        insertSpaces(row);
        for(int hashNum = 0; hashNum < 8 - 2 * row; hashNum++) {
            cout << "#";
        }
        insertSpaces(row);
        cout << "\n";
    }
}

void exercise2_2Practice() {
    for(int row = 0; row < 4; row++) {
        insertSpaces(3 - row);
        for(int hashNum = 0; hashNum < 2 + 2 * row; hashNum++) {
            cout << "#";
        }
        insertSpaces(row);
        cout << "\n";
    }
}

void exercise2_2() {
    for(int row = 0; row < 8; row++) {
        int numOfSpaces = 3 - row;
        if(numOfSpaces < 0) numOfSpaces = abs(numOfSpaces) - 1;
        insertSpaces(numOfSpaces);
        for(int hashNum = 0; hashNum < 8 - 2 * numOfSpaces; hashNum++) {
            cout << "#";
        }
        insertSpaces(numOfSpaces);
        cout << "\n";
    }
}

void exercise2_3() {
    for(int row = 0; row < 8; row++) {
        int numOfSpaces = 3 - row;
        if(numOfSpaces < 0) numOfSpaces = abs(numOfSpaces) - 1;
        numOfSpaces = 3 - numOfSpaces;
        insertSpaces(numOfSpaces);
        int numOfHashes = numOfSpaces + 1;
        for(int hashNum = 0; hashNum < 2 * numOfHashes; hashNum++) {
            if(hashNum == numOfHashes) insertSpaces(14 - 2 * (numOfHashes + numOfSpaces));
            cout << "#";
        }
        insertSpaces(numOfSpaces);
        cout << "\n";
    }
}

int main() {
    exercise2_1();
    cout << "\n";
    exercise2_2();
    cout << "\n";
    exercise2_3();
}