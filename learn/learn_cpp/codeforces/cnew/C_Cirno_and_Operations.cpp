#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector <ll> a(n);
        for(auto &i:a) {
            cin>>i;
        }
        if(a.size()==1) {
            cout<<a[0]<<endl;
            continue;
        }
        ll sum=accumulate(a.begin(),a.end(),0ll);
        while(a.size()>1) {
            vector <ll> v;
            ll temp;
            for(int i=0;i<a.size()-1;i++) {
                v.push_back(a[i+1]-a[i]);
            }
            sum=max<ll>(sum,abs(accumulate(v.begin(),v.end(),0ll)));
            a=v;
        }
        sum=max<ll>(sum,abs(a[0]));
        cout<<sum<<endl;
    }
    return 0;
}