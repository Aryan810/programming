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
        string s;
        cin >> s;
        stack <int> capital;
        stack <int> lower;
        set<int> to_rem;
        for (int i=0;i<s.size();i++){
            if (s[i] >= 65 && s[i] <= 90){
                if (s[i] == 'B'){
                    if (!capital.empty()){
                        to_rem.insert(capital.top());
                        capital.pop();
                    }
                    // to_rem.insert(i);
                }else{
                    capital.push(i);
                }
            }else{
                if (s[i] == 'b'){
                    if (!lower.empty()){
                        to_rem.insert(lower.top());
                        lower.pop();
                    }
                }else{
                    lower.push(i);
                }
            }
        }
        string ans;
        // cout << 1 << endl;
        for (int i=0;i<s.size();i++){
            // cout << i << endl;
            if (to_rem.size() != 0 && i == *(to_rem.begin())){
                to_rem.erase(to_rem.begin());
                continue;
            }else if(!(s[i] == 'b' || s[i] == 'B')){
                ans.push_back(s[i]);
                // cout << ans << endl;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}