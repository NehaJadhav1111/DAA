#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int value;  
    int weight; 
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, compare);

    int currentWeight = 0;  
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        
        else {
            int remaining = W - currentWeight;
            finalValue += arr[i].value * ((double)remaining / arr[i].weight);
            break; 
        }
    }

    return finalValue;
}

int main() {
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    Item* arr = new Item[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight of item " << i + 1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    double maxValue = fractionalKnapsack(W, arr, n);

    cout << "Maximum value we can obtain = " << maxValue << endl;

    delete[] arr;

    return 0;
}
