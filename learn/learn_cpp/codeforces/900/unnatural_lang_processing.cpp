#include <iostream>
#include <vector>
#include <set>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

bool in(set<char>& a, char b){
    return (a.find(b) != a.end());
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        set<char> v;
        v.insert('a');
        v.insert('e');
        set<char> c;
        c.insert('b');
        c.insert('c');
        c.insert('d');
        string s;
        cin >> s;
        bool start = 0;
        for (int i=0;i<s.size()-2;){
            if ((i+3 < s.size())&&in(c, s[i])){
                if ((in(v, s[i+3]))){
                    s.insert(s.begin()+i+2, '.');
                    i+=3;
                }else{
                    s.insert(s.begin()+i+3, '.');
                    i+=4;
                }
            }else{
                i+=1;
            }

            // if(in(c, s[i])){
            //     if (in(v, s[i+1])){
            //         if (i+3 < n){
            //             if (in(v, s[i+3])){
            //                 if (i+2 != n-1){
            //                     s.insert(s.begin()+i+2, '.');
            //                 }
            //                 i += 3;
            //             }else{
            //                 i += 2;
            //             }
            //         }
            //     }else{
            //         s.insert(s.begin()+i+1, '.');
            //         i+=2;
            //     }
            // }else{
            //     i+=1;
            // }
        }
        cout << s << endl;

    }

    return 0;
}