#include <iostream>
using namespace std;
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int target = 40;

    for (int i = 0; i < 5; i++) {
        if (arr[i] == target) {
            cout << "40 found at index " << i;
            break;
        }
    }
    return 0;
}