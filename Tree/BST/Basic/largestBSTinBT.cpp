// Largest bst in binary tree

#include <iostream>
#include <limits.h>
using namespace std;

class NodeData
{
public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData()
    {
    }

    NodeData(int size, int max, int min, bool valid)
    {
        this->size = size;
        minVal = min;
        maxVal = max;
        validBST = valid;
    }
};

class Node
{
public:
    Node *left;
    Node *right;
    int data;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

NodeData *findLargestBST(Node *root, int &ans)
{
    // base case
    if (root == NULL)
    {
        NodeData *temp = new NodeData(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData *leftKaAns = findLargestBST(root->left, ans); // going left until NULL ,then hit base case
    NodeData *rightKaAns = findLargestBST(root->right, ans);

    // checking starts here
    NodeData *currNodeKaAns = new NodeData();

    currNodeKaAns->size = leftKaAns->size + rightKaAns->size + 1;
    currNodeKaAns->maxVal = max(root->data, rightKaAns->maxVal);
    currNodeKaAns->minVal = min(root->data, leftKaAns->minVal);

    if (leftKaAns->validBST && rightKaAns->validBST && (root->data > leftKaAns->maxVal) && (root->data < rightKaAns->minVal))
    {
        currNodeKaAns->validBST = true;
    }
    else
    {
        currNodeKaAns->validBST = false;
    }

    if (currNodeKaAns->validBST)
    {
        ans = max(ans, currNodeKaAns->size);
    }

    return currNodeKaAns;
}
