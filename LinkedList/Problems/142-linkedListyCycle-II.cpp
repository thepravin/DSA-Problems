// leetcode : 142 

ListNode *detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;

        // Step 1: loop present check
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                // Step 2: Cycle detected, move slow to head
                slow = head;

                // Step 3: Find the cycle's starting point
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        // No cycle found
        return NULL;
    }