#include <iostream>
#include <string>

using namespace std;

class CWH{
    protected:
        string title;
        float rating;
    public:
        CWH(string s, float r){
            title = s;
            rating = r;
        }
        CWH(){}
        virtual void display(){
            cout << "bogus code" << endl;
        }

};

class CWHVideo : public CWH{
    float videoLen;
    public:
        CWHVideo(string s, float r, float vL): CWH(s, r){
            videoLen = vL;
        }
        
        // if we remove this display() function then display() function of CWH (base) class will be invoked.  
        void display(){
            cout <<"This is an amazing video with >> \nTitle: "<<title<<endl;
            cout<<"Rating: "<<rating<<" out of 5 stars"<<endl;
            cout<<"Length: "<<videoLen<<" minutes"<<endl;
        }
};

class CWHText: public CWH{
    int words;
    public:
        CWHText(string s, float r, int words_): CWH(s, r){
            words = words_;
        }

        void display(){
            cout<<"This is an amazing text tutorial with >> \nTitle: "<<title<<endl;
            cout<<"Rating: "<<rating<<" out of 5 stars"<<endl;
            cout<<"No. of words in this text tutorial: "<<words<<endl;
        }
};

int main(){
    string title;
    float rating, vlen;
    int words;

    // For CWH video.
    title = "Djengo tuto...";
    vlen = 4.56;
    rating = 4.99;
    CWHVideo djVideo(title, rating, vlen);
    // djvideo.display();
    
    // For CWH text.
    title = "Djengo tuto...";
    words = 243;
    rating = 4.19;
    // CWHVideo djvideo(title, rating, vlen);
    CWHText djText(title, rating, words);
    // djText.display();

    CWH* tuts[2];
    tuts[0] = &djVideo;
    tuts[1] = &djText;
    tuts[0]->display();
    tuts[1]->display();

    return 0;
}

/*
 Rules for virtual functions >>

 1. They cannot be static
 2. They are accessed by objects pointers.
 3. Virtual functions can be a friend of another class.
 4. A virtual function in base class might not be used.
 5. If a virtual function definded in a base class, there is no nessessity of redefining it in derived class.

*/