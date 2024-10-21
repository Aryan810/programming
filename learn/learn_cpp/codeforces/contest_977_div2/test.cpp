#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> b;
    b.push_back(31);
    b.push_back(31);
    b.push_back(1);
    b.push_back(31);
    
    int gape = (int)(lower_bound(b.begin()+0+1, b.end(), 1)-b.begin())-0;


    return 0;
}