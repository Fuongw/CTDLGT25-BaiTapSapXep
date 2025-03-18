#include <iostream>
using namespace std;

int sumRow(int a[100][100], int row, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[row][i];
    }
    return sum;
}

int findMaxSumRow(int a[100][100], int m, int n) {
    int maxSum = -1;  
    int maxRow = -1;  

    for (int i = 0; i < m; i++) {
        int rowSum = sumRow(a, i, n);
        if (rowSum > maxSum) {
            maxSum = rowSum;
            maxRow = i;
        }
    }

    return maxRow;
}

void sortRowsBySum(int a[100][100], int m, int n) {
    for (int i = 0; i < m - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < m; j++) {
            if (sumRow(a, j, n) > sumRow(a, maxIndex, n)) {
                maxIndex = j;
            }
        }

        if (maxIndex != i) {
            for (int k = 0; k < n; k++) {
                int temp = a[i][k];
                a[i][k] = a[maxIndex][k];
                a[maxIndex][k] = temp;
            }
        }
    }
}

int main() {
    int m, n;
    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;

    int a[100][100];
    cout << "Nhap mang (" << m << " x " << n << "):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int maxRow = findMaxSumRow(a, m, n);
    cout << "Dong co tong lon nhat la dong " << maxRow << " (chi so tu 0).\n";

    cout << "\nMang ban dau:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    sortRowsBySum(a, m, n);

    cout << "\nMang sau khi duoc sap xep theo tong cac dong:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
