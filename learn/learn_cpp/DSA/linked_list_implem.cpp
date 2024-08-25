#include <iostream>
#include <string>

using namespace std;

template <class t>
class Node{
    public:
        t value;
        Node* next;
        Node(t value, Node* next = NULL){
            this->value = value;
            this->next = next;
        }
        Node(){}
        void show(Node* head){
            cout << endl;
            Node* ptr = head;
            while (ptr->next != NULL){
                cout << ptr->value << endl;
                ptr = ptr->next;
            }
            cout << endl;
        }
        Node* addAfter(t value){
            Node* ptr = new Node(value, this->next);
            next = ptr;
            return ptr;
        }
        Node* addAtBeginning(t value){
            return new Node(value, this);
        }
        Node* addAtEnd(t item){
            Node* ptr = this;
            while (ptr->next != NULL){
                ptr = ptr->next;
            }
            return ptr->addAfter(item);
        }
        Node* nodeAtDistance(int distance){
            Node* ptr = this;
            for (int i=0;i<distance;i++){
                if (ptr->next == NULL){
                    return new Node();
                }
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
                Node * ptr = head;
                head = head->next;
                delete ptr;
            }else{
                for (int i=0;i<distance-1;i++){
                    ptr = ptr->next;
                }
                Node* temp = ptr->next;
                ptr->next = ptr->next->next;
                delete temp;
            }
        }
        void pop_back(){
            Node* ptr = this;
            while (ptr->next->next != NULL){
                ptr = ptr->next;
            }
            Node* temp = ptr->next;
            ptr->next = NULL;
            delete temp;
        }

        void deleteFirstNodeWithValue(t value, Node* &head){
            Node* ptr = this;
            int i = 0;
            bool found = true;
            while (ptr->value != value){
                ptr = ptr->next;
                if (ptr->next == NULL){
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
    Node<string>* head = new Node<string>("first");
    head->addAfter("second");
    head->addAtEnd("third");
    head->addAfter("fourth");
    // cout << head->nodeAtDistance(1)->value<<endl;
    // cout << head->nodeAtDistance(2)->value<<endl;
    // cout << head->nodeAtDistance(3)->value<<endl;
    head->insertAtDistance(2, "inserted at 2: 535");
    head->insertAtDistance(4, "inserted at 4: 7");
    // cout << head->nodeAtDistance(0)->value << endl;
    head->removeAtDistance(0, head);
    // cout << head->nodeAtDistance(0)->value << endl;
    // cout << head->nodeAtDistance(2)->value << endl;
    // cout << head->nodeAtDistance(3)->value << endl;
    head->show(head);
    head->pop_back();
    head->show(head);
    // cout << head->nodeAtDistance(3)->value << endl;
    head->deleteFirstNodeWithValue("second", head);
    head->deleteFirstNodeWithValue("fourth", head);
    head->show(head);
    head->addAfter("aryan mahan");
    head->show(head);
    head->deleteFirstNodeWithValue("aryan hero", head);
    head->show(head);
    // cout << head->nodeAtDistance(0)->value << endl;
    // cout << head->nodeAtDistance(1)->value << endl;
    // cout << "." << head->nodeAtDistance(2)->value << "." << endl;




    return 0;
}