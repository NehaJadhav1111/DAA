#include <iostream>
using namespace std;

int binary_search(int array[], int low, int high, int element) {
    int mid;

    if (low <= high) {
        mid = (low + high) / 2;

        if (array[mid] == element) {
            return mid;
        } else if (array[mid] < element) {
            return binary_search(array, mid + 1, high, element);
        } else {
            return binary_search(array, low, mid - 1, element);
        }
    }

    return -1;
}

int main() {
    int low = 0;
    int high;
    int ele;
    int arr[100];
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter array elements in sorted order:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    high = n - 1;

    cout << "Enter the element to be searched: ";
    cin >> ele;

    int found = binary_search(arr, low, high, ele);
    if (found != -1) {
        cout << "Element found at index: " << found << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
