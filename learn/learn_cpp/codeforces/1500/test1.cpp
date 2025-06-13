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
        vector <pair<int,int>> v;
        for(int i=1;i<=n;i++) {
            int x;
            cin>>x;
            v.push_back({x,i});
        }
        sort(v.begin(),v.end());
        vector <pair<int,int>> v_ans;
        while(v.size()>=2) {
            int x=min(v[v.size()-1].first,v[v.size()-2].first);
            for(int i=1;i<=x;i++) {
                v_ans.push_back({v[v.size()-1].second,v[v.size()-2].second});
            }
            v[v.size()-1].first-=x;
            v[v.size()-2].first-=x;
            if(v[v.size()-1].first==0) {
                v.erase(v.begin()+v.size()-1);
            }
            if(v[v.size()-2].first==0) {
                v.erase(v.begin()+v.size()-2);
            }
        }

        cout<<v_ans.size()<<endl;
        for(int i=0;i<v_ans.size();i++) {
            cout<<v_ans[i].first<<" "<<v_ans[i].second<<endl;
        }
    }
    return 0;
}