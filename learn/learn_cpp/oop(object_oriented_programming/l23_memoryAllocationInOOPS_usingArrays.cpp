#include <iostream>
#include <string>

using namespace std;

const int len = 100;

class Shop{
    int itemId[len];
    int itemPrice[len];
    int counter;
    public:
        void initCounter(){counter = 0;}
        void setPrice(void);
        void displayPrices(void);
};

void Shop :: setPrice(void){
    cout << "Enter Id of your item no. "<<(counter+1)<<" : ";
    cin >> itemId[counter];
    cout << "Enter Price of your item: ";
    cin >> itemPrice[counter];
    counter++;
}

void Shop :: displayPrices(void){
    for (int i = 0; i < counter; i++)
    {
        cout << "The Price of item with Id "<<itemId[i]<<" is "<<itemPrice[i]<<endl;
    }
    
}

int main(){

      Shop myshop;
      myshop.initCounter();
      for (int i = 0; i < 3; i++)
      {
        myshop.setPrice();
      }
      
      cout << "Displaying prices >> \n";
      myshop.displayPrices();

    return 0;
}