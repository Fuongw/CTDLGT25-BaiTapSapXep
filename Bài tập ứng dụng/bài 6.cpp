#include <iostream>
using namespace std ;

// Sap xep so chan theo thu tu tang dan
void BubbleSortEven(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Sap xep so le theo thu tu giam dan
void BubbleSortOdd(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main() {
    int n, a[1000];
    cout<< "Nhap phan tu cua mang: " ;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int even[1000] , odd[1000] ;
    int evenCount = 0, oddCount = 0; 
    
    for (int i = 0; i < n; i++) {
    	if (a[i] != 0) { 
            if (a[i] % 2 == 0) {
                even[evenCount] = a[i]; 
                evenCount++; 
            } else {
                odd[oddCount] = a[i]; 
                oddCount++; 
            }
        }
    }
    

    BubbleSortEven(even, evenCount);
    BubbleSortOdd(odd, oddCount);
    
    evenCount = 0; 
    oddCount = 0; 
    
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue; 
        } else if (a[i] % 2 == 0) {
            a[i] = even[evenCount]; 
            evenCount++; 
        } else {
            a[i] = odd[oddCount]; 
            oddCount++; 
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
