// #include<atcoder/modint>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

int helper(int i, int state, vector<vector<int>> &grid, vector<vector<int>> &dp, int &n)
{
    // cout << i << " " << state << endl; 
    if (i == n - 1)
    {
        if (!grid[0][i] && !grid[1][i])
        {
            if (state == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (!grid[0][i])
        {
            if (state == 2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (!grid[1][i])
        {
            if (state == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (state == 0 || state == 3)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else if (i >= n)
    {
        return 0;
    }
    if (dp[i][state] != -1)
    {
        return dp[i][state];
    }

    int ret = 0;
    if (!grid[0][i] && !grid[1][i])
    {
        switch (state)
        {
        case 0:
            ret += helper(i+1, 0, grid, dp, n);
            break;
        default:
            break;
        }
    }
    else if (!grid[0][i])
    {
        switch (state)
        {
        case 0:
            ret += helper(i+1, 2, grid, dp, n);
            break;
        case 2:
            ret += helper(i+1, 0, grid, dp, n);
            break;
        default:
            break;
        }
    }
    else if (!grid[1][i])
    {
        switch (state)
        {
        case 0:
            ret += helper(i+1, 1, grid, dp, n);
            break;
        case 1:
            ret += helper(i+1, 0, grid, dp, n);
            break;
        default:
            break;
        }
    }
    else
    {
        switch (state)
        {
        case 0:
            ret += helper(i+1, 3, grid, dp, n);
            ret += helper(i+1, 0, grid, dp, n);
            break;
        case 1:
            ret += helper(i+1, 2, grid, dp, n);
            break;
        case 2:
            ret += helper(i+1, 1, grid, dp, n);
            break;
        case 3:
            ret += helper(i+1, 0, grid, dp, n);
            break;
        default:
            break;
        }
    }
    if (ret > 1){
        ret = 2;
    }
    return dp[i][state] = ret;
}

void solve()
{

    int n;
    cin >> n;

    vector<vector<int>> grid(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == '.')
            {
                grid[i][j] = 1;
            }
            else
            {
                grid[i][j] = 0;
            }
        }
    }

    vector<vector<int>> dp(n, vector<int>(4, -1));
    int ret = helper(0, 0, grid, dp, n);
    if (ret == 0){
        cout << "None" << endl;
    }else if (ret == 1){
        cout << "Unique" << endl;
    }else{
        cout << "Multiple" << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while (test--)
    {
        solve();
    }

    return 0;
}