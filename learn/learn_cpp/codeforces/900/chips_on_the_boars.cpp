#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vlli a(n);
        vlli b(n);
        lli s1=0ll, s2=0ll;
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> b[i];
        // case 1
        // exustive in 'i' >>
        s1 = ((lli)accumulate(a.begin(), a.end(), 0ll))+((n)*(*min_element(b.begin(), b.end())));

        // case 2
        // exustive in 'j' >>
        s2 = ((lli)accumulate(b.begin(), b.end(), 0ll))+((n)*(*min_element(a.begin(), a.end())));

        cout << ((s1 > s2)?s2:s1) << endl;
    }

    return 0;
}