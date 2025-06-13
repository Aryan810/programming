#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




class Solution {
public:
    
    vector<string> valid;

void generate(int open, int closing, string & out){
    cout << out << endl;
    if (open == 0 && closing == 0){
        valid.push_back(out);
        return;
    }
    if (open > 0){
        out.push_back('(');
        generate(open-1, closing, out);
        out.pop_back();
    }
    if (closing > 0){
        if (open < closing){
            out.push_back(')');
            generate(open, closing-1, out);
            out.pop_back();
        }
    }
}
    vector<string> generateParenthesis(int n) {
        string out;
        generate(n, n, out);
        return valid;
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    Solution a;
    vector<string> v = a.generateParenthesis(n);
    for (int i=0;i<v.size();i++){
        cout << v[i] << endl;
    }

    return 0;
}