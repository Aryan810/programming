#include <iostream>
#include <vector>
#define lli long long int

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int last = 0;
        int y=12, x=12;
        for (int i=0;i<n;i++){
            int hashes = 0;
            int index_of_first_hash = 0;
            for (int j=0;j<m;j++){
                char c;
                cin >> c;
                if (c == '#'){
                    if (hashes == 0){
                        index_of_first_hash = j;
                    }
                    hashes+=1;
                }
            }
            if (hashes == 1){
                x = index_of_first_hash + 1; // +1 is because we are counting from one in the question.
            }
            if ((hashes < last) || (i == n-1)){
                y = ((i == n-1)&&(last == 0))?(i+1):(i-1+1); // +1 is because we are counting from one in the question.
                for (int k=i+1;k<n;k++){
                    string temp;
                    cin >> temp;
                }
                break;
            }
            last = hashes;
        }
        cout << y << " " << x << endl;
        

    }

    return 0;
}