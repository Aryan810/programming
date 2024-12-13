#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

bool comp1(pair<int, int> a, pair<int, int> b){
    return (a.first < b.first);
}
bool comp2(pair<int, int> a, pair<int, int> b){
    return (a.second < b.second);
}
bool comp3(pair<int, int> a, pair<int, int> b){
    return (a.second > b.second);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<pair<int, int> > a(3);
    for (int i=0;i<3;i++){
        int x, y;cin >> x >> y;
        a[i] = {x, y};
    }

    sort(a.begin(), a.end(), comp1);
    auto b = a;
    sort(b.begin(), b.end(), comp2);
    auto c = a;
    sort(c.begin(), c.end(), comp3);
    if (a == b || a == c){
        cout << 3 << endl;
        cout << b[0].first << " " << b[0].second << " " << b[0].first << " " << b[1].second << endl;
        cout << b[0].first << " " << b[1].second << " " << b[2].first << " " << b[1].second << endl;
        cout << b[2].first << " " << b[1].second << " " << b[2].first << " " << b[2].second << endl;
    }else{
        // if in terms of x ->
        auto p = a[0];
        auto q = a[2];
        auto m = a[1];
        cout << 4 << endl;
        if (m.second >= q.second){
            if (q.second >= p.second){
                cout << p.first << " " << p.second << " " << p.first << " " << q.second << endl;
                cout << p.first << " " << q.second << " " << m.first << " " << q.second << endl;
                cout << m.first << " " << q.second << " " << m.first << " " << m.second << endl;
                cout << m.first << " " << q.second << " " << q.first << " " << q.second << endl;
            }else{
                cout << q.first << " " << q.second << " " << q.first << " " << p.second << endl;
                cout << q.first << " " << p.second << " " << m.first << " " << p.second << endl;
                cout << m.first << " " << p.second << " " << m.first << " " << m.second << endl;
                cout << m.first << " " << p.second << " " << p.first << " " << p.second << endl;
            }
        }else{
            if (q.second >= p.second){
                cout << q.first << " " << q.second << " " << m.first << " " << q.second << endl;
                cout << m.first << " " << q.second << " " << m.first << " " << p.second << endl;
                cout << m.first << " " << p.second << " " << p.first << " " << p.second << endl;
                cout << m.first << " " << p.second << " " << m.first << " " << m.second << endl;
            }else{
                cout << p.first << " " << p.second << " " << m.first << " " << p.second << endl;
                cout << m.first << " " << p.second << " " << m.first << " " << q.second << endl;
                cout << m.first << " " << q.second << " " << q.first << " " << q.second << endl;
                cout << m.first << " " << q.second << " " << m.first << " " << m.second << endl;
            }
        }
    }

    return 0;
}