#include <iostream>
#include <string>

using namespace std;

class Student
{
protected:
    int roll_no;
    string name;

public:
    void set_name(string name_)
    {
        name = name_;
    }
    void get_name(void)
    {
        cout << endl
             << "\nName: " << name << endl
             << endl;
    }
    void set_roll_number(int);
    void get_roll_number(void);
};

void Student ::set_roll_number(int r)
{
    roll_no = r;
}

void Student ::get_roll_number()
{
    cout << "The roll number is " << roll_no << endl;
}

class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void set_marks(float, float);
    void get_marks(void);
};

void Exam ::set_marks(float math_marks, float phy_marks)
{
    maths = math_marks;
    physics = phy_marks;
}

void Exam ::get_marks(void)
{
    cout << "The marks of Physics are " << physics << "\nThe marks of Maths are " << maths << endl;
}

class Result : public Exam
{
    float percentage;

public:
    Result()
    {
        set_name("-------");
    }
    Result(string name_)
    {
        set_name(name_);
    }
    void display()
    {
        get_name();
        get_roll_number();
        get_marks();
        cout << "Your percentage is " << ((maths + physics) / 2) << endl;
        ;
    }
};

int main()
{
    Result aryan("Aryan Gupta");
    aryan.set_roll_number(69);
    aryan.set_marks(98, 95);

    aryan.display();

    return 0;
}