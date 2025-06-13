#include <bits/stdc++.h>
using namespace std;


std::string base64_chars =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";
bool is_base64(unsigned char c) {
    return (isalnum(c) || ((c == '+') || (c == '/')));
}

bool isvalid(string s){
    int endeq = 0;
    for (int i=s.size()-1;i>=0;i--){
        if (s[i] == '='){
            endeq += 1;
        }else{
            break;
        }
    }
    if (endeq > 2){
        return 0;
    }
    if (s.size()%4 != 0){return 0;}
    for (int i=0;i<s.size()-endeq;i++){
        if (!is_base64(s[i])){
            return 0;
        }
    }
    return 1;
}

std::string base64_decode(const std::string& encoded) {
    int len = encoded.size();
    int i = 0, j = 0, in = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string output;

    while (len-- && (encoded[in] != '=') && is_base64(encoded[in])) {
        char_array_4[i++] = encoded[in++];
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] =  (char_array_4[0] << 2)        + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) +   char_array_4[3];

            for (i = 0; i < 3; i++) output += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++) char_array_4[j] = 0;

        for (j = 0; j < 4; j++) char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] =  (char_array_4[0] << 2)        + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) +   char_array_4[3];

        for (j = 0; j < (i - 1); j++) output += char_array_3[j];
    }

    return output;
}

int bitmap_extraction(string & base64_data){
    string decoded = base64_decode(base64_data);
    string s;
    for (int i=0;i<decoded.size();i++){
        int c = decoded[i];
        if ((c == 'A' || (c == 'B' || c == 'C')) || ((c >= '0' && c <= '9') || (c == '{' || c == '}'))){
            s.push_back(decoded[i]);
        }
    }
    // cout << s << " " <<s.size() << endl;
    int pos = s.find("ABC{");
    int num = 0;
    // cout << pos << endl;
    if (pos != s.size()){
        string nm = "";
        for (int i=pos+4;i<s.size();i++){
            if (s[i] >= '0' && s[i] <= '9'){
                nm.push_back(s[i]);
            }else{
                if (s[i] == '}'){
                    num = stol(nm);
                    break;
                }else{
                    num = 0;
                    break;
                }
            }
        }
    }
    return num;
}

int main(){
    
    


    return 0;
}