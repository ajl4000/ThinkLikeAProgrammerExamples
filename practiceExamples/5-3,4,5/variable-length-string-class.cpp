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
        void concatenate(const variableLengthString& newString);
        void printList();
        variableLengthString& operator=(const variableLengthString& rhs);
        char operator[](int i);
        void remove(int position, int length);
    private:        
        stringList _listHead;
        stringList _listTail;
        int _stringLength;
        void deleteList(stringList& listPtr);
        stringList copiedList(const stringList original);
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
    _stringLength = 0;
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

void variableLengthString::concatenate(const variableLengthString& s) {
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

variableLengthString::stringList variableLengthString::copiedList(const stringList original) {
    if(original == NULL) return NULL;
    stringNode* ogList = original;
    stringNode* newList = new stringNode;
    stringNode* stringHead = newList;
    newList->letter = ogList->letter;
    ogList = ogList->next;
    int i = 1;
    while(ogList != NULL) {
        stringNode* newNode = new stringNode;
        newNode->letter = ogList->letter;
        newList->next = newNode;
        newList = newList->next;
        ogList = ogList->next;
        i++;
    }
    newList->next = NULL;
    _stringLength = i;
    return stringHead;
}

variableLengthString& variableLengthString::operator=(const variableLengthString& rhs) {
    if(this != &rhs) {
        deleteList(_listHead);
        _listHead = copiedList(rhs._listHead);
    }
    return *this;
}

char variableLengthString::operator[](int i) {
    return charAt(i);
}

void variableLengthString::remove(int position, int length) {
    if(position < 1 || position > _stringLength) return;
    stringNode* nodePtr = _listHead;
    stringNode* trailingPtr = NULL;
    int i = 1;
    while(nodePtr != NULL && i < position) {
        trailingPtr = nodePtr;
        nodePtr = nodePtr->next;
        i++;
    }
    int j = 0;
    while(j < length && nodePtr != NULL) {
        stringNode* temp = nodePtr;
        if(i == 1) {
            nodePtr = nodePtr->next;
            _listHead = nodePtr;
            delete temp;
        }
        else {
            nodePtr = nodePtr->next;
            trailingPtr->next = nodePtr;
            delete temp;
        }
        j++;
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
    cout << '\n';
    vString2 = vString;
    vString2.printList();
    cout << '\n';
    cout << vString[1] << " " << vString2.stringLength();
    cout << '\n';
    vString2.remove(6, 6);
    vString2.printList();
    return 1;
}