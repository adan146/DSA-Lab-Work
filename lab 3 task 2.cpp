#include <iostream>
using namespace std;

int main() {
    char* ptr = new char;

    cout << "Enter a character: ";
    cin >> *ptr;
    cout<<"character is:"<<*ptr<<endl;

    delete ptr;
    ptr = nullptr;

    return 0;
}