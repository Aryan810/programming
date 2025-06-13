#include <iostream>
#include <vector>
#define lli long long int

using namespace std;

vector<bool>::iterator iter(int i, vector<bool>& data){
    return (data.begin()+i);
}

int main(){
    
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        
        // LET UP(U) == 1, DOWN(D)==0
        vector<bool> data(n);
        for (int i=0;i<n;i++){
            char c;
            cin >> c;
            data[i] = (c == 'U')?1:0;
        }
        bool alice = 1;
        bool done = 0;
        while (!done){
            vector<bool>::iterator prev, nxt;
            n = data.size();
            bool found = 0;
            // if (data.size() == 1){
                    // cout << "N====1" << endl;
            //  }
            for (vector<bool>::iterator i=data.begin();i!=data.end();i++){
                prev = (i == data.begin())?(data.end()-1):(i-1);
                nxt = (i == data.end()-1)?(data.begin()):(i+1);
                if (*i){
                    if (n >= 2){
                        *prev = (*prev)?0:1;
                        *nxt = (*nxt)?0:1;
                        found = 1;
                        alice = (alice)?0:1;
                        data.erase(i);
                        break;
                    }else{
                        data.erase(i);
                        found = 1;
                        alice = (alice)?0:1;
                        break;
                    }
                    
                }

            }
            // cout << "N: " << data.size() << endl;
            // cout << "A: " << alice << endl;

            if (!found){
                done = 1;
            }
        }
        // cout << "N!: " << data.size() << endl;
        cout << ((alice)?"NO":"YES") << endl;

    }

    return 0;
}   