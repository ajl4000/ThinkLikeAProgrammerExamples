#include <iostream>

using namespace std;

typedef char * arrayString;
char characterAt(arrayString s, int position);
int length(arrayString s);
arrayString substring(const arrayString& s, int start, int sLength);

int main(void) {
    arrayString a = new char[5];
    a[0] = 't', a[1] = 'e', a[2] = 's', a[3] = 't', a[4] = 'i', a[5] = 'n', a[6] = 'g', a[7] = 0;
    arrayString sub = substring(a, 8, 3);
    for(int i = 0; i < length(sub); i++) {
        cout << sub[i];
    }
    cout << '\n';
    delete[] a;
    delete[] sub;
    return 1;
}

arrayString substring(const arrayString& s, int start, int sLength) {
    if(start + sLength - 1 > length(s)) {
        sLength = length(s) - start + 1;
    }
    arrayString sub = new char[sLength + 1];
    for(int i = 0; i < sLength; i++) {
        sub[i] = s[i + start - 1];
    }
    sub[sLength] = 0;
    return sub;
}

char characterAt(arrayString s, int position) {
    return s[position];
}

int length(arrayString s) {
    int count = 0;
    while(s[count] != 0) {count++;}
    return count;
}