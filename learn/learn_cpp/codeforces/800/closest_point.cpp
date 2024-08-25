#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

void insert_from_to(set<int> & s, int a, int b){
    s.erase(s.begin(), s.end());
    while (a <= b){
        s.insert(s.end(), a++);
    }
}

// void show(set<int> & s){
//     set<int>::iterator iter = s.begin();
//     cout << endl;
//     while(iter != s.end()){
//         cout << *(iter++) << endl;
//     }
// }


int is_closest_exist(vector<int> & points){
    // main logic :
    set<int> main;
    insert_from_to(main, points[0]-(points[1]-points[0]), points[1]);
    set<int> temp;
    set<int> temp1;
    int g1, g2;
    sort(points.begin(), points.end());
    for (int i=1;i<points.size();i++){
        g1 = points[i]-points[i-1];
        if (i != points.size()-1){
            g2 = points[i+1]-points[i];
        }else{
            g2 = g1;
        }
        if (g1 <= g2){
            insert_from_to(temp, points[i]-g1, points[i]+g1);
        }
        else{
            insert_from_to(temp, points[i]-g2, points[i]+g2);
        }
        // cout << "I: " << i << endl;
        // show(main);
        // cout << "temp" << endl;
        // show(temp);
        temp1 = main;
        main.erase(main.begin(), main.end());
        set_intersection(temp1.begin(), temp1.end(), temp.begin(), temp.end(), inserter(main, main.begin()));
    }
    temp = set<int>(points.begin(), points.end());
    temp1.erase(temp1.begin(), temp1.end());
    set_intersection(temp.begin(), temp.end(), main.begin(), main.end(), inserter(temp1, temp1.begin()));
    temp.erase(temp.begin(), temp.end());
    set_difference(main.begin(), main.end(), temp1.begin(), temp1.end(), inserter(temp, temp.begin()));
    
    // cout << "SIZE: " << temp.size() << endl;
    
    // show(temp);
    if (temp.size() == 0){
        return 0;
    }

    return 1;
}

int main(){

    int t;
    cin >> t;

    int n;
    vector<int> points;
    int temp;
    
    for (int i=0;i<t;i++){
        cin >> n;
        for (int j=0;j<n;j++){
            cin >> temp;
            points.push_back(temp);
        }
        if (is_closest_exist(points)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        points.erase(points.begin(), points.end());
    }

    return 0;
}