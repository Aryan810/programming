#include <iostream>

using namespace std;

// this queue is made with worst case complexity of insersion as O(n).

// class Queue{
//     int size;
//     int * arr;
//     int last;
//     public:
//         Queue(int max_size){
//             this->size = max_size;
//             this->arr = new int(max_size);
//             this->last = -1;
//         }
        
//         int getMaxSize(){return size;}

//         int getSize(){return last+1;}

//         int push_back(int item){
//             if (last < size-1){
//                 this->arr[++last] = item;
//                 return 1;
//             }else{
//                 return 0;
//             }
//         }

//         int getFirst(){
//             if (last != -1){
//                 return arr[0];
//             }else{
//                 cout << "queue is empty!" << endl;
//                 return -1;
//             }
//         }

//         int peek(int index=0){
//             // if index == -1 : it means that you want the last element
//             if (index > last){
//                 cout << "index must not be greater than " + to_string(last) + " !" << endl;
//                 return -1;
//             }else if(index < 0){
//                 // cout << "yes" << endl;
//                 index = index*(-1);
//                 index = index%(last+1);
//                 // cout << index << endl;
//                 if (index == 0){
//                     index = (last+1);
//                 }
//                 return this->arr[last - (index) + 1];
//             }else{
//                 return this->arr[index];
//             }
//         }

//         int pop(){
//             if (last != -1){
//                 for (int i=0;i<(last);i++){
//                     arr[i] = arr[i+1];
//                 }
//                 last -= 1;
//                 size -= 1;
//                 return 1;
//             }else{
//                 return 0;
//             }
//         }

//         void show(){
//             for (int i=0;i<(last+1);i++){
//                 cout << this->arr[i] << endl;
//             }
//             if (last == -1){
//                 cout << "EMPTY!" << endl;
//             }
//             cout << endl;
//         }

//         // int setSize(int size){
//         //     if (size < this->size){

//         //     }
//         // }


// };

class Queue{
    int size;
    int * arr;
    int f, l;
    int used_size;
    public:
        Queue(int max_size){
            this->size = max_size;
            this->arr = new int(max_size);
            this->l = -1;
            this->f = -1;
            this->used_size = 0;
        }
        
        int getMaxSize(){return size;}

        int getSize(){return used_size;}

        void status(){
            cout << "f: " << f << ", l: " << l << endl;
        }

        int enqueue(int item){
            if (used_size < size){
                if (l == size-1){
                    l = -1;
                }
                this->arr[++l] = item;
                used_size += 1;

                return 1;
            }
            return 0;
        }

        int getFirst(){
            if (used_size != 0){
                if (this->f == size-1){
                    return this->arr[0];
                }
                return this->arr[this->f + 1];
            }
            cout << "Empty Queue!" << endl;
            return -1;
        }

        // int peek(int index=0){
        //     // if index == -1 : it means that you want the last element
        //     if (index > last){
        //         cout << "index must not be greater than " + to_string(last) + " !" << endl;
        //         return -1;
        //     }else if(index < 0){
        //         // cout << "yes" << endl;
        //         index = index*(-1);
        //         index = index%(last+1);
        //         // cout << index << endl;
        //         if (index == 0){
        //             index = (last+1);
        //         }
        //         return this->arr[last - (index) + 1];
        //     }else{
        //         return this->arr[index];
        //     }
        // }

        int deque(){
            if (used_size != 0){
                if (this->f >= size-1){
                    this->f = 0;
                }else{
                this->f += 1;
                }
                used_size -= 1;
                return 1;
            }
            return 0;
            // if (last != -1){
            //     for (int i=0;i<(last);i++){
            //         arr[i] = arr[i+1];
            //     }
            //     last -= 1;
            //     size -= 1;
            //     return 1;
            // }else{
            //     return 0;
            // }
        }

        void show(){
            int temp = this->f;
            while (temp != this->l){
                if (temp >= this->size-1){
                    temp = -1;
                }
                cout << this->arr[temp++ + 1] << endl;
            }
            cout << endl;
        }

        // int setSize(int size){
        //     if (size < this->size){

        //     }
        // }


};


int main(){
    Queue q(4);
    q.enqueue(34);
    q.enqueue(87);
    q.enqueue(12);
    q.enqueue(24);
    q.show();
    q.deque();
    q.show();
    cout << q.getSize() << endl;
    q.status();
    q.enqueue(191);
    q.status();

    cout << q.getSize() << endl;

    // q.show();
    // q.enqueue()




    return 0;
}