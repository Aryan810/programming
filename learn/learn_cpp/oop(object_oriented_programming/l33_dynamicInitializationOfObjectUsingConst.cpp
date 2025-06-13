#include <iostream>
#include <string>

using namespace std;

class BankDeposite{
    int principal;
    int years;
    float interestRate;
    float returnValue;
    string interestType;
    public:
        BankDeposite(){}
        BankDeposite(int p, int y, float r); // r can be a value like 0.04
        BankDeposite(int p, int y, int r);

        void show(void);
};

BankDeposite :: BankDeposite(int p, int y, float r){
    principal = p;
    years = y;
    interestRate = r;
    returnValue = principal;
    interestType = "fraction";
    for (int i = 0; i < years; i++)
    {
        returnValue = returnValue*(1+r);
    }
    
}

BankDeposite :: BankDeposite(int p, int y, int r){
    principal = p;
    years = y;
    interestRate = float(r)/100;
    returnValue = principal;
    interestType = "%";
    for (int i = 0; i < years; i++)
    { 
        returnValue = returnValue*(1+(interestRate));
    }
}

void BankDeposite :: show(void){
    cout << "Principal: "<<principal
         <<"\nYears: "<<years
         <<"\nInterest Rate: "<<interestRate<<" "<<interestType
         <<"\nReturn Value: "<<returnValue
         <<endl;

}

int main(){
    int p, y;
    float r;
    int R;
    BankDeposite bd1, bd2, bd3;
    // cout << "Enter the value of 'p', 'y' and 'r': ";
    // cin >> p >> y >> r;

    // bd1 = BankDeposite(p, y, r);
    // bd1.show();


    cout << "Enter the value of 'p', 'y' and 'R': ";
    cin >> p >> y >> R;
    bd2 = BankDeposite(p, y, R);
    bd2.show();


    return 0;
}