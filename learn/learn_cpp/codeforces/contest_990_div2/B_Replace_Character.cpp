#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;cin >> n;
        string s;
        cin >> s;
        vector< pair<int, int> > a(26, {0, 0});
        for(int i=0;i<26;i++){
            a[i] = {i, 0};
        }
        for (int i=0;i<n;i++){
            a[s[i]-'a'].second += 1;
        }
        sort(a.begin(), a.end(), comp);
        int mm = 0;
        for (int i=0;i<a.size();i++){
            // cout << a[i].second << endl;
            if (a[i].second > 0){
                mm = a[i].first;
                a[i].second -= 1;
                break;
            }
        }
        (a.end()-1)->second += 1;
        int M = (a.end()-1)->first;
        for (int i=0;i<s.size();i++){
            if (s[i] == 'a'+mm){
                s[i] = 'a'+M;
                break;
            }
        }
        cout << s << endl;
    }

    return 0;
}