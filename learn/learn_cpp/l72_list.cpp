#include <iostream>
#include <list>

using namespace std;

void display(list<int> &l){
    list<int> :: iterator iter = l.begin();
    for (int i = 0; i < l.size(); i++)
    {
        cout << *iter<<" ";
        iter++;
    }
    cout << endl;
    
}

int main(){

    list<int> lst1;
    lst1.push_back(2);
    lst1.push_back(4);
    lst1.push_back(3);
    lst1.push_back(4);
    lst1.push_back(1);
    // display(lst1);
    
    // Removing functions from the list.

    // lst1.pop_back();
    // lst1.pop_front();
    // lst1.remove(4);

    // lst1.sort();

    // display(lst1);

    list<int> lst2;
    lst2.push_back(7);
    lst2.push_back(5);
    lst2.push_back(9);

    lst1.merge(lst2);
    lst1.sort();
    lst1.reverse();
    // display(lst1);

    list<int> lst3;
    lst3.push_back(7);
    lst3.push_back(5);
    lst3.push_back(9);
    list<int> :: iterator iter = lst3.begin();
    lst3.insert((++iter), 200);
    display(lst3);
    





    return 0;
}