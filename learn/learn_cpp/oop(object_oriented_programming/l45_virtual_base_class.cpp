#include <iostream>

using namespace std;

class Student{
    protected:
        int roll_no;
    public:
        void set_roll_number(int a){
            roll_no = a;
        }
        void print_number(void){
            cout << "Your roll number is: "<<roll_no<<endl;
        }
};

class Test: virtual public Student{
    protected:
        float maths, physics;
        public:
            void set_marks(float m1, float m2){
                maths = m1;
                physics = m2;
            }

            void print_marks(void){
                cout << "Your result is here: \n"
                    << "Maths: "<<maths<<endl
                    <<"Physics: "<<physics<<endl;
            }

};

class Sports: virtual public Student{
    protected:
        float score;
    public:
        void set_score(float sc){
            score = sc;
        }
        void print_score(void){
            cout << "Your PT score is: "<<score<<endl;
        }

};

class Result: public Test, public Sports{
    private:
        float total;
    public:
        void display(void){
            total = maths + physics + score;
            print_number();
            print_marks();
            print_score();
            cout << "Your total score is: "<<total<<endl;
        }

};

int main(){
    Result aryan;
    aryan.set_score(86);
    aryan.set_marks(98.0f, 95.0f);
    aryan.set_roll_number(56);
    aryan.display();

    return 0;
}