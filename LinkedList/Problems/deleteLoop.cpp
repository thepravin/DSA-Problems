// Detect and delete loop
// LeetCode : 

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

int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// ************************************************
bool isLoopPresent(Node*&head){
    if (head==NULL)
    {
        return false;
    }

    Node* slow = head;
    Node*fast = head;
    while (fast!=NULL)
    {
        fast = fast->next;
        if (fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }

        if (slow == fast)
        {
            // loop present
            return true;
        }
        
        
    }

    // fast is equal to null
    return false; // no loop
    
    
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

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
   Node *sixth = new Node(60);
   Node *seventh = new Node(70);
   Node *eighth = new Node(80);
   Node *ninth= new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
   sixth->next=seventh;
   seventh->next = eighth;
   eighth->next =ninth;
   ninth->next =eighth;

 
  bool ans = isLoopPresent(head);
  if (ans)
  {
    cout<<"Loop PRESENT"<<endl;
  }else{
    cout<<" No Loop "<<endl;
  }
  
  

    return 0;
}