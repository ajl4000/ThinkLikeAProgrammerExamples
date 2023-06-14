#include <iostream>

using namespace std;

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
    printString(head);
    cout << '\n';
    cout << characterAt(head, 4) << '\n';
    append(head, '!');
    printString(head);

    return 1;
}

void concatenate(struct stringNode* s1, struct stringNode* s2) {
    struct stringNode* curr1 = s1;
    while(curr1->next != NULL) {
        curr1 = curr1->next;
    }

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