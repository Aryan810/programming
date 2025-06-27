// #include<atcoder/modint>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int>>
#define vv(x) vector<vector<x>>
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve()
{

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> out(n, vector<char>(m, '.'));
    vector<char> hor = {'a', 'b', 'c'};
    vector<char> v1 = {'d', 'e'};
    vector<char> v2 = {'f', 'g', 'h'};
    vector<char> v3 = {'i', 'j', 'k'};
    vector<char> v5 = {'n', 'o', 'p'};
    vector<char> v7 = {'s', 't', 'u'};
    vector<char> v4 = {'l', 'm'};
    vector<char> v6 = {'q', 'r'};
    if ((n + 1) & 1)
    {
        if ((k + 1) & 1 && k <= (n * (m / 2)))
        {
            int left = k;
            int curr = 0;
            int j;
            for (j = 0; j < m; j += 2)
            {
                int i;
                for (i = 0; i < n; i++)
                {
                    if (left <= 0)
                    {
                        break;
                    }
                    if ((j / 2) & 1)
                    {
                        out[i][j] = hor[curr % 3];
                        out[i][j + 1] = hor[curr % 3];
                    }
                    else
                    {
                        out[i][j] = v5[curr % 3];
                        out[i][j + 1] = v5[curr % 3];
                    }
                    curr += 1;
                    left -= 1;
                }
            }
            for (int j=0;j<m;j++){
                int i = 0;
                int now = 0;
                while (i < n && out[i][j]!='.'){
                    i += 1;
                }
                if (j&1){
                    for (;i<n;i+=2){
                        out[i][j] = v7[now%3];
                        out[i+1][j] = v7[now%3];
                        now += 1;
                    }
                }else{
                    for (;i<n;i+=2){
                        out[i][j] = v3[now%3];
                        out[i+1][j] = v3[now%3];
                        now += 1;
                    }
                }
            }
            cout << "YES" << endl;
            each(row, out)
            {
                each(val, row)
                {
                    cout << val;
                }
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
        return;
    }
    int left = k;

    if ((m / 2) & 1)
    {
        if (k & 1 && (k >= m / 2 && k <= (n * (m / 2))))
        {
            int now = 0;
            for (int i = 0; i < m; i += 2)
            {
                out[0][i] = v1[(now) % 2];
                out[0][i + 1] = v1[(now) % 2];
                now += 1;
                left -= 1;
            }
            now = 0;
            int j;
            for (j = 0; j < m; j += 2)
            {
                int i = 1;
                if (left > 0)
                {
                    for (i = 1; i < n && left > 0; i += 2)
                    {
                        if ((j / 2) & 1)
                        {
                            out[i][j] = hor[(now) % 3];
                            out[i][j + 1] = hor[(now) % 3];
                            out[i + 1][j] = (hor[(now + 1) % 3]);
                            out[i + 1][j + 1] = (hor[(now + 1) % 3]);
                        }
                        else
                        {
                            out[i][j] = v2[(now) % 3];
                            out[i][j + 1] = v2[(now) % 3];
                            out[i + 1][j] = (v2[(now + 1) % 3]);
                            out[i + 1][j + 1] = (v2[(now + 1) % 3]);
                        }
                        left -= 2;
                        now += 2;
                    }
                }
            }


            for (int j=0;j<m;j++){
                int i = 0;
                int now = 0;
                while (i < n && out[i][j]!='.'){
                    i += 1;
                }
                if (j&1){
                    for (;i<n;i+=2){
                        out[i][j] = v7[now%3];
                        out[i+1][j] = v7[now%3];
                        now += 1;
                    }
                }else{
                    for (;i<n;i+=2){
                        out[i][j] = v3[now%3];
                        out[i+1][j] = v3[now%3];
                        now += 1;
                    }
                }
            }
            
            cout << "YES" << endl;
            each(row, out)
            {
                each(val, row)
                {
                    cout << val;
                }
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        if ((k + 1) & 1 && (k >= m / 2 && k <= (n * (m / 2))))
        {
            int now = 0;
            for (int i = 0; i < m; i += 2)
            {
                out[0][i] = v5[(now) % 3];
                out[0][i + 1] = v5[(now) % 3];
                now += 1;
                left -= 1;
            }
            now = 0;
            int j;
            for (j = 0; j < m; j += 2)
            {
                int i = 1;
                if (left > 0)
                {
                    for (i = 1; i < n && left > 0; i += 2)
                    {
                        if ((j / 2) & 1)
                        {
                            out[i][j] = hor[(now) % 3];
                            out[i][j + 1] = hor[(now) % 3];
                            out[i + 1][j] = (hor[(now + 1) % 3]);
                            out[i + 1][j + 1] = (hor[(now + 1) % 3]);
                        }
                        else
                        {
                            out[i][j] = v2[(now) % 3];
                            out[i][j + 1] = v2[(now) % 3];
                            out[i + 1][j] = (v2[(now + 1) % 3]);
                            out[i + 1][j + 1] = (v2[(now + 1) % 3]);
                        }
                        left -= 2;
                        now += 2;
                    }
                }
                
            }
            
            for (int j=0;j<m;j++){
                int i = 0;
                int now = 0;
                while (i < n && out[i][j]!='.'){
                    i += 1;
                }
                if (j&1){
                    for (;i<n;i+=2){
                        out[i][j] = v7[now%3];
                        out[i+1][j] = v7[now%3];
                        now += 1;
                    }
                }else{
                    for (;i<n;i+=2){
                        out[i][j] = v3[now%3];
                        out[i+1][j] = v3[now%3];
                        now += 1;
                    }
                }
            }
            cout << "YES" << endl;
            each(row, out)
            {
                each(val, row)
                {
                    cout << val;
                }
                cout << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

signed main()
{
    fast_io;
    // mint::set_mod(M);
    int test;
    cin >> test;

    while (test--)
    {
        solve();
    }

    return 0;
}