// sort 0 1 2

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

void sortZeroOneTwo(Node *&head)
{
    // Step 1 : count
    int zeros = 0;
    int ones = 0;
    int twos = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zeros++;
        else if (temp->data == 1)
            ones++;
        else if (temp->data == 2)
            twos++;

        temp = temp->next;
    }

    // Step 2 : Print in original LL
    temp = head;
    while (zeros--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (ones--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (twos--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

Node* withoutCounting(Node*& head){
    // creating doumy nodes
    Node* zerosHead = new Node(-1);
    Node* zerosTail = zerosHead;

    Node* onesHead = new Node(-1);
    Node* oneTail = onesHead;

    Node* twosHead = new Node(-1);
    Node* twosTail = twosHead;

    // travel the original LL
    Node* curr = head;
    while (curr != NULL)
    {
        if (curr->data==0)
        {
            // take out the zero wali nodes
            Node* temp =curr;
            curr = curr->next;
            temp->next=NULL;
            // append the zeros node in zerosHead LL
            zerosTail->next = temp;
            zerosTail=temp;
        }
        else if (curr->data==1)
        {
            // take out the one wali nodes
            Node* temp =curr;
            curr = curr->next;
            temp->next=NULL;
            // append the one node in oneHead LL
            oneTail->next = temp;
            oneTail=temp;
        }
        else if (curr->data==2)
        {
            // take out the two wali nodes
            Node* temp =curr;
            curr = curr->next;
            temp->next=NULL;
            // append the two node in twoHead LL
            twosTail->next = temp;
            twosTail=temp;
        }
        
    }
  // yha pr, zero,one,two teeno LL readyv h

  //join them
  // remove dummy nodes

  // modify one wali list
  Node* temp = onesHead;
  onesHead = onesHead->next;
  temp->next=NULL;
  delete temp;

  // modify two wali list
  temp = twosHead;
  twosHead = twosHead->next;
  temp->next=NULL;
  delete temp;

  // join list
   if (onesHead != NULL)
   {
        // one wali list is non empty
        zerosTail->next = onesHead;
        if (twosHead != NULL)
        {
            oneTail->next = twosHead;
        }
        
   }else{
    //one wali list is empty
    if (twosHead !=NULL)
    {
        zerosTail->next = twosHead;
    }
    
   }
   // remove zerohead dummy node
   temp=zerosHead;
   zerosHead = zerosHead->next;
   temp->next = NULL;

   return zerosHead;
    

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

    Node *head = new Node(1);
    Node *second = new Node(1);
    Node *third = new Node(2);
    Node *fourth = new Node(2);
    Node *fifth = new Node(2);
    Node *six = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    print(head);
    cout << endl;

    // using counting
    // sortZeroOneTwo(head);
    // print(head);

    // without counting
   head= withoutCounting(head);
    print(head);


    return 0;
}