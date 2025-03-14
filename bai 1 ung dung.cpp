#include <iostream>
#include <cmath>
usingnamespace std;
//Ham kiem tra so nguyen to
bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}
//Ham tinh tong cac chu so cua mot so 
int sumOfDigits(int n){
    int sum=0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}
int main(){
    int n, k;
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    int maxValues[n];
    int maxIndices[n];
    int numValues = 0;
    
    int sumDigitsArr[n];
    int valuesArr[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        int value;
        cout << "Nhap phan tu thu " << i << ": ";
        cin >> value;

        //a. Tim k phan tu lon nhat
        if (numValues < k) {
            maxValues[numValues] = value;
            maxIndices[numValues] = i;
            numValues++;
        } else {
            int minValue = maxValues[0];
            int minIndex = 0;
            for (int j = 1; j < n; j++) {
                if (maxValues[j] < maxValues[minIndex]) {
                    minIndex = j;
                }
            }
            if (value > maxValues[minIndex]) {
                maxValues[minIndex] = value;
                maxIndices[minIndex] = i;
            }
        }
        //b. Sap xep theo tung cac chu so
        sumDigitsArr[i] = sumOfDigits(value);
        valuesArr[i] = value;
    
        // c. Xoa so nguyen to
        if (!isPrime(value)) {
            valuesArr[count] = value;
            count++;
        }
    }
    // a. In ra vi tri cua k phan tu lon nhat
    cout << "Vi tri cua " << k << " phan tu lon nhat: ";
    for (int i = 0; i < numValues; i++) {
        cout << maxIndices[i] << " ";
    }
    cout << endl;

    // b. Sap xep va in ra theo tung cac chu so 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sumDigitsArr[j] > sumDigitsArr[j + 1]) {
                int temp = sumDigitsArr[j];
                sumDigitsArr[j] = sumDigitsArr[j + 1];
                sumDigitsArr[j + 1] = temp;

                temp = valuesArr[j];
                valuesArr[j] = valuesArr[j + 1];
                valuesArr[j + 1] = temp;
            }
        }
    }
    cout << "Mang sau khi sap xep theo tong cac chu so: ";
    for (int i = 0; i < n; i++) {
        cout << valuesArr[i] << " ";
    }
    cout << endl;

    // c. In ra mang sau khi xoa so nguyen to
    cout << "Mang sau khi xoa so nguyen to: ";
    for (int i = 0; i < count; i++) {
        cout << valuesArr[i] << " ";
    }
    cout << endl;

    return 0;
}
