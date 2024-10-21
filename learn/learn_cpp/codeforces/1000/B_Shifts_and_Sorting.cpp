#include <iostream>
#include <list>
#include <vector>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;
list<int> v;
lli logic(list<int> & s){
    auto fo = s.begin();
    auto lz = s.begin();
    lli cost = 0;
    int ones = 0;
    while (!(fo == s.end() && lz == s.end())){
        if (*fo == 0 && *lz == 0){
            fo++;
            lz++;
        }
        if (*fo == 1 && *lz == 1){
            while (*lz != 0){
                lz++;
                if(lz == s.end()){return cost;}
                ones+=1;
            }
            int zeros = 0;
            while (*lz!=1){
                s.erase(lz++);
                zeros += 1;
                if (lz == s.end()){break;}
            }
            fo = lz;
            cost += (ones+1ll)*zeros*1ll;
        }
        // cout << 1 << endl;
    }
    return cost;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        string s;
        cin >> s;
        v.clear();
        for (int i=0;i<s.size();i++){
            v.push_back(int(s[i])-48);
        }
        cout << logic(v) << endl;
        v.clear();
    }

    return 0;
}