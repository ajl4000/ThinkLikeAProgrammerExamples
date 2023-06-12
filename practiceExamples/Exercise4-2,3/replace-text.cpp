#include <iostream>
#include <string>

using namespace std;

typedef char * arrayString;
int length(arrayString s);

int main(void) {
    arrayString source = new char[9];
    source[0] = 'a', source[1] = 'b', source[2] = 'c', source[3] = 'd', source[4] = 'a',
    source[5] = 'b', source[6] = 'e', source[7] = 'e', source[8] = 0;
    arrayString target = new char[3];
    target[0] = 'a', target[1] = 'b', target[2] = 0;
    arrayString replaceText = new char[4];
    replaceText[0] = 'x'; replaceText[1] = 'y'; replaceText[2] = 'z'; replaceText[3] = 0;
    replaceString(source, target, replaceText);
    return 1;
}

void replaceString(arrayString& source, const arrayString& target, const arrayString& replaceText) {
    int resultStrLen;
    arrayString
}

void concatenate(arrayString& s1, arrayString s2) {
    int s1_OldLength = length(s1);
    int s2_Length = length(s2);
    int s1_NewLength = s1_OldLength + s2_Length;
    arrayString newS = new char[s1_NewLength + 1];
    for(int i = 0; i < s1_OldLength; i++) {
        newS[i] = s1[i];
    }
    for(int i = 0; i < s2_Length; i++) {
        newS[s1_OldLength + i] = s2[i];
    }
    newS[s1_NewLength] = 0;
    delete[] s1;
    s1 = newS;
}

int length(arrayString s) {
    int count = 0;
    while(s[count] != 0) {count++;}
    return count;
}