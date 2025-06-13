#include <iostream>

using namespace std;

// Destructor not takes a argument and never returns anything!

class num{
    static int count;
    public:
        num(){
            count++;
            cout<<"This is the time when constructor is called for obj no. "<<count<<endl;
        }

        ~num(){
            cout << "This is the time when the destructor is called for obj no. "<<count<<endl;
            count--;
        }
};
int num :: count = 0;
int main(){
    cout << "We are inside our main function."<< endl;
    cout << "Creating first object n1"<<endl;
    num n1;
    {
        cout << "Entering this block"<<endl;
        cout<<"Creating two more objects"<<endl;
        num n2, n3;
        cout << "Exiting this block."<<endl;
    }
    cout << "Back to main"<<endl;
    

    return 0;
}