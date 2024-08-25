#include <iostream>
#include <string>

using namespace std;

// Nesting of member functions
class binary
{
    private:
        string s;
        void chk_bin(void);

    public:
        void read(void);
        void interchange(void);
        string get(void)
        {
            return s;
        }
};

void binary ::interchange(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
        {
            s[i] = '1';
        }
        else if (s.at(i) == '1')
        {
            s[i] = '0';
        }
        else
        {
            cout << "Not a valid binary number";
            exit(0);
        }
    }
}
void binary ::read(void)
{
    cout << "Enter a binary number: ";
    cin >> s;
    cout << endl;
    chk_bin();
}

void binary ::chk_bin(void)
{
    for (int i = 0; i < s.length(); i++)
    {
        if ((s.at(i) != '0') and (s.at(i) != '1'))
        {
            cout << "Not a valid binary!"<<endl;
            exit(0);
        }
    }
    cout << "It is a valid binary."<<endl;
}

// ------------__-__------------------

int main()
{
    binary b;
    b.read();
    cout << "string: " << b.get() << endl;
    b.interchange();
    cout << "string: " << b.get() << endl;

    return 0;
}