#include <iostream>

using namespace std;

class ShopItem{
    int id;
    float price;
    public:
        void setData(int a, float b){
            id = a;
            price = b;
        }
        void getData(){
            cout << "Item Id: "<<id<<"\nItem price: "<<price <<endl;
        }
};

int main(){
    int size = 3;
    ShopItem *ptr = new ShopItem[size];
    int id_;
    float price_;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter id and price of item: "<<(i+1)<<": ";
        cin >> id_>>price_;
        (ptr + i) -> setData(id_, float(price_));
        (ptr + i) -> getData();
    }
    
     

    return 0;
}