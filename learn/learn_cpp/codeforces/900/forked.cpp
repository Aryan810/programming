#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

// bool comp(pair<int, int> p1, pair<int, int> p2){
//     return (p1.first == p2.first && p1.second == p2.second);
// }

void add(set<pair<int, int> >& s, pair<int, int>& p, int a, int b){
    // 1
    pair<int, int> x;
    x.first = p.first + a;

    x.second = p.second + b;


    s.insert(x);
    x.first = p.first + a;
    x.second = p.second - b;
    s.insert(x);

    x.first = p.first - a;
    x.second = p.second + b;
    s.insert(x);
    x.first = p.first - a;
    x.second = p.second - b;
    s.insert(x);

    // 2

    x.first = p.first + b;
    x.second = p.second + a;
    s.insert(x);
    x.first = p.first + b;
    x.second = p.second - a;
    s.insert(x);

    x.first = p.first - b;
    x.second = p.second + a;
    s.insert(x);
    x.first = p.first - b;
    x.second = p.second - a;
    s.insert(x);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        pair<int, int> k;
        cin >> k.first >> k.second;
        pair<int, int> q;
        cin >> q.first >> q.second;

        set<pair<int, int> > ks, qs, v;
        set<pair<int, int> >::iterator it;


        //king
        add(ks, k, a, b);

        // queen
        add(qs, q, a, b);

        set_intersection(ks.begin(), ks.end(), qs.begin(), qs.end(), inserter(v, v.begin()));

        cout << v.size() << endl;
    }

    return 0;
}