#include <iostream>

using namespace std;


class Stack{
    int size;
    int* arr;
    int top;
    public:
        Stack(int size){
            this->top = -1;
            this->size = size;
            this->arr = new int(this->size);
        }

        int getSize(){
            return size;
        }

        int push(int value){
            if (this->top == (this->size-1)){
                return 0;
            }else{
                arr[++top] = value;
                return 1;
            }
        }

        int getElementsNum(){return top+1;}

        void setSize(int size){
            if (size > this->size){
                // this->size = size;
                int * narr = new int(size);
                for (int i=0;i<this->size;i++){
                    narr[i] = this->arr[i];

                }
                int * temp = this->arr;
                this->arr = narr;
                for (int i=0;i<this->size;i++){
                    delete (temp + i);
                }
                this->size = size;
                
            }else if (size == this->size){}
            else{
                // top = size - 1;
                // for (int i=0;i<(top + 1 - size);i++){
                //     cout << "YES " << top << " " << i << endl;
                //     // delete (this->arr + (top - i));
                //     delete (this->arr + (top - i));
                //     cout << "YES " << top << " " << *this->arr << endl;

                // }
                // top = size - 1;
                // this->size = size;

                int * narr = new int(size);
                for (int i=0;i<size;i++){
                    narr[i] = this->arr[i];
                }
                delete this->arr;
                this->size = size;
                top = (size - 1);

            }

        }

        // returns elements at given index. top element is on '0' index.
        int peek(int index=0){
            if (index > top){
                throw "out of range! max. index = " + to_string(top);
            }
            else if (index < 0){
                throw "index must be > 0";
            }else{
                return arr[top - index];
            }
        }

        int getTop(){return this->arr[this->top];}

        int getBottom(){
            if (top != -1){return this->arr[0];}
            return -1;
        }

        void pop(){
            if (top != -1){
                top -= 1;
            }
        }

        int isEmpty(){
            return (top == -1);
        }

        int isFull(){
            return (top == size-1);
        }

        void show(){
            for (int i=0;i<(top+1);i++){
                cout << arr[top - i] << endl;
            }
            cout << endl;
        }

};

int main(){
    Stack s(5);
    s.pop();
    // s.push(123);
    // s.push(567);
    // s.push(57);
    // s.push(67);
    // s.pop();
    // s.pop();
    // s.pop();
    // s.pop();
    // s.push(7);
    // s.push(37);
    // s.push(71);
    // // s.pop();
    // s.show();
    // cout << s.getElementsNum() << endl;
    // s.push(908);
    // s.show();
    // cout << s.getElementsNum() << endl;
    // s.push(4538);
    // s.show();
    // cout << s.getElementsNum() << endl;
    // cout << s.isEmpty(); // 2 elements.
    // s.pop();
    // s.pop();
    // cout << s.isEmpty(); // 0 elements.

    // s.setSize(1);
    // s.show();


    
    

    return 0;
}