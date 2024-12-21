#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ifstream inp;
    inp.open("input.txt");
    ofstream out;
    out.open("output.txt");
    int mx=101, my=103;
    vector< pair< pair<int, int> , pair<int, int> > > ipos;
    while (1){
        string s;
        getline(inp, s);
        if (s == ""){break;}
        int i = 2;
        cout << s << endl;
        pair<int, int> p, v;
        string temp;
        while ((s[i] >= '0' && s[i] <= '9')){
            temp.push_back(s[i]);
            i += 1;
        }
        p.first = stoi(temp);
        i += 1;
        temp = "";
        while (s[i] >= '0' && s[i] <= '9'){
            temp.push_back(s[i]);
            i += 1;
        }
        i += 3;
        p.second = stoi(temp);
        temp = "";
        while (s[i] >= '0' && s[i] <= '9' || s[i] == '-'){
            temp.push_back(s[i]);
            i += 1;

        }
        i += 1;
        v.first = stoi(temp);
        temp = "";
        while (i<s.size() && s[i] >= '0' && s[i] <= '9' || s[i] == '-'){
            temp.push_back(s[i]);
            i += 1;
        }
        v.second = stoi(temp);
        ipos.push_back({p, v});
    }

    for (int ii=6400;ii<=6800;ii++){
        vector< pair<int, int> > final_pos;
        for (auto aa: ipos){
            auto p = aa.first;
            auto v = aa.second;
            int fx = p.first + ii*v.first;
            int fy = p.second + ii*v.second;
            if (fx < 0){
                if (fx%mx == 0){
                    fx = 0;
                }else{
                    fx = fx%mx + mx;
                }
            }else{
                fx = fx%mx;
            }

            if (fy < 0){
                if (fy%my == 0){
                    fy = 0;
                }else{
                    fy = fy%my + my;
                }
            }else{
                fy = fy%my;
            }
            cout << fx << " " << fy << endl;
            final_pos.push_back({fx, fy});
        }

        out << ii << endl;
        out << endl;

        for (int jj=0;jj<my;jj++){
            for (int kk=0;kk<mx;kk++){
                if (find(final_pos.begin(), final_pos.end(), make_pair(kk, jj)) != final_pos.end()){
                    out << "0";
                }else{
                    out << ".";
                }
            }out << endl;
        }
        out << endl;

    }
    // ll q1 = 0;
    // ll q2=0, q3=0, q4=0;
    // int mxh=(mx-1)/2, myh=(my-1)/2;
    // for (auto p: final_pos){
    //     if (p.first < mxh && p.second < myh){
    //         q1 += 1;
    //     }else if (p.first < mxh && p.second > myh){
    //         q4 += 1;
    //     }else if(p.first > mxh && p.second > myh){
    //         q3 += 1;
    //     }else if (p.first > mxh && p.second < myh){
    //         q2 += 1;
    //     }
    // }
    // cout << (q1*q2*q3*q4) << endl;


    // inp.close();
    out.close();
    return 0;
}