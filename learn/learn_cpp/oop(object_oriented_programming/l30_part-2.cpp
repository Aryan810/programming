#include <iostream>


using namespace std;

class Point{
    int x, y ;
    public:
        Point(int a, int b){
            x = a;
            y = b;
        }
        friend double distance(Point, Point);
        void displayPoint(){
            cout << "The point is ("<<x<<", "<<y<<")" <<endl;
        }

};

double distance(Point a, Point b){
    return sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));

}

// Quiz :

int main(){

    Point a(1, 5);
    a.displayPoint();

    Point b(4, 6);
    b.displayPoint();

    cout << "The distance is: "<<distance(a, b);

    return 0;
}