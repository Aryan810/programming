#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool comp(lli a, lli b){
    return (a > b);
}

bool logic(vlli & arr){
    lli lot = 0ll;
    for (int i=0;i<arr.size();i++){
        if (i == arr.size()-1 && lot == 0ll){
            return 0;
        }
        if (i == 0 && arr[i] == 1ll){
            return 0;
        }
        if (arr[i] == 1ll){
            if (lot > 0ll){
                lot -= 1;
            }else{
                return 0;
            }
        }else{
            lot += arr[i] - 1ll;
        }
        // cout << lot << endl;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<lli> arr(n);
        for (int i=0;i<n;i++) cin >> arr[i];

        sort(arr.begin(), arr.end(), comp);
        // for (int i=0;i<arr.size();i++){
        //     cout << arr[i] << endl;
        // }
        cout << (logic(arr)?"YES":"NO") << endl;
        
    }

    return 0;
}