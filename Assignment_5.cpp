#include <iostream>
using namespace std;

int knapSack(int W, int wt[], int val[], int n, int K[][101]) { 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

void printTable(int K[][101], int n, int W) { 
    cout << "Table of values:\n";
    cout << "  ";
    for (int w = 0; w <= W; w++)
        cout << w << " ";
    cout << endl;

    for (int i = 0; i <= n; i++) {
        cout << i << " ";
        for (int w = 0; w <= W; w++)
            cout << K[i][w] << " ";
        cout << endl;
    }
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    int profit[n], weight[n];
    
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int K[101][101];
    int maxValue = knapSack(W, weight, profit, n, K);
    
    cout << "Maximum value in the knapsack: " << maxValue << endl;
    
    printTable(K, n, W);

    return 0;
}