/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
     Node* findIntersection(Node* head1, Node* head2) {
        Node *p1 = head1, *p2 = head2;
        Node *head = nullptr, *tail = nullptr;

        while (p1 && p2) {
            if (p1->data > p2->data) {
                p2 = p2->next;
            }
            else if (p2->data > p1->data) {
                p1 = p1->next;
            }
            else {
                if (head == nullptr) {
                    head = tail = new Node(p1->data);
                } else {
                    tail->next = new Node(p1->data);
                    tail = tail->next;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        return head;
    }
};