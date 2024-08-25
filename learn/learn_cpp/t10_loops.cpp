# include <iostream>
using namespace std;
int main()
{
    /*
    LOOPS IN CPP
    
    1: WHILE LOOP
    2: FOR LOOP >> 

            syntax:
                for (initialisation; condition; updation){
                BODY
                }


    3: DO WHILE LOOP
    */
//    for (int i = 1; i < (4 + 1); i++){
//     cout << i << endl;

//    }
    // while (i <= 40){
    //     cout << i << endl;
    //     i++;
    // }

   // do while loop

//    do
//    {
//     cout << i << endl;
//     i ++;
//    } while (i <= 10);
   
   // ex: table of 6:
   int i = 6;
   int temp = 6;
   do{
    cout << temp<<endl;
    temp = temp + i;
   }while(temp <= i*10);
   
    return 0;
}
