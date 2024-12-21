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

void solve(){
    ll n, k;cin >> n >> k;
    if (k&2 != 0 || k > (n*n)/2){
        cout << "NO" << endl;
        return;
    }
    vector<ll> p(n);
    for (int i=1;i<=n;i++){
        p[i-1] = i;
    }

    ll pos = k/2;
    int i=1,j=n;
    while (pos > 0){
        if (pos > j-i){
            pos -= j-i;
            swap(p[i-1], p[j-1]);
            i++;
            j--;
        }else{
            swap(p[i-1], p[i-1+pos]);
            pos = 0;
            break;
        }
    }
    ofstream out;
    out.open("output.txt");
    out << "YES" << endl;
    for (int i=0;i<n;i++){
        out << p[i] << " ";
    }out << endl;
    out.close();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}