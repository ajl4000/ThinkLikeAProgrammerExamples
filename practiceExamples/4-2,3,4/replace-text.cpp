#include <iostream>
#include <string>

using namespace std;

typedef char * arrayString;
int length(arrayString s);
void replaceString(arrayString& source, const arrayString& target, const arrayString& replaceText);
arrayString substring(const arrayString& s, int start, int sLength);
void concatenate(arrayString& s1, arrayString s2);
arrayString createArrayString(char *array);

int main(void) {
    char tempS[] = "abcdabee";
    arrayString source = createArrayString(tempS);
    char tempT[] = "e";
    arrayString target = createArrayString(tempT);
    char tempR[] = "xyz";
    arrayString replaceText = createArrayString(tempR);

    cout << "          Source: " << source << "\n          Target: " << target << "\nReplacement Text: " << replaceText << '\n';
    replaceString(source, target, replaceText);
    cout << "  Replace Result: " << source;

    delete[] source;
    delete[] target;
    delete[] replaceText;

    return 1;
}

void replaceString(arrayString& source, const arrayString& target, const arrayString& replaceText) {
    int targetLength = length(target);
    arrayString tempS = new char[0];
    tempS[0] = 0;
    int i = 0;
    while(source[i] != 0) {
        if(source[i] == target[0]) {
            bool matches = true;
            for(int j = 1; j < targetLength; j++) {
                if(source[i + j] != target[j]) matches = false;
            }
            if(matches) {
                concatenate(tempS, replaceText);
                i += targetLength - 1;
            }
        }
        else {
            concatenate(tempS, substring(source, i + 1, 1));
        }
        i++;
    }
    delete[] source;
    source = tempS;
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

arrayString createArrayString(char *array) {
    int arrayLength = length(array);
    arrayString returnS = new char[arrayLength + 1];
    for(int i = 0; i < arrayLength + 1; i++) {
        returnS[i] = array[i];
    }
    return returnS;
}