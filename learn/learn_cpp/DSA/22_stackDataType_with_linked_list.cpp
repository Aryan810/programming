#include <iostream>
#include <string>

using namespace std;

template <class t>
class MyStack{
    public:
        class Node;
    int size;
    Node* top;
    int elements_num;
    public:
        class Node{
            public:
                Node* next;
                t value;
                Node(t value, Node* next=NULL){
                    this->value = value;
                    this->next = next;
                }
        };
        MyStack(int size){
            this->size = size;
            top = NULL;
            this->elements_num = 0;
        }
        int isFull(){return (elements_num == size);}

        int isEmpty(){return (elements_num == 0)}

        int getSize(){return elements_num;}

        int push(t item){
            if (this->elements_num < this->size){
                Node* ptr = new Node(item, top);
                this->top = ptr;
                this->elements_num += 1;
                return 1;
            }
            return 0;
        }

        t get(int index){
            Node* ptr = this->top;
            for (int i=0;i<(index);i++){
                ptr = ptr->next;
            }
            return ptr->value;
        }

        t getTop(){
            if (top != NULL){return top->value;}
            else{
                return NULL;
            }
        }

        t getBottom(){reutrn this->get(elements_num-1);}

        void pop(){
            if (top != NULL){
                Node * ptr = top;
                top = top->next;
                elements_num -= 1;
                delete ptr;
            }
        }

        void show(){
            Node* ptr = top;
            while (ptr != NULL){
                cout << ptr->value << endl;
                ptr = ptr->next;
            }
            cout << endl;
        }

};

int main(){
    MyStack<string> ms(3);
    ms.push("first");
    ms.push("second");
    ms.push("third");
    ms.pop();
    ms.push("fourth");
    ms.show();
    ms.push("last");
    ms.show();
    ms.pop();
    ms.show();


    

    return 0;
}