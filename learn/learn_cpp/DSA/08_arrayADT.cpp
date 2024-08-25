#include <iostream>
#include <vector>
#include <string>

using namespace std;

class myArray{
    int total_size;
    int used_size;
    int* ptr;
    
    void add(int index, int item){
        int* temp;
        if (total_size > used_size){
            temp = new int(total_size);
            used_size += 1;
        }else{
            temp = new int(total_size+1);
            used_size += 1;
            total_size += 1;
        }
        temp[index] = item;
        for (int i = 0; i < used_size-1; i++)
        {
            if (i < index){
                temp[i] = ptr[i];
            }else if(i >= index){
                temp[i+1] = ptr[i];
            }
        }
        ptr = temp;
    }
    public:
        void set(int i, int item){
        if (used_size >= (i+1))
            *(ptr+i) = item;
        else{
            this->insert(used_size, item);
        }
        }
        int tSize(){
            return total_size;
        }
        int uSize(){
            return used_size;
        }
        myArray(int tSize){
            total_size = tSize;
            used_size = 0;
            ptr = new int(tSize);
        }
        int get(int i){
            return *(ptr + i);
        }
        void show(){
            for (int i = 0; i < this->used_size; i++)
            {
                cout << this->get(i) << " ";
            }
            cout << endl;
        }
        void insert(int index, int item){
            if (total_size <= used_size){
                this->add(index, item);
            }else{
                for (int i=1;i<(used_size-index+1);i++){
                    ptr[used_size-i+1] = ptr[used_size-i];
                }
                ptr[index] = item;
                used_size += 1;
            }
        }

        void remove(int index){
            for (int i=(index+1);i < (used_size);i++){
                ptr[i-1] = ptr[i];
            }
            used_size -= 1;
            // int* temp = new int(used_size-1);
            // for (int i = 0; i < used_size; i++)
            // {
            //     if (i < index){
            //         temp[i] = ptr[i];
            //     }else if(i > index){
            //         temp[i-1] = ptr[i];
            //     }
            // }
            // used_size -= 1;
            // ptr = temp;
        }
};


int main(){
    myArray marks(9);
    marks.set(0, 12);
    marks.set(1, 223);
    marks.set(2, 1132);
    marks.show();
    marks.insert(1, 892);
    cout << marks.uSize() << " " << marks.tSize() << endl;
    marks.show();
    marks.remove(1);
    marks.show();
    marks.remove(0);
    marks.show();
    marks.remove(1);
    marks.show();
    cout << marks.uSize() << " " << marks.tSize() << endl;
    // marks.set(7, 52);
    // marks.show();
    // cout << marks.uSize() << " " << marks.tSize() << endl;
    // marks.remove(marks.uSize()-1);
    // marks.show();
    // cout << marks.uSize() << " " << marks.tSize() << endl;
    // marks.insert(2, 1132);
    // cout << marks.uSize() << " " << marks.tSize() << endl;

    // marks.insert(2, 1132);
    // cout << marks.uSize() << " " << marks.tSize() << endl;

    // marks.insert(2, 1132);
    // cout << marks.uSize() << " " << marks.tSize() << endl;

    // marks.insert(2, 1132);
    // cout << marks.uSize() << " " << marks.tSize() << endl;

    // marks.insert(2, 1132);
    // marks.show();
    // cout << marks.uSize() << " " << marks.tSize() << endl;
    // marks.insert(2, 1132);
    //   marks.show();
    // cout << marks.uSize() << " " << marks.tSize() << endl;

    return 0;
}