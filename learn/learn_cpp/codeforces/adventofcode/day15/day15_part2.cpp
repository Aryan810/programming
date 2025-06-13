#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void checkIfCanMove(pair<int, int> current, vector<string> & v, int change, bool & canMove, set< pair<int, int> > & boxes){
    boxes.insert(current);
    if (!canMove){return;}
    if (v[current.first+change][current.second] == '.'){
        return;
    }else if (v[current.first+change][current.second] == '#'){
        canMove = 0;
        return;
    }else{
        if (v[current.first+change][current.second] == '['){
            checkIfCanMove({current.first+change, current.second}, v, +change, canMove, boxes);
            checkIfCanMove({current.first+change, current.second+1}, v, +change, canMove, boxes);
        }else if (v[current.first-1][current.second] == ']'){
            checkIfCanMove({current.first+change, current.second}, v, +change, canMove, boxes);
            checkIfCanMove({current.first+change, current.second-1}, v, +change, canMove, boxes);
        }
    }
}

void moveall(set< pair<int, int> > & boxes, vector<string> & v, int change){
    if (change < 0){
        if (boxes.size() > 0){
            auto it = boxes.begin();
            int row = it->first;
            while (it != boxes.end() && it->first == row){
                swap(v[it->first][it->second], v[it->first+change][it->second]);
                ++it;
                if (it != boxes.end() && it->first != row){
                    row = it->first;
                }
            }
        }
    }else{
        if (boxes.size() > 0){
            auto it = boxes.rbegin();
            int r = it->first;
            while (it != boxes.rend() && it->first == r){
                swap(v[it->first][it->second], v[it->first+change][it->second]);
                ++it;
                if (it != boxes.rend() && it->first != r){
                    r = it->first;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


        ifstream inp;
        inp.open("input.txt");

        vector<string> v;
        pair<int, int> robo;
        while (1){
            string s;
            getline(inp, s);
            // cout << 1 << " " << s << endl;
            if (s == ""){break;}
            v.push_back(s);
            auto pos = s.find('@');
            if (pos < s.size()){
                robo = {v.size()-1, pos};
            }
        }

        vector<string> moves;
        
        while (1){
            string s;
            getline(inp, s);
            // cout << 2 << " " << s << endl;
            if (s == ""){break;}
            moves.push_back(s);
        }
        // cout << "ROBO: " << robo.first << " " << robo.second << endl;
        for (auto line: v){cout << line << endl;}cout << endl;

        // new map
        vector<string> newv;
        for (int i=0;i<v.size();i++){
            string temp;
            for (int j=0;j<v[i].size();j++){
                if (v[i][j] == '.'){
                    temp.push_back('.');
                    temp.push_back('.');
                }else if (v[i][j] == '#'){
                    temp.push_back('#');
                    temp.push_back('#');
                }else if (v[i][j] == 'O'){
                    temp.push_back('[');
                    temp.push_back(']');
                }else{
                    temp.push_back('@');
                    temp.push_back('.');
                }
            }
            newv.push_back(temp);
        }
        v = newv;
        robo.second *= 2;
        for (auto line: v){cout << line << endl;}cout << endl;
        cout << robo.first << " : " << robo.second << endl;


        for (int i=0;i<moves.size();i++){
            for (int j=0;j<moves[i].size();j++){
                auto move = moves[i][j];
                // cout << "MOVE: " << move << endl;
                if (move == '>'){
                    auto temp = robo;
                    temp.second += 1;
                    while (v[temp.first][temp.second] == '[' || v[temp.first][temp.second] == ']'){
                        temp.second += 1;
                    }
                    if (v[temp.first][temp.second] == '.'){
                        temp.second -= 1;
                        while (temp != robo){
                            swap(v[temp.first][temp.second]
                            , v[temp.first][temp.second+1]);
                            temp.second -= 1;
                        }
                        v[temp.first][temp.second] = '.';
                        v[temp.first][temp.second+1] = '@';
                        robo.second += 1;
                    }
                }else if (move == '<'){
                    auto temp = robo;
                    temp.second -= 1;
                    while ((v[temp.first][temp.second] == '[') || (v[temp.first][temp.second] == ']')){
                        temp.second -= 1;
                    }
                    if (v[temp.first][temp.second] == '.'){
                        temp.second += 1;
                        while (temp != robo){
                            swap(v[temp.first][temp.second]
                            , v[temp.first][temp.second-1]);
                            temp.second += 1;
                        }
                        v[temp.first][temp.second] = '.';
                        v[temp.first][temp.second-1] = '@';
                        robo.second -= 1;
                    }
                }else if (move == '^'){
                    bool canMove = 1;
                    set< pair<int, int> > boxes;
                    if (v[robo.first-1][robo.second] == '['){
                        checkIfCanMove({robo.first-1, robo.second}, v, -1, canMove, boxes);
                        checkIfCanMove({robo.first-1, robo.second+1}, v, -1, canMove, boxes);
                    }else if (v[robo.first-1][robo.second] == ']'){
                        checkIfCanMove({robo.first-1, robo.second}, v, -1, canMove, boxes);
                        checkIfCanMove({robo.first-1, robo.second-1}, v, -1, canMove, boxes);
                    }else if (v[robo.first-1][robo.second] == '#'){
                        canMove = 0;
                    }
                    // cout << canMove << " " << boxes.size() << endl;
                    if (canMove){
                        moveall(boxes, v, -1);
                        swap(v[robo.first][robo.second], v[robo.first-1][robo.second]);
                        robo.first -= 1;
                    }
                }else if (move == 'v'){
                    bool canMove = 1;
                    set< pair<int, int> > boxes;
                    if (v[robo.first+1][robo.second] == '['){
                        checkIfCanMove({robo.first+1, robo.second}, v, 1, canMove, boxes);
                        checkIfCanMove({robo.first+1, robo.second+1}, v, 1, canMove, boxes);
                    }else if (v[robo.first+1][robo.second] == ']'){
                        checkIfCanMove({robo.first+1, robo.second}, v, 1, canMove, boxes);
                        checkIfCanMove({robo.first+1, robo.second-1}, v, 1, canMove, boxes);
                    }else if (v[robo.first+1][robo.second] == '#'){
                        canMove = 0;
                    }
                    // cout << canMove << " " << boxes.size() << endl;
                    if (canMove){
                        moveall(boxes, v, +1);
                        swap(v[robo.first][robo.second], v[robo.first+1][robo.second]);
                        robo.first += 1;
                    }
                }
                // for (auto line: v){cout << line << endl;}
                // cout << endl;
            }
        }

        for (auto line: v){cout << line << endl;}
        cout << endl;

        // calculating answer
        ll ans = 0;
        for (int i=0;i<v.size();i++){
            for (int j=0;j<v[i].size();j++){
                if (v[i][j] == '['){
                    ans += i*100 + j;
                }
            }
        }
        cout << ans << endl;
        inp.close();
    

    return 0;
}