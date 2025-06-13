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
        stack<int> s;
        lli cost = 0;
        for (int i=0;i<n;i++){
            char c;
            cin >> c;
            if (c == '_'){
                if (!s.empty()){
                    cost += i - s.top();
                    s.pop();
                }else{
                    s.push(i);
                }
            }else if(c == '('){
                s.push(i);
            }else{
                cost += i - s.top();
                s.pop();
            }
        }
        cout << cost << endl;
    }

    return 0;
}