#include <iostream>

using namespace std;

class SimpleCalculator{
    protected:
        int a;
        int b;
    public:
        // void get_num_simple(void){
        //     cout << "Enter two numbers to operate simple calculator: ";
        //     cin >> a >> b;
        //     cout<<endl;
        // }
        void set_num1(int n1, int n2){
            a = n1;
            b = n2;
        }
        void display_simple(void){
            cout << "The value of (a + b) is: " << (a + b) << endl;
            cout << "The value of (a - b) is: " << (a - b) << endl;
            cout << "The value of (a x b) is: " << (a * b) << endl;
            cout << "The value of (a / b) is: " << (a / b) << endl;
        }
        // void add(void){
        //     cout << "The sum is :"<<(num1+num2)<<endl;
        // }
        // void difference(void){
        //     cout << "The subtraction is: "<<(num1-num2)<<endl;

        // }
        // void product(void){
        //     cout << "The product is :"<<(num1*num2)<<endl;
        // }
        // void division(void){
        //     cout << "The division is :"<<(num1/num2)<<endl;
        // }
};

class ScientificCalc{
    protected:
        int num1;
        int num2;
    public:

        // void get_num_scientific(void){
        //     cout << "Enter two numbers to operate scientific calculator: ";
        //     cin >> num1 >> num2;
        //     cout<<endl;
        // }
        void set_num2(int n1, int n2){
            num1 = n1;
            num2 = n2;
        }

        void display_scintific(void){
            exponent();
            remainder();
            log();
            sine();
        }

        void exponent(void){
            int ans = 1;
            for (int i = 0; i < num2; i++)
            {
                ans = ans * num1;
            }
            
            cout << "The value of "<<num1<<" to the power of "<<num2<<" is: "<<(ans)<<endl;

        }

        void remainder(void){
            // int temp = num1;
            // while (temp > num2){
            //     temp = temp - num2;
            // }
            cout << "The reminder is: "<<(num1%num2)<<endl;
        }
        void log(void){
            float ans = log2(num1)/log2(num2);
            cout << "The value of log "<<num1<<" to base "<<num2<<" is: "<<ans<<endl;
        }
        void sine(void){
            cout << "The value of sin("<<num1<<") is: "<<sin(double(num1))
                 <<"\nThe value of sin("<<num2<<") is: "<<sin(double(num2))<<endl;
        }
};

class HybridCalc : public SimpleCalculator, public ScientificCalc{
    public:
        void set(int a, int b){
            set_num1(a, b);
            display_simple();
            set_num2(a, b);
            display_scintific();
        }
};

/*
Here:
1: we are using multiple inheritence.
2: we use public mode of inheritence.
3: displaying results of simple and hybrid calc using object of hybrid class.
4: here we reused the code to get number for both calculator.
*/   

int main(){
    int num1, num2;
    HybridCalc hc;
    cout << "Enter two numbers to operate scientific calculator: ";
    cin >> num1 >> num2;
    cout<<endl;
    hc.set(num1, num2);

    return 0;
}