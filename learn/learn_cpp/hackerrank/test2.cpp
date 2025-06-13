#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <sstream>


using namespace std;

string right_justify(double num){
    num = double(int(num*pow(10, 2)))/pow(10, 2);
    string num_str = to_string(num);
    while (*(num_str.end()-1)=='0'){
        num_str.erase(num_str.end()-1);
    }
    int n = 15-num_str.size();
    for (int i=0; i<n; i++) {
        num_str = "_" + num_str;
    }
    return num_str;
    }

string hexa_decimal(long int num){
    string data[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", 
                    "a", "b", "c", "d", "e", "f"};
    string hexad;
    int e=0;
    while (pow(16, e)<num){
        e += 1;
    }
    cout << "E: "<<e<<endl;
    for (int i=e-1;i>=0;i--){
        hexad += data[(num-(num%(long int)(pow(16, i))))/(long int)pow(16, i)-1];
        num = num%(long int)(pow(16, i));
    }
    hexad = "0x" + hexad;
    return hexad;
}

int main(){

    // set <int> s;
    // s.insert(2);
    // s.insert(3);
    // s.insert(23);
    // s.insert(4);
    

    // double d = 4.52532;
    // string d;
    // d += "a";
    // d += "b";
    // cout << d;

    // cout << pow(2, 3);
    double d=-5.423;
    int n=2;
    // cout << ceil((d)*pow(0.1, n))<<endl;
    // double f = double(int(d*pow(10, n)))/pow(10, n);
    // cout << f;
    // cout << right_justify(d);
    // stringstream ss;
    // ss << scientific;
    // ss << to_string(2331.41592653498);
    // cout << ss.str();
    cout << hex<< (28473348240);



    return 0;
}