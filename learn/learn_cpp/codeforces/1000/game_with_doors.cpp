// #include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int l, r, L, R;
        cin >> l >> r >> L >> R;
        int min_doors = 0;
        vector<int> s1, s2, s;
        for (int i=l;i<=r;i++){
            s1.push_back(i);
        }
        for (int i=L;i<=R;i++){
            s2.push_back(i);
        }
        // cout << "INSIDE" << endl;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(s));
        // cout << "OUTSIDE" << endl;

        min_doors = s.size() + 1;
        if (R == r){min_doors -= 1;}
        if (L == l){min_doors -= 1;}
        cout << min_doors << endl;

    }

    return 0;
}