// LeetCode - 138 Copy with Random Pointr LL
#include<iostream>
using namespace std;

// Approach 1
/*

    Node* helper(Node*head,unordered_map<Node*,Node*>&mp){
        if(head==0) return head;

        // creating new LL , mapping with old LL
        Node* newHead = new Node(head->val);
        mp[head]=newHead ; // oldHead -> newHead  //S.C=O(n)
        newHead->next=helper(head->next,mp);     //T.C = O(n)

        // adjuct random pointers
        if(head->random){
            newHead->random = mp[head->random];
        }
            return newHead;

    }


    Node* copyRandomList(Node* head) {
        if(head==0) return head;

        unordered_map<Node*,Node*> mp;

        return helper(head,mp);

    }

    */


/*


class Solution {
public:
    // Approach 2 - Without map

    Node* helper(Node*head){
        if(!head) return head;

        // Step 1 : Clone oldNode -> newNode
        Node* it = head; //iterate old head 
        while(it){
            Node* cloneNode = new Node(it->val);
            cloneNode->next = it->next;
            it->next = cloneNode;
            it=it->next->next;
        }

        // Step 2 : Assign random links 
        it = head;
        while(it){
            Node*cloneNode = it->next;
            cloneNode->random = it->random ? it->random->next : nullptr;
            it=it->next->next;
        }

        // Step 3 : Detach
        it=head;
        Node* cloneHead = it->next;
        while(it){
            Node* cloneNode = it->next;
            it->next = it->next->next;
            if(cloneNode->next){
                cloneNode->next = cloneNode->next->next;
            }
            it=it->next;
        }
        return cloneHead;

    }

    Node* copyRandomList(Node* head) {
        if(!head) return head;

        return helper(head);
    }
};


*/