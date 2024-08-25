#include <iostream>
#include <string>

using namespace std;

template <class t>
class Node{
    public:
        t value;
        Node* next;
        Node(t value, Node* next=NULL){
            this->value = value;
            if (next == NULL){
                this->next = this;
            }else{
                this->next = next;
            }
        }
        Node(){}
        void show(Node* head){
            Node* ptr = head;
            while (ptr->next != head){
                cout << ptr->value << endl;
                ptr = ptr->next;
            }
            cout << ptr->value << endl;
            cout << endl;
        }
        Node* addAfter(t value){
            Node* ptr = new Node(value, this->next);
            this->next = ptr;
            return ptr;
        }
        Node* addAtBeginning(t value){
            Node* ptr = new Node(value, this);
            Node* temp = this;
            while (temp->next != this){
                temp = temp->next;
            }
            temp->next = ptr;
            return ptr;
        }
        Node* addAtEnd(t item){
            Node* ptr = this;
            while (ptr->next != this){
                ptr = ptr->next;
            }
            return ptr->addAfter(item);
        }
        Node* nodeAtDistance(int distance){
            Node* ptr = this;
            for (int i=0;i<distance;i++){
                ptr = ptr->next;
            }
            return ptr;
        }
        Node* insertAtDistance(int distance, t value){
            Node* ptr = this;
            for (int i=0;i<distance-1;i++){
                ptr = ptr->next;
            }

            ptr->next = new Node(value, ptr->next);
            return ptr->next;
        }

        void removeAtDistance(int distance, Node* & head){
            Node* ptr = this;
            if (distance == 0){
                Node * ptr = this;
                while(ptr->next != this){
                    ptr = ptr->next;
                }
                ptr->next = this->next; // last node pointed to second node.
                ptr = head;             // now 'ptr' is pointed to first(head) node.
                head = this->next;      // the stack pointer of head is shifted from first to second element.
                delete ptr;             // 'ptr' is pointed to old first (head) node and here we delete it or free its memory from heap;
            }else{
                for (int i=0;i<distance-1;i++){
                    ptr = ptr->next;
                }
                Node* temp = ptr->next;
                if (temp == this){
                    removeAtDistance(0, head);
                }else{
                ptr->next = ptr->next->next;
                delete temp;
                }
            }
        }
        void pop_back(){
            Node* ptr = this;
            while (ptr->next->next != this){
                ptr = ptr->next;
            }
            Node* temp = ptr->next;
            ptr->next = this;
            delete temp;
        }

        void deleteFirstNodeWithValue(t value, Node* &head){
            Node* ptr = this;
            int i = 0;
            bool found = true;
            while (ptr->value != value){
                ptr = ptr->next;
                if (ptr->next == this){
                    found = false;
                    break;
                }
                i += 1;
            }
            if (found){
                removeAtDistance(i, head);
            }else{
                cout << endl << "value <" << value << "> not found!" << endl;
            }

        }

};

int main(){
    Node<string> * head = new Node<string>("head 1");
    head->addAfter("node 1");
    head->addAfter("node 2");
    head->addAfter("node 3");
    head->show(head);

    head->pop_back();
    head->show(head);

    // head->insertAtDistance(3, "inserted at 3");
    // head->show(head);

    // head->insertAtDistance(5, "inserted at 5 *");
    // head->show(head);
    
    // head->insertAtDistance(5, "inserted at 5 after node 3");
    // head->show(head);

    head->insertAtDistance(9, "inserted at 9 after node 2");
    head->show(head);

    // head->removeAtDistance(0, head);
    // head->removeAtDistance(4, head);
    // head->show(head);

    head->deleteFirstNodeWithValue("node 2", head);
    head->show(head);
    return 0;
}