#include <iostream>

using namespace std;

int main(){

    for (int i = 0; i < 10; i++)
    {   
        if (i == 7){
            cout << "neglecting as got i = 7"<<endl;
            continue;
        }
        cout << i<< endl;
    }
    

    return 0;
}