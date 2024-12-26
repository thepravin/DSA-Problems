#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList
{
private:
    int size = 0;

public:
    Node *head;
    Node *tail;

    void addAtHead(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void addAtTail(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    int length()
    {
        return size;
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{

    LinkedList *ll = new LinkedList();
    ll->addAtHead(15);
    ll->addAtHead(16);
    ll->addAtHead(17);
    ll->addAtTail(14);
    ll->addAtTail(13);

    ll->print();

    cout << endl;
    cout << "Length : " << ll->length() << endl;

    return 0;
}