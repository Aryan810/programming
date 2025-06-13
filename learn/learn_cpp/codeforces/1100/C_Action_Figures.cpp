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

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        string go;
        cin >> go;
        lli cost = 0ll;
        int fzero = go.find('0');
        if (fzero >= go.size()){fzero = go.size();}
        queue<int> q;
        for (int i=n-1;i>=fzero;i--){
            if (go[i]-48 == 0){
                if (q.empty()){
                }else{
                    q.pop();
                }
                cost += i+1;
            }else{
                q.push(i+1);
            }
        }
        vector<int> left(fzero + q.size());
        for (int i=0;i<fzero;i++){
            left[i] = i+1;
        }
        int x = q.size();
        int i = 1;
        while (!q.empty()){
            left[fzero + x - i] = q.front();
            q.pop();
            i++;
        }
        for (int i=0;i<(int)ceil(left.size()/(double)2);i++){
            cost += left[i];
        }
        cout << cost << endl;
    }

    return 0;
}