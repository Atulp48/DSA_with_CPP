#include<iostream>
using namespace std;
void printArray(int arr[], int size) {

    cout<< " printing the array " << endl;
    for(int i =0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout<< " printing DONE " << endl;
}

int main() {
    int number[15];
    cout << "Value at 14 index " << number[14] << endl;
    int second[3] = {5, 7, 11};

    cout << "Value at 2 index " << second[2] << endl;

    int third[15] = {2,7};

    int n = 15;
  
    int thirdSize = sizeof(third)/sizeof(int);
    cout<<" Size of Third is " << thirdSize <<endl;
    int fourth[10] = {0};

    n = 10;
    int fifth[10] = {1};
    n = 10;
    int fifthSize = sizeof(fifth)/sizeof(int);
    cout<<" Size of Fifth is " << fifthSize <<endl;
    

    char ch[5] = {'a', 'b', 'c', 'r', 'p'}; 
    cout << ch[3] << endl;

    cout<< " printing the array " << endl;
    for(int i =0; i<5; i++) {
        cout << ch[i] << " ";
    }
    cout<< " printing DONE " << endl;
    double firstDouble[5];
    float firstFloat[6];
    bool firstBool[9];
    cout << endl << " Everything is Fine " << endl << endl;

    return 0;
}