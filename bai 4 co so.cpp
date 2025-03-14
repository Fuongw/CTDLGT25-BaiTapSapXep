#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;
const int Max_size = 30000;
int data[Max_size]; 
int n;
void readDataFromFile(const string& filename) {
	ifstream file(filename);
	n = 0;
	while (file >> data[n]) {
		n++;
	}
}
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void Interchange (int a[], int n) {
	for (int i = 0; i < n-1; i++)
	for (int j = i+1; j < n; j++)
	if (a[i] > a[j])
	Swap (a[i], a[j]);
}
void Selection (int a[], int n) {
	for (int i = 0; i < n-1; i++) {
		// Tim a[kmin] nho nhat trong day [i, n-1]
		int minval = a[i];
		int kmin = i;
		for (int j = i+1; j < n; j++)
		if (minval > a[j]) {
			minval = a[j];
			kmin = j;
		}
		//Hoan doi a[i] voi a[kmin]
		Swap(a[i], a[kmin]);
	}
	
}
void Insertion (int a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int x = a[i];
		bool cont = true;
		while ((j >=0) &&cont)
		if (a[j] > x) {
			a[j+1] = a[j];
			j--;
		}
		else
		cont = false;
		a[j+1] = x;
	}
}
void BubbleNoFlag(int a[], int n) {
	for (int i = n-1; i>=1; i--)
	for (int j = 0; j<= i-1; j++)
	if (a[j] > a[j+1])
	Swap (a[j], a[j+1]);
}
void Partition (int a[], int p, int q) {
	int x = a[(p + q) / 2];
	int i = p;
	int j = q;
	do {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			Swap (a[i], a[j]);
			i++;
			j--;
		}	
	}
	while (i > j);
	if (p < j)
	Partition (a, p, j);
	if (i < q)
	Partition (a, i, q);
}
void MergeSort(int a[], int n) {
    int temp[n];
    MergeSort(a, temp, 0, n - 1);
}
void RecMergeSort(int a[], int temp[], int p, int q) {
    if (p < q) {
        int k = (p + q) / 2;
        RecMergeSort(a, temp, p, k);
        RecMergeSort(a, temp, k + 1, q);
        Merge(a, temp, p, k + 1, q);
    }
}
void Merge(int a[], int temp[], int p, int t, int q) {
    // Trộn dãy a[p]..a[t-1] với dãy a[t]..a[q] đưa vào mảng temp
    int i = p;
    int k = t - 1;
    int n = 0;

    while ((p <= k) && (t <= q)) {
        if (a[p] < a[t]) {
            temp[n] = a[p];
            p++;
        } else {
            temp[n] = a[t];
            t++;
        }
        n++;
    }

    while (p <= k) {
        temp[n] = a[p];
        n++;
        p++;
    }

    while (t <= q) {
        temp[n] = a[t];
        n++;
        t++;
    }

    for (int j = 0; j < n; j++) {
        a[i + j] = temp[j];
    }
}
void Sift(int a[], int p, int q) {
    int x = a[p];
    int i = p;
    int j = 2 * i + 1;
    bool cont = true;

    while ((j <= q) && cont) {
        if (j < q && a[j] < a[j + 1]) {
            j = j + 1;
        }
        if (x < a[j]) {
            a[i] = a[j];
            i = j;
            j = 2 * i + 1;
        } else {
            cont = false;
        }
    }
    a[i] = x;
 }
double measureTime(void (*sortFunc)(int[], int), int a[], int size) {
    clock_t start = clock();
    sortFunc(a, size);
    clock_t end = clock();
    return double(end - start) / CLOCKS_PER_SEC;
}
void saveResults(const string& filename, const string results[]) {
    ofstream file(filename);
    for (int i = 0; i < 7; i++) {
        file << results[i] << endl;
    }
}
int main() {
    string inputFile = "input_data.txt";  // Đọc dữ liệu từ file
    string outputFile = "output_results.txt";  // Lưu kết quả vào file
    readDataFromFile(inputFile);
    // Các thuật toán sắp xếp
    void (*algorithms[])(int[], int) = {
        Interchange, Selection, Insertion, BubbleNoFlag,
        Merge, Partition
    };

    string results[7];

    for (int i = 0; i < 7; i++) {
        int a[Max_size];
        copy(data, data + n, a);  
        double timeTaken = measureTime(algorithms[i], a, n);
        results[i] = "Algorithm " + to_string(i + 1) + ": " + to_string(timeTaken) + " seconds";
    }

    saveResults(outputFile, results);

    return 0;
}
