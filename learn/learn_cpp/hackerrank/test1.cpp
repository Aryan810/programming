// #include <cmath>
// #include <cstdio>
// #include <vector>
#include <iostream>
// #include <algorithm> 
#include <string>
#include <list>
#include <map>
#include <fstream>

using namespace std;

ifstream inp;


class LRUCache{
    int cp;
    list<int> lst;
    map<int, int> mp;
    list<int>::iterator tail, head;
    
    public:
        LRUCache(int cp){
            this -> cp = cp;
            tail = lst.end();
            head = lst.begin();
        }
        void set(int key, int value){
            if (lst.size() < cp){
                lst.push_front(key);
                mp[key] = value;
            }else{
                cout << "END: "<<*(lst.end())<<endl;
                mp.erase(*(lst.end()));
                lst.pop_back();
                lst.push_front(key);
                mp[key] = value;
            }
        }
        int get(int key){
            bool found = false;
            list<int>::iterator iter = lst.begin();
            for (int i=0;i<lst.size();i++){
                if (*(iter)==key){
                    found = true;
                    lst.erase(iter);
                    lst.push_front(key);
                }
                iter++;
            }
            if (found){
                return mp[key];
            }else{
                return -1;
            }
        }
};


int main() {
    int n, m;
    inp.open("input08.txt");
    inp >> n >> m;
    cout << n << m;
    LRUCache lc(m);
    string inp_typ;
    int t1, t2;
    for (int i=0; i<n; i++) {
        inp >> inp_typ;
        if (inp_typ == "get"){
            inp >> t1;
            cout << lc.get(t1) << endl;
        }else if (inp_typ == "set"){
            inp >> t1 >> t2;
            lc.set(t1, t2); 
        }
    }
    
    
    return 0;
}
