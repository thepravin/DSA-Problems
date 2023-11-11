// https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem

// Get value of kth node form tail

// Find middle node

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// ************************************************

// method 1 => iteratively
int lengthofLL(Node *&head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int getNode(Node *llist, int positionFromTail)
{

    int length = lengthofLL(llist);

    int destiPosition = length - positionFromTail - 1;
    int count = 0;

    Node *ansNode = llist;
    while (count < destiPosition)
    {

        count++;
        ansNode = ansNode->next;
    }

    return ansNode->data;
}

// method 2 => recursion

void fun(Node *&head, int &positionFromTail, int &ans)
{
    // base case
    if (head == NULL)
    {
        return;
    }

    fun(head->next, positionFromTail, ans);
    if (positionFromTail == 0)
    {
        ans = head->data;
    }
    positionFromTail--;
}

int getNode2(Node *llist, int positionFromTail)
{
    int ans = 0;
    fun(llist, positionFromTail, ans);
    return ans;
}

// *********************************************

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    Node *head = new Node(3);
    Node *second = new Node(2);
    Node *third = new Node(1);
    Node *fourth = new Node(0);
    // Node *fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = NULL;

    print(head);
    cout << endl;

    cout << getNode(head, 2) << endl;
    cout << getNode2(head, 2) << endl;

    return 0;
}