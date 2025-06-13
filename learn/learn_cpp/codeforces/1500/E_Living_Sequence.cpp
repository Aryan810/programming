#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

int binexpiter(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int bad_before(int x)
{
    int ans = 0;
    string s = to_string(x);
    for (int i=0;i<s.size();i++){
      int y = s[i]-'0';
      if (y == 4){
        ans += y * binexpiter(9, s.size()-i-1);
        break;
      }else{
        ans += ((y>4)?y-1:y)*binexpiter(9, s.size()-i-1);
      }
    }
    return ans;
}


void solve()
{

    int n;
    cin >> n;

    int low = n;
    int high = 1e18 + 1;
    while (high - low > 1)
    {
        int mid = (high + low) / 2;
        int temp = bad_before(mid);
        // cout << mid << " " << temp << endl;
        // cout << low << " : " << high << endl;
        string s = to_string(mid);
        if (s.find('4') < s.size()){
            if (n < temp){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            continue;
        }
        if (temp > n)
        {
            high = mid - 1;
        }
        else if (temp == n)
        {
            cout << mid << endl;
            return;
        }
        else
        {
            low = mid + 1;
        }
    
    }
    int temp = bad_before(high);
    if (temp == n)
    {
        cout << high << endl;
    }
    else
    {
        cout << low << endl;
    }

}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while (test--)
    {
        solve();
    }

    return 0;
}