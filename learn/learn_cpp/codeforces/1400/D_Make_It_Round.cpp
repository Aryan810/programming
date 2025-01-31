#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;
    int p2=0, p5=0;
    int n1 = n;
    while (n1%10 == 0){
        n1 /= 10;
    }
    while (n1%2 == 0){
        n1 /= 2;
        p2 += 1;
    }
    while (n1%5 == 0){
        n1 /= 5;
        p5 += 1;
    }
    swap(p2, p5);
    if (p2 == 0 && p5 == 0){
        if (m < 10){
            cout << n*m << endl;return;
        }else{
            string s = to_string(m);
            cout << binexpiter(10, s.size()-1)*(s[0]-'0')*n << endl;
        }
    }else if (p2 == 0){
        int x = binexpiter(5, p5);
        if (m >= x){
            int y = 1;
            while (m >= x*y*10){
                y *= 10;
            }
            int best = (m/(x*y))*(x*y);
            cout << n*best << endl;return;
        }else{
            int y = 1;
            while (m < x/y){
                y *= 5;
            }
            int best = (m/(x/y))*(x/y);
            cout << n*best << endl;return;
        }
    }else{
        int x = binexpiter(2, p2);
        if (m >= x){
            int y = 1;
            while (m >= x*y*10){
                y *= 10;
            }
            int best = (m/(x*y))*(x*y);
            cout << n*best << endl;return;
        }else{
            int y = 1;
            while (m < x/y){
                y *= 2;
            }
            int best = (m/(x/y))*(x/y);
            cout << n*best << endl;return;
        }
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}