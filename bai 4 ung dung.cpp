#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm tìm số nguyên tố lớn nhất trong ma trận
int findMaxPrime(int m, int n, int a[10][10]) {
    int maxPrime = -1; // Khởi tạo là -1 để đánh dấu nếu không tìm thấy số nguyên tố
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j]) && a[i][j] > maxPrime) {
                maxPrime = a[i][j];
            }
        }
    }
    return maxPrime;
}

void findRowsWithPrime(int m, int n, int a[10][10]) {
    cout << "Cac dong co chua gia tri nguyen to:\n";
    for (int i = 0; i < m; i++) {
        bool hasPrime = false;
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j])) {
                hasPrime = true;
                break;
            }
        }
        if (hasPrime) {
            cout << "Dong " << i + 1 << endl;
        }
    }
}

// Hàm tìm những dòng chỉ chứa các số nguyên tố
void findRowsWithOnlyPrime(int m, int n, int a[10][10]) {
    cout << "Cac dong chi chua cac so nguyen to:\n";
    for (int i = 0; i < m; i++) {
        bool allPrime = true;
        for (int j = 0; j < n; j++) {
            if (isPrime(a[i][j])) {
                allPrime = false;
                break;
            }
        }
        if (allPrime) {
            cout << "Dong " << i + 1 << endl;
        }
    }
}

int main() {
    int m, n;
    cout << "Nhap so dong m: ";
    cin >> m;
    cout << "Nhap so cot n: ";
    cin >> n;
    int a[10][10];
    cout << "Nhap ma tran:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhap gia tri cho ma tran[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> a[i][j];
        }
    }
    int maxPrime = findMaxPrime(m, n, a);
    if (maxPrime == -1) {
        cout << "So nguyen to lon nhat trong ma tran la: " << maxPrime << endl;
    }
    findRowsWithPrime(m, n, a);
    findRowsWithOnlyPrime(m, n, a);

    return 0;
}