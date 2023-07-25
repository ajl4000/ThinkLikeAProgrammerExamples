#include <iostream>

struct treeNode
{
    int data;
    treeNode* left;
    treeNode* right;
};
typedef treeNode* treePtr;

bool isTreeHeapRecursive(treePtr curr, int headData)
{
    if(curr == NULL)
    {
        return false;
    }
    int nodeData = curr->data;
    std::cout << "current head: " << curr->data << std::endl;
    if(nodeData <= headData) return isTreeHeapRecursive(curr->left, nodeData) || isTreeHeapRecursive(curr->right, nodeData);
    return true;
}

bool isTreeHeap(treePtr head)
{
    return !isTreeHeapRecursive(head, head->data);
}

int main()
{
    treePtr right22 = new treeNode;
    right22->data = 1;
    right22->left = NULL;
    right22->right = NULL;
    treePtr left22 = new treeNode;
    left22->data = 5;
    left22->left = NULL;
    left22->right = NULL;
    treePtr right21 = new treeNode;
    right21->data = 6;
    right21->left = NULL;
    right21->right = NULL;
    treePtr left21 = new treeNode;
    left21->data = 6;
    left21->left = NULL;
    left21->right = NULL;
    treePtr right1 = new treeNode;
    right1->data = 15;
    right1->left = left21;
    right1->right = right21;
    treePtr left1 = new treeNode;
    left1->data = 14;
    left1->left = left22;
    left1->right = right22;
    treePtr head = new treeNode;
    head->data = 27;
    head->left = left1;
    head->right = right1;

    std::cout << isTreeHeap(head);

    return 1;
}