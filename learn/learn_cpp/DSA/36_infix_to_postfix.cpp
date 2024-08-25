#include <iostream>
#include <string>
#include <map>

using namespace std;

template <class t>
class Stack{
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
        Stack(int size){
            this->size = size;
            top = NULL;
            this->elements_num = 0;
        }
        int isFull(){return (elements_num == size);}

        int isEmpty(){return (elements_num == 0);}

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
            if (top != NULL){return top->value;}else{
                throw "Empty Stack!";
            }
        }

        t getBottom(){return this->get(elements_num-1);}

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

    string infix, postfix;
    cout << "Enter your string: ";
    cin >> infix;
    cout << endl;

    map <char, int> prec;
    prec['-'] = 1;
    prec['+'] = 1;
    prec['*'] = 2;
    prec['/'] = 2;


    Stack<char> st(infix.length());
    for (int i=0;i<infix.length();i++){
        // st.show();
        if (prec.find(infix[i]) != prec.end()){
            if (st.getSize() != 0){
                if (prec[st.getTop()] >= prec[infix[i]]){
                    while(prec[st.getTop()] >= prec[infix[i]]){
                        postfix += st.getTop();
                        st.pop();
                        if (st.getSize() == 0){break;}
                    }

                    st.push(infix[i]);
                }else{
                    st.push(infix[i]);
                }
            }else{
                st.push(infix[i]);
            }
        }else{
            postfix += (infix[i]);
        }
    }
    while (!st.isEmpty()){
        postfix += st.getTop();
        st.pop();
    }
    cout << "postfix: " << postfix << endl;


    return 0;
}