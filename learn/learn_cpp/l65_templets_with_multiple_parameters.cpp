#include <iostream>
#include <string>


using namespace std;

template <class t1>
class print{
    t1 data;
    public:
        print(t1 info){
            data = info;
        }
        void show(){
            cout << data << endl;
        }
};

int main(){
    print <float> prt(2424.2424f);
    prt.show();

    return 0;
}