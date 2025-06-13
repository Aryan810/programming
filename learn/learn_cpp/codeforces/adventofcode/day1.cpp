#include <bits/stdc++.h>
#include <fstream>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("day1inp.txt");

    vi a(1000);
    vi b(1000);

    for (int i=0;i<1000;i++){
        inp >> a[i] >> b[i];
    }
    // sort(a.begin(), a.end());
    // sort(b.begin(), b.end());
    // ll sum = 0;
    // for (int i=0;i<1000;i++){
    //     sum += abs(a[i]-b[i]);
    // }
    // cout << sum << endl;

    // part 2
    unordered_map <int, int> m;
    for (int i=0;i<b.size();i++){
        m[b[i]] += 1;
    }

    ll ans = 0;
    for (int i=0;i<a.size();i++){
        ans += a[i]*(m[a[i]]);
    }
    cout << ans << endl;

    inp.close();

    

    return 0;
}