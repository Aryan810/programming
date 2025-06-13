#include <iostream>
#include <string>
#include <math.h>

using namespace std;

string base_change(int num, int base, int change_to_base){
    int base_10;
    string num_s = to_string(num);
    if (base != 10){
        base_10 = 0;
        for (int i=0;i<num_s.size();i++){
            if (!((int(num_s[i]-'0') < (base)) && (int(num_s[i]-'0') >= 0))){
                cout << "invalid base !" << endl;
                return "";
                // throw "Invalid base";
            }
            base_10 += int(num_s[i]-'0')*pow(base, num_s.size()-1-i);
        }
    }else{
        base_10 = num;
    }
    num_s = "";
    // cout << base_10 << endl;
    while (base_10 != 0){
        num_s = to_string(base_10%change_to_base) + num_s;
        base_10 = (base_10 - (base_10%change_to_base))/change_to_base;
    }
    return num_s;
}

int main(){

    int num = 122;
    int base = 3;
    int new_base =19;
    cout << base_change(num, base, new_base) << endl;

    return 0;
}