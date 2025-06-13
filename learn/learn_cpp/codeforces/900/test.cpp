#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

int main(){

    // vector<int> v(3);
    // v[0] = 1;
    // v[1] = 55;
    // v[2] = 191;
    // v.erase(v.begin()+1);
    // cout << v[1] << endl;
    
    // cout << accumulate(a.begin(), a.end()-2, 0) << endl;
    // vector<int> a(7);
    // a[0] = 1;
    // a[1] = 2;
    // a[2] = 3;
    // a[3] = 4;
    // a[4] = 4;
    // a[5] = 7;
    // a[6] = 699;
    // sort(a.begin(), a.end());
    // int l=2 , r=4;
    // cout << (lower_bound(a.begin(), a.end(), l)-a.begin()) << endl;
    // cout << (upper_bound(a.begin(), a.end(), r)-a.begin()) << endl;
    // vector<int> a(3);
    // a[0] = 2;
    // a[1] = 2;
    // a[2] = 9;
    // // cout << (lower_bound(a.begin(), a.end(), 0) - a.begin()) << endl;
    // vector<int>::iterator i = a.begin()+2;
    // a.erase(a.begin()+1);
    // int t = 4;
    // while(t--){
    //     char c;
    //     cin >> c;
    //     cout << c << endl;
    // }
    // vector<bool> a(5);
    // a[0] = 1;
    // a[1] = 1;
    // a[2] = 0;
    // a[3] = 1;
    // a[4] = 0;

    // vector<bool>::iterator d=a.begin(), b=d+1, c=a.end()-1;
    // cout << "B: " << (b-a.begin()) << endl;
    // a.erase(d);
    // cout << "B: " << (b-a.begin()) << endl;

    // *b = (*b)?0:1;
    // *c = (*c)?0:1;

    // for (int i=0;i<a.size();i++){
    //     cout << a[i] << endl;
    // }

    // cout << int('0') << endl;
    // int x = 97;
    // map<char, int> a;
    // a[(char)x] += 5;
    // (a.find((char)x)->second) += 1;
    // cout << (a.find((char)x)->second) << endl;

    // set<int> s;
    // s.insert(242);
    // s.insert(34);
    // cout << (s.find(34)-s.begin()) << endl;

    // vector< pair<int, int> > v = {{1, 2}, {3, 4}, {3, 90}};
    // cout << v.size() << endl;

    int a = 5;
    int b = 9;
    int c = 4;
    cout << (a^b^c) << endl;

    return 0;
}