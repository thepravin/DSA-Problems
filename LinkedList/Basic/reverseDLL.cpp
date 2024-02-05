

/* /

Approach 1 : Using Stack

Approach 2 : pointer arrangment


 */

/* Approach 2 :

Node* reverseDLL(Node* head)
{   
    // Write your code here 
    if(head==NULL || head->next == NULL)  {
        return head;
    }

    Node*last=nullptr;
    Node*curr = head;
    while(curr != NULL){
        // curr ka prev last node ko point karega
        last = curr->prev;
        
        // curr ka prev curr ke next ko point karega
        curr->prev = curr->next;

        //curr ka next last ko point karega
        curr->next = last;

        // update curr
        curr = curr->prev;

    }

   
    return last->prev;
} */