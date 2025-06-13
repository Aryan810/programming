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

int main(){

    oset<int> a;
    a.insert(3499);
    a.insert(324);
    a.insert(434);
    cout << a.order_of_key(3498) << endl;
    return 0;
}