#include<iostream>
using namespace std;

class Human {

    public:
    int height;

    public: 
    int weight;

    private:
    int age;

    public:
    int getAge() {
        return this->age;
    }

    void setWeight(int w) {
        this->weight = w;

    }

};

class Male: private Human {

    public:
    string color;
    void sleep() {
        cout << "Male Sleeping" << endl;
    }
    int getHeight() {
        return this->height;
    }

};



int main() {

    Male m1;
    return 0;
}