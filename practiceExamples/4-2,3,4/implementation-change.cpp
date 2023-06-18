#include <iostream>

using namespace std;
typedef char * arrayString;
void concatenate(arrayString& s1, const arrayString& s2);
void append(arrayString& s, const char c);
char characterAt(const arrayString& s, int pos);
arrayString createArrayString(char *array);
void printAString(const arrayString& s);

int main(void) {
    char a[] = " Hello";
    a[0] = 5;
    arrayString s1 = createArrayString(a);
    char b[] = " World!";
    b[0] = 6;
    arrayString s2 = createArrayString(b);
    
    append(s1, ' ');
    printAString(s1);
    cout << " | " << characterAt(b, 5) << '\n';
    concatenate(s1, s2);
    printAString(s1);

    delete[] s1;
    delete[] s2;
    return 1;
}

void concatenate(arrayString& s1, const arrayString& s2) {
    int newLength = s1[0] + s2[0];
    arrayString tempS = new char[newLength + 1];
    tempS[0] = newLength;
    for(int i = 1; i <= s1[0]; i++) {
        tempS[i] = s1[i];
    }
    for(int i = 1; i <= s2[0]; i++) {
        tempS[i + s1[0]] = s2[i];
    }
    delete[] s1;
    s1 = tempS;
}

void append(arrayString& s, const char c) {
    int newLength = s[0] + 2;
    arrayString temp = new char[newLength];
    for(int i = 1; i <= s[0]; i++) temp[i] = s[i];
    temp[0] = newLength;
    temp[newLength] = c;
    delete[] s;
    s = temp;
}

char characterAt(const arrayString& s, int pos) {
    return s[pos];
}

arrayString createArrayString(char *array) {
    arrayString returnS = new char[array[0] + 1];
    for(int i = 0; i <= array[0]; i++) {
        returnS[i] = array[i];
    }
    return returnS;
}

void printAString(const arrayString& s) {
    for(int i = 1; i <= s[0]; i++) {
        cout << s[i];
    }
}