#include <iostream>
#include <string>

using namespace std;

template <class t>
class Node{
    t value;
    Node* next;
    Node* prev;
    public:
        Node (t value, Node* prev=NULL, Node* next=NULL){
            this->value = value;
            this->prev = prev;
            this->next = next;
        }

        Node* addAtHead(t value, Node* & head){
            Node* ptr = new Node(value, NULL, head);
            head -> prev = ptr;
            head = ptr;
            return head;
        }

        Node* addAtIndex(int index, t value, Node* & head){
            Node * ptr = this;
            for (int i=0; i<(index-1); i++){
                if (ptr->next==NULL){
                    break;
                }
                ptr = ptr->next;
            }
            if (index < 1){
                return addAtHead(value, head);
            }else{
            return ptr->addAfter(value);
            }
        }

        Node* addAfter(t value){
            Node * ptr = new Node(value, this, this->next);
            if (this->next != NULL){
                this->next->prev = ptr;
            }
            this->next = ptr;
            return ptr;
        }
        void showRemainingNode(){
            Node * ptr = this;
            do{
                cout << ptr->value << endl;
                ptr = ptr->next;
            }
            while (ptr != NULL);
            cout << endl;
        }

        void show(){
            Node * ptr = this;
            while (ptr->prev != NULL){
                ptr = ptr->prev;
            }
            ptr->showRemainingNode();
        }


};

int main(){
    Node<int> * head = new Node<int>(54);
    head->addAfter(45);
    head->addAfter(32);
    head->addAtIndex(0, 78, head);
    // head->showRemainingNode();
    // cout << head->next;
    head->show();
    

    return 0;
}