#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

void split_str(stringstream& ss, char c, vector<string>& words){
    string word;
    while (!(ss.eof()))
    {   
        getline(ss, word, c);
        words.push_back(word);
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    map <string, map<string, string> > data;
    map<string, string> attrib;
    vector <string> words;
    for (int i = 0; i < n; i++)
    {   
        words.clear();
        attrib.clear();
        string temp;
        while (true){
            cout << 0;
            cin >> temp;
            // cout << temp;
            cout << 1;
            if (temp.back() == '>'){
                temp.replace(temp.end()-1,temp.end(), "");
                cout << 2;
                words.push_back(temp);
                break;
            }
            if(temp[0] == '<'){
                temp.replace(0, 1, "");
            }

            if (temp == "="){
            }else{
            words.push_back(temp);
            }

        }
        
        // cout << words.back();

        for(int j=1;j<words.size();j++){
            attrib[words[j]] = words[j+1];
            j++; 
        }
        data[words[0]] = attrib;
    }
    // cout << data["tag1"]["value"] <<endl;
    // cout << data["tag1"]["name"] <<endl;

    string query;

    for (int j = 0; j < q; j++)
    {   
        vector <string> vec;
        cin >> query;
        stringstream ss(query);
        split_str(ss, '~', vec);
        if (vec[0].find('.') != string::npos){
            try{
                cout << data[vec[0]][vec[1]]<<endl;
            }catch(exception& e){
                cout << "Not Found!"<<endl;
            }
        }else{
            cout << data[vec[vec.size()-1]][vec[vec.size()]];
        }
    }
    return 0;
}