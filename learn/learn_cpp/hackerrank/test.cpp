#include <iostream>
#include <vector>

using namespace std;

int main(){
    // vector<int> vec;
    // vec.push_back(2);
    // vector<int> :: iterator iter = vec.begin();
    // *iter = 9;
    // cout << vec.at(0) <<endl<<vec.size();
    int n=0;
    for (int i = 0; i < 4; i++)
    {   cout << i<<endl;
        if (i == 2){
            cout << "Entered!" <<endl;
            i = -1;
            continue;
        }
        n++;
        if (n==10){
            break;
        }
        
    }
    
    

    return 0;
}