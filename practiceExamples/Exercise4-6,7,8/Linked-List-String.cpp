#include <iostream>

using namespace std;

struct stringNode* removeChars(struct stringNode* s, int pos, int length);
void concatenate(struct stringNode* s1, struct stringNode* s2);
void append(struct stringNode* s, char c);
char characterAt(struct stringNode* s, int index);
struct stringNode* createListFromString(char *s, int stringSize);
void printString(struct stringNode *s);

struct stringNode{
    char letter;
    stringNode* next;
};

int main(void) {
    char s1[] = "Hello"; 
    struct stringNode* head = createListFromString(s1, 5);
    char s2[] = "World!"; 
    struct stringNode* world = createListFromString(s2, 6);
    printString(head);
    cout << '\n';
    cout << characterAt(head, 4) << '\n';
    append(head, '!');
    printString(head);
    cout << '\n';
    concatenate(head, world);
    printString(head);
    cout << '\n';
    head = removeChars(head, 1, 6);
    printString(head);
    cout << '\n';


    return 1;
}

struct stringNode* removeChars(struct stringNode* s, int pos, int length) {
    struct stringNode* nodePtr = s;
    struct stringNode* trailing = NULL;
    int i = 1;
    while(nodePtr != NULL && i != pos) {
        trailing = nodePtr;
        nodePtr = nodePtr->next;
        i++;
    }
    int j = 1;
    while(j <= length && nodePtr != NULL) {
        struct stringNode* temp = nodePtr;
        if(i == 1) {
            nodePtr = nodePtr->next;
            s = nodePtr;
            delete temp;
        }
        else {
            trailing->next = nodePtr->next;
            nodePtr = nodePtr->next;
            delete temp;
        }
        j++;
    }
    return s;
}

void concatenate(struct stringNode* s1, struct stringNode* s2) {
    struct stringNode* nodePtr = s1;
    while(nodePtr->next != NULL) {
        nodePtr = nodePtr->next;
    }
    struct stringNode* copyPtr = s2;
    while(copyPtr != NULL) {
        struct stringNode* newNode = new stringNode;
        newNode->letter = copyPtr->letter;
        nodePtr->next = newNode;
        nodePtr = nodePtr->next;
        copyPtr = copyPtr->next;
    }
    nodePtr->next = NULL;
}

void append(struct stringNode* s, char c) {
    struct stringNode* curr = s;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    struct stringNode* newNode = new stringNode;
    newNode->letter = c;
    newNode->next = NULL;
    curr->next = newNode;
}

char characterAt(struct stringNode* s, int index) {
    struct stringNode* curr = s;
    int i = 0;
    while(curr != NULL) {
        if(i == index) {
            return curr->letter;
        }
        curr = curr->next;
        i++;
    }
    return 0;
}

struct stringNode* createListFromString(char *s, int stringSize) {
    struct stringNode* head = new stringNode;
    head->letter = s[0];
    struct stringNode* curr;
    curr = head;
    for(int i = 1; i < stringSize; i++) {
        struct stringNode* next = new stringNode;
        next->letter = s[i];
        curr->next = next;
        curr = next;
    }
    curr->next = NULL;
    return head;
}

void printString(struct stringNode *s) {
    struct stringNode* curr = s;
    while(curr != NULL) {
        cout << curr->letter;
        curr = curr->next;
    }
}