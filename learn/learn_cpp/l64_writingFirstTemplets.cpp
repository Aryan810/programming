#include <iostream>

using namespace std;

template <class T>

class Vector{
    public:
        T *arr;
        int size;
        Vector(int m){
            size = m;
            arr = new T[size];
        }
        T dot(Vector &v){
            T d = 0;
            if (size <= v.size){
                for (int i = 0; i < size; i++)
                {
                    d += (this->arr[i]) * v.arr[i];
                }
            }else{
                for (int i = 0; i < v.size; i++)
                {
                    d += (this->arr[i]) * v.arr[i];
                }
            }
            return d;
        }
};

int main(){
    // Vector v1(3);
    // Vector v2(1);
    // v1.arr[0] = 1;
    // v1.arr[1] = 2;
    // v1.arr[2] = 3;

    // v2.arr[0] = 3;
    // v2.arr[1] = 2;
    // v2.arr[2] = 1;

    // cout << v1.dot(v2);

    Vector <float> v1(3);
    Vector <float> v2(3);
    v1.arr[0] = 1.5;
    v1.arr[1] = 2.5;
    v1.arr[2] = 3.5;

    v2.arr[0] = 3.03;
    v2.arr[1] = 2.34;
    v2.arr[2] = 1.34;

    cout << v1.dot(v2);
 

    
    

    return 0;
}