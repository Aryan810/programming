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

vector< vector<int> > v;

void generate(vector<int> & out, vector<int> & nums, int i){
    if (i == nums.size()){
        v.push_back(out);
    }
    if (i < nums.size()){
        generate(out, nums, i+1);
        out.push_back(nums[i]);
        generate(out, nums, i+1);
        out.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vi a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    vi out;
    generate(out, a, 0);
    

    return 0;
}