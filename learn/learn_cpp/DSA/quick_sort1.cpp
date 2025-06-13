#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>::iterator& s, vector<int>::iterator& e){
        int temp = *s;
        *s = *e;
        *e = temp;
}

int getIndex(vector<int>::iterator& s, vector<int>::iterator& item){
    return item-s;
}

void quick_sort(vector<int>::iterator start, vector<int>::iterator end){
    
    vector<int>::iterator i = start+1, j = end;

    while (!(j<=i)){
        if (!(*i > *start)){
            i++;
        }
        if (!(*j <= *start)){
            j--;
        }
        if ((*j <= *start) && (*i > *start)){
            swap(i, j);
        }
    }
    swap(start, j);
    cout << "index: " << getIndex(start, j) << endl;
    if (getIndex(start, j)>1){
        quick_sort(start, j); 
    }
    if ((end-start-getIndex(start, j)-1)>1){
        quick_sort(++j, end);
    }
}

int main(){
    vector<int> v;
    v.push_back(453);
    v.push_back(458);
    v.push_back(364);
    v.push_back(14);
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << endl;
    quick_sort(v.begin(), v.end());
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;

    

    return 0;
}