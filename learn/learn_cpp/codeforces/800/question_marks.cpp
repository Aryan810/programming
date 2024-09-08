#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){

    int t, n;
    int marks = 0;
    cin >> t;
    vector<char> v(4);
    v[0] = 'A';
    v[1] = 'B';
    v[2] = 'C';
    v[3] = 'D';

    for (int i=0;i<t;i++){
        cin >> n;
        string inp;
        cin >> inp;

        map<char, int> m;
        
        m['A'] = 0;
        m['B'] = 0;
        m['C'] = 0;
        m['D'] = 0;
        m['?'] = 0;
        for (int j=0;j<(4*n);j++){
            m[inp[j]] += 1;
        }
        marks = 0;
        for (int j=0; j<v.size();j++){
            if (m[v[j]] > n){
                marks += n;
            }else{
                marks += m[v[j]];
            }
        }
        cout << marks << endl;

    }

    return 0;
}