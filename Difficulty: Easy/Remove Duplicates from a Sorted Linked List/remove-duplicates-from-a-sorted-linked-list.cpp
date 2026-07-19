/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {

        Node* current = head;

        while (current->next != nullptr) {

            if (current->data == current->next->data) {
                Node* next_next = current->next->next;
                Node* temp = current->next;
                current->next = next_next;
                delete (temp);
            }

            else
                current = current->next;
        }
        return head;
    }
};