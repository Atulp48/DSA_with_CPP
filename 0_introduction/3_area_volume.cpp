#include <iostream>
using namespace std;
class Detalis {

   public:
    double l;
    double b;
    double h;

    double Area() {
        return l * b;
    }

    double Volume() {
        return l * b* h;
    }
};

int main() {
    Detalis B;
    B.l =12;
    B.b = 11;
    B.h = 31;

    cout << "Area of Room =  " << B.Area() << endl;
    cout << "Volume of Room =  " << B.Volume() << endl;

    return 0;
}