#include <iostream>
using namespace std;
int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int target = 40;

    int low = 0;
    int high = 4;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            cout << "40 found at index " << mid;
            break;
        }
        else if (target > arr[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return 0;
}