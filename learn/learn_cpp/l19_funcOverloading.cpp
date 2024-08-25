#include <iostream>

using namespace std;

// for volume of cylinder.
double volume(double r, int h){
    return (3.14*r*r*h);
}

// volume of cube.
int volume(int l, int b, int h){
    return (l*b*h);
}

// volume of sphere
double volume(double r){
    return (4/3)*(3.14)*(r*r*r);
}

int main(){
    cout << "vol. of cube: "<< volume(12, 12, 12)<<endl;
    cout << "vol. of cylinder: "<< volume(8.9, 11)<<endl;
    cout << "vol. of sphere: "<< volume(2.89)<<endl;
    

    return 0;
}