#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    vector<int> pos;
    pos.push_back(a+b+c);
    pos.push_back(a*b*c);
    pos.push_back(a*b + c);
    pos.push_back(a+ b*c);
    pos.push_back(a*(b+c));
    pos.push_back((a+b)*c);
    cout << *max_element(pos.begin(), pos.end()) << endl;
    return 0;
}