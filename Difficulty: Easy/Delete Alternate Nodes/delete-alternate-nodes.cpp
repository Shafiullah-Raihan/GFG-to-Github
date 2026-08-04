/*
Structure of the node of the binary tree
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        int data = x;
        next = NULL;
    }
};
*/
// Complete this function
class Solution {
  public:
    void deleteAlt(struct Node *head) {
        // Code here
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        
        Node* temp = head->next;
        head->next = temp->next;
        delete temp;
        
        deleteAlt(head->next);
    }
};