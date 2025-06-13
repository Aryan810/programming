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

pair<int, int> givept(int n){
    int x = (sqrt(1 + 8*n) - 1)/2;
    int q = (x*(x+1))/2;
    // cout << x << " " << q << " " << n << endl;
    if (q == n){
        return make_pair(x-1, 0);
    }else{
        return make_pair(n-q-1, x-n+q+1);
    }
}

int numpt(pair<int, int> pt){
    return (pt.first + 1 + ((pt.first + pt.second)*(pt.first + pt.second + 1))/2);
}

void solve(){

    int n;
    cin >> n;

    vi a(n);
    rep(i, n){
        cin >> a[i];
    }
    set<int> unocu;
    for (int i=0;i<n;i++){
        unocu.insert(i+1);
    }
    vector<pair<int, int> > points(4*n);
    set<pair<int, int> > avpts;
    set<pair<int, pair<int, int> > > pts;
    int sm = 1;
    int num = 0;
    while (num < 4*n){
        if (sm%3 == 0){
            sm += 1;
        }
        for (int i=0;i<=sm;i++){
            int x = i;
            int y = sm - i;
            set<pair<int, int> > lpts;
            if (x%3 == 0){
                if ((num < 4*n && x+1 > 0) > 0 && lpts.find({x+1, y}) == lpts.end()){
                    // points[num] = {x+1, y};
                    lpts.insert({x+1, y});
                    // num += 1;
                }
                if ((num < 4*n && x-1 > 0) && lpts.find({x-1, y}) == lpts.end()){
                    // points[num] = {x-1, y};
                    lpts.insert({x-1, y});
                    // num += 1;
                }
            }else if (y%3 == 0){
                if ((num < 4*n && y+1 > 0) && lpts.find({x, y+1}) == lpts.end()){
                    // points[num] = {x, y+1};
                    lpts.insert({x, y+1});
                    // num += 1;
                }
                if ((num < 4*n && y-1 > 0) > 0 && lpts.find({x, y-1}) == lpts.end()){
                    // points[num] = {x, y-1};
                    lpts.insert({x, y-1});
                    // num += 1;
                }
            }
            for (auto ele: lpts){
                if (avpts.find(ele) == avpts.end()){
                    avpts.insert(ele);
                    pts.insert({i, ele});
                    points[num] = ele;
                    num += 1;
                }
            }
        }
        sm += 1;
    }
    
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        pair<int, int> pt;
        if (x == 0){
            pt = givept(*(unocu.begin()));
            avpts.erase({3*pt.first + 1, 3*pt.second + 1});
            unocu.erase(unocu.begin());
            cout << 3*pt.first + 1 << " " << 3*pt.second + 1 << endl;
        }else{
            auto pt1 = pts.begin();
            auto pt2 = avpts.begin();
            while ((pt2 = avpts.find(pt1->second)) == avpts.end()){
                pt1++;
            }

            cout << pt1->second.first << " " << pt1->second.second << endl;
            avpts.erase(pt2);
            pair<int, int> xpt = {pt1->second.first/4, pt1->second.second/4};
            if (unocu.find(numpt(xpt)) != unocu.end()){
                unocu.erase(numpt(xpt));
            }
            pts.erase(pt1);
        }
    }
    // cout << givept(1).first << " " << givept(1).second << endl;


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