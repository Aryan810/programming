#include <iostream>

using namespace std;

int main(){

    // int marks[4] = {100, 99, 42, 43};
    // // or, int marks[] = {100, 99, 42, 43};
    // int i = 0;
    // while (i < 4){
    //     cout << marks[i] << endl;
    //     i++;
    // }

    int marks[5];
    marks[0] = 10;
    marks[1] = 90;
    marks[2] = 313;
    marks[3] = 3132;
    // or, int mathMarks[] = {100, 99, 42, 43};

    // // By while loop:
    // int i = 0;
    // while (i < 4){
    //     cout << mathMarks[i] << endl;
    //     i++;
    // }

    // // By for loop: 
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << "the value at "<<i<<" is "<<mathMarks[i]<<endl;
    // }

    // // By do while loop: 
    // int i = 0;
    // do{
    //     cout << "the value at "<<i<<" is "<<mathMarks[i]<<endl;
    //     i++;
    // }while(i < 4);

    // POINTERS Arithimatic and Arrays: 
    
    // here 'p' is a pointer to array 'marks': 

    // for (int* p = marks; p != &marks[4]; p++)
    // {
    //     cout << "value is " << *p << endl;
    // }
    int* p = marks;
    while(*p != marks[4]){
        cout << "value is " << *(p++)<<endl;
    }
    
    return 0;
}




// NOTES >>



