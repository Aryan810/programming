#include <iostream>
#include <string>

using namespace std;

int is_imp(int inp){
    string str = to_string(inp);
    string suffix;
    if (str.length() < 3){
        return 0;
    }else{
        if (str.substr(0, 2)=="10"){
            suffix = str.substr(2, str.length());
            if (suffix[0] == '0'){
                return 0;
            }else{
                if (int(stoi(suffix)) < 2){return 0;}
            }
        }else{
            return 0;
        }
    }
    return 1;

}

int main(){

    int t;
    cin >> t;
    int inp;

    for (int i=0;i<t;i++){
        cin >> inp;
        if (is_imp(inp)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;

        }

    }

    return 0;
}