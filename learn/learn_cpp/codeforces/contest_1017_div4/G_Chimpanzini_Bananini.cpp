#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct Node{
    int val;
    struct Node * next;
    struct Node * prev;
};
typedef struct Node Node;
void insertR(Node ** it, int val){
    Node * x = (Node *)malloc(sizeof(Node));
    x->val = val;
    x->next = (*it)->next;
    x->prev = *it;
    (*it)->next->prev = x;
    (*it)->next = x;
}

void insertL(Node ** it, int val){
    Node * x = (Node *)malloc(sizeof(Node));
    x->val = val;
    x->next = (*it);
    x->prev = (*it)->prev;
    (*it)->prev->next = x;
    (*it)->prev = x;

}

void solve(){

    int q;
    cin >> q;
    Node * last = (Node *)malloc(sizeof(Node));
    last->next = last;
    last->prev = last;
    bool empty = 1;
    int rizz = 0;
    int n = 0;
    int f = 1;
    int sm = 0;
    for (int i=0;i<q;i++){
        int r;
        cin >> r;
        // cout << "R: " << n << " " << sm << " " << last->val << endl;
        // if (!empty){
        //     cout << "Array: ";
        //     for (int j=0;j<n;j++){
        //         cout << last->val << " ";
        //         last = last->prev;
        //     }cout << endl;
        // }
        if (r == 1 && !empty){
            rizz = rizz + sm - n*(last->val);
            if (f){
                last = last -> prev;
            }else{
                last = last -> next;
            }
        }else if (r == 2 && !empty){
            if (f){
                last = last->next;
            }else{
                last = last->prev;
            }
            if (f){f = 0;}else{f = 1;}
            rizz = (n+1)*sm - rizz;
        }else if (r == 3){
            int val;cin >> val;
            sm += val;
            n += 1;
            if (empty){
                last->val = val;
                empty = 0;
            }else{
                if (f){
                    insertR(&last, val);
                    last = last->next;
                }else{
                    insertL(&last, val);
                    last = last->prev;
                }
            }
            rizz = rizz + n*(last->val);
        }
        cout << rizz << endl;
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}