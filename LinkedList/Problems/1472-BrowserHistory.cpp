
// LeetCode 1472 : Design Browser History

/*


// Step 1 : create Node class
class Node {
public:
    string data;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class BrowserHistory {
public:
    // Step 2 : create current node for tracking
    Node* current = NULL;

    BrowserHistory(string homepage) {
        // this is constructor called only once
        current = new Node();
        current->data = homepage;
    }

    void visit(string url) {
        Node* newTab = new Node();
        newTab->data = url;
        current->next = newTab;
        newTab->prev = current;
        current = newTab;
    }

    string back(int steps) {
        while (steps--) {
            if (current->prev != NULL) {
                current = current->prev;
            } else {
                break;
            }
        }

        return current->data;
    }

    string forward(int steps) {
        while (steps--) {
            if (current->next != NULL) {
                current = current->next;
            } else {
                break;
            }
        }
        return current->data;
    }
};




 */