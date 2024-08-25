#include <iostream>
#include <vector>

using namespace std;

template <class t>
void display(vector <t> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << "element at "<<i<<" is: "<< v.at(i)<<endl;
    }
    
}

int main(){
    vector <int> vec1; // zero length vectors
    int element, size;
    // cout << "Please enter size of the vector: " << endl;
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter an element to add to this vector: ";
    //     cin >> element;
    //     vec1.push_back(element);
    // }
    vector <char> vec2(4);
    vector <char> vec3(vec2);
    vector <int> v(1, 3);
    // display(vec3);
    vector <int> vec4(4, 0);
    // display(vec4);
    // vec4.swap(v);
    // display(vec4);
    // cout << v.max_size();
    display(v);
    cout << v.capacity();

    // display(vec1);
    // vector <int> :: iterator iter = vec1.begin();
    // iter += size;
    // vector <int> :: iterator iter1 = vec1.begin();
    // vec1.insert(iter+1, 5, 234);
    // cout << endl;
    // vec1.erase(iter1, iter);
    // display(vec1);
    // cout << endl << vec1[0];


    return 0;
}