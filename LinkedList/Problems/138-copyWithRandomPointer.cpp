// LeetCode - 138 Copy with Random Pointr LL


// Approach 1

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