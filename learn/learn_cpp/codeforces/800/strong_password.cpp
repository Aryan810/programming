#include <iostream>
#include <string>

using namespace std;

int main(){

    int t;
    cin >> t;
    bool check = false;
    string temp;
    string words = "ab";
    for (int i=0;i<t;i++){
        cin >> temp;
        check = false;
        for (int j=1;j<temp.size();j++){
            if (temp[j-1] == temp[j]){
                check = true;
                if (temp[j-1] == words[0]){
                    temp = temp.substr(0, j) + words[1] + temp.substr(j, temp.size());
                }else if (temp[j-1] == words[1]){
                    temp = temp.substr(0, j) + words[0] + temp.substr(j, temp.size());
                }else{
                    temp = temp.substr(0, j) + words[0] + temp.substr(j, temp.size());
                }
                break;
            }
        }
        if (!check){
            if (temp[0] == words[0]){
                temp = words[1] + temp;
            }else{
                temp = words[0] + temp;
            }
        }
        cout << temp << endl;
        temp = "";
    }


    return 0;
}