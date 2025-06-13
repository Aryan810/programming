#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    
    int A = 65;
    int a = 97;
    set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    // v.insert('a');
    string ns;

    for (int i=0;i<s.size();i++){
        if (v.find(s[i]) == v.end()){
            ns.push_back('.');
            if (int(s[i]) - A <= 25 && int(s[i]) - A >= 0){
                ns.push_back(char(a + int(s[i]) - A));
            }else{
                ns.push_back(s[i]);
            }
        }
    }
    cout << ns << endl;


    return 0;
}