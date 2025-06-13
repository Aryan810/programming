#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#define lli long long int
using namespace std;

int no_of_first_1s(string s){
    int n=0;
    for (int i=0;i<s.length();i++){
        if (s.at(i) == '0'){
            break;
        }
        n += 1;
    }
    return n;
} 
int is_all_ones(string s){
    int size = int(sqrt(s.length()));
    for (int i=0;i<size;i++){
        if ((s[i] == '0') || (s[s.length()-1-i] == '0')){
            return 0;
        }
    }
    return 1;
}
int is_correct_in_between(string s){
    int a = int(sqrt(s.length()));
    vector<string> parts(0);
    for (int i=0;i<=(s.length()-a);i+=a){
        // cout << "substr: " << s.substr(i, a) << endl;
        parts.push_back(s.substr(i, a));
    }
    // cout << "size: " << parts.size() << endl;
    for (int i=1; i<(parts.size()-2);i++){
        if (parts[i] != parts[i+1]){
            // cout << parts[i] << " " << parts[i+1] << endl;
            return 0;
        }
    }
    return 1;
}
int is_all_equal(vector<int> & nums){
    int a = nums[0];
    for (int i=0;i<nums.size();i++){
        if (nums[i] != a){
            return 0;
        }
    }
    return 1;
}

int main(){
    // vector<int> v;
    // // v.push_back(9);
    // // v.push_back(6);
    // // sort(v.begin(), v.end());
    // // cout << v[0] << endl;
    // // v.erase(v.begin(), v.end());
    // v.insert(v.end(), 2);
    // v.insert(v.end(), 2);
    // cout << is_all_equal(v);

    // string str = "1002";
    // string s = str.substr(0, 2);
    // cout << s << endl;
    // int k = 10;
    // for(int i=0;i<k;i++){
    //     if (i==2){
    //         k = 0;
    //     }
    //     cout << i << endl;
    // }

    // cout << ((2%2)==0) << endl;
    // map<char, int> m;
    // m['A'] = 20;
    // m['B'] = 89;
    // m['C'] = 0;
    // m['?'] = 0;
    // cout << m.begin();

    // cout << float(5)/3;
    // string s = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
    // cout <<int(sqrt(199809))<<endl;
    // cout << sizeof(int) << endl;
    // cout << ceil(4.5);
    // long long int a;
    // a = 1;
    // cout << a << endl;

    // map<long long int, long long int> milk;
    // milk[0] += 6;
    // cout << milk[0] << endl;
    // cout << to_string(2);
    // char a, b;
    // cin >> a >> b;
    // cout << a << " " << b;
    // lli a = 900;
    // string s = to_string(1ll+(lli)(pow(10, a-1ll)));
    // cout << s << endl;
    // for (int i=1;i<=a-2;i++){
    //     cout << s.substr(a*i, a) << endl;
    // }
    set<pair<int, int> > s;
    pair<int, int> p(1, 42);
    pair<int, int> p1(1, 42);
    cout << (p==p1) << endl;
    return 0;
}