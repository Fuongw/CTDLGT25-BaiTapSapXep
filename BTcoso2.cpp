#include <iostream>
using namespace std;

// Hoan vi hai phan tu 
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// QuickSort
void Partition(int a[], int p, int q) {
    int x = a[(p + q) / 2];
    int i = p, j = q;
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (p < j) Partition(a, p, j);
    if (i < q) Partition(a, i, q);
}

void QuickSort(int a[], int n) {
    Partition(a, 0, n - 1);
}

// MergeSort
void Merge(int a[], int temp[], int p, int t, int q) {
    int i = p, j = t, k = 0;
    while (i < t && j <= q) {
        if (a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i < t) temp[k++] = a[i++];
    while (j <= q) temp[k++] = a[j++];
    for (int m = 0; m < k; m++) a[p + m] = temp[m];
}

void RecMergeSort(int a[], int temp[], int p, int q) {
    if (p < q) {
        int k = (p + q) / 2;
        RecMergeSort(a, temp, p, k);
        RecMergeSort(a, temp, k + 1, q);
        Merge(a, temp, p, k + 1, q);
    }
}

void MergeSort(int a[], int n) {
    int *temp = new int[n];
    RecMergeSort(a, temp, 0, n - 1);
    delete[] temp;
}

// HeapSort
void Sift(int a[], int p, int q) {
    int x = a[p];
    int i = p, j = 2 * i + 1;
    while (j <= q) {
        if (j < q && a[j] < a[j + 1]) j++;
        if (x >= a[j]) break;
        a[i] = a[j];
        i = j;
        j = 2 * i + 1;
    }
    a[i] = x;
}

void HeapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Sift(a, i, n - 1);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        Sift(a, 0, i - 1);
    }
}

// In mang
void PrintArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 10;
    int a[] = {8, 5, 1, 3, 6, 9, 12, 4, 7, 10};

    QuickSort (a, n);
    cout << "QuickSort: ";
    PrintArray(a, n);

    MergeSort (a, n);
    cout << "MergeSort: ";
    PrintArray(a, n);

    HeapSort (a, n);
    cout << "HeapSort: ";
    PrintArray(a, n);

    return 0;
}

