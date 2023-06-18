#include <iostream>

using namespace std;

class variableLengthString {
    private: 
        struct stringNode {
            char letter;
            stringNode* next;
        };
        typedef stringNode* stringList;
    public:
        variableLengthString();
        variableLengthString(char* stringArray, int stringLength);
        ~variableLengthString();
        int stringLength();
        char charAt(int position);
        void append(char c);
        void concatenate(variableLengthString newString);
        void printList();
    private:        
        stringList _listHead;
        stringList _listTail;
        int _stringLength;
        void deleteList(stringList& listPtr);
};

variableLengthString::variableLengthString() {
    _listHead = NULL;
    _listTail = NULL;
    _stringLength = 0;
}

variableLengthString::variableLengthString(char* stringArray, int stringLength) {
    _stringLength = stringLength;
    _listHead = new stringNode;
    _listHead->letter = stringArray[0];
    stringNode* curr;
    curr = _listHead;
    for(int i = 1; i < stringLength; i++) {
        stringNode* next = new stringNode;
        next->letter = stringArray[i];
        curr->next = next;
        curr = next;
    }
    curr->next = NULL;
    _listTail = curr;
}

variableLengthString::~variableLengthString() {
    deleteList(_listHead);
}

int variableLengthString::stringLength() {
    return _stringLength;
}

void variableLengthString::deleteList(stringList& listPtr) {
    _listTail = NULL;
    while(listPtr != NULL) {
        stringList temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

char variableLengthString::charAt(int pos) {
    if(_stringLength == 0 || pos > _stringLength || pos < 1) return 0;
    stringNode* curr = _listHead;
    for(int i = 1; i < pos; i++) {
        curr = curr->next;
    }
    return curr->letter;
}

void variableLengthString::append(char c) {
    stringNode* newNode = new stringNode;
    newNode->letter = c;
    newNode->next = NULL;
    _listTail->next = newNode;
    _listTail = newNode;
    _stringLength++;
}

void variableLengthString::concatenate(variableLengthString s) {
    if(s._stringLength == 0) return;
    stringNode* thisListPtr = _listTail;
    stringNode* newListPtr = s._listHead;
    while(newListPtr != NULL) {
        stringNode* newNode = new stringNode;
        newNode->letter = newListPtr->letter;
        thisListPtr->next = newNode;
        thisListPtr = thisListPtr->next;
        newListPtr = newListPtr->next;
    }
    thisListPtr->next = NULL;
    _stringLength += s._stringLength;
}

void variableLengthString::printList() {
    stringNode* listPtr = _listHead;
    while(listPtr != NULL) {
        cout << listPtr->letter;
        listPtr = listPtr->next;
    }
}

int main(void) {
    char s1[] = "Hello";
    variableLengthString vString = variableLengthString(s1, 5);
    vString.append(' ');
    cout << vString.charAt(7) << '\n';
    char s2[] = "World!";
    variableLengthString vString2 = variableLengthString(s2, 6);
    vString.concatenate(vString2);
    cout << vString.stringLength() << ", ";
    vString.printList();
    return 1;
}