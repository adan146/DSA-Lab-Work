#include <iostream>
using namespace std;
int main() {
    int arr[10] = {20, 30, 40, 50};
    int n = 4;

    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = 15;
    n++;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}