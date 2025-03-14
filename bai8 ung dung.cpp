#include <iostream>
using namespace std;
//cau a: tim mang nghich the cua 1 hoan vi
void timnghichthe (int A[], int C[], int n){
	for (int i=0; i<n; i++){
		C[i] = 0; //khoi tao
		for (int j = 0; j < i; j++){
			if (A[j] > A[i]){ //gia tri cua phan tu dung sau lon hon phan tu dung truoc
				C[i]++;
			}
		}
	}
}
//cau b:tim hoan vi cua mot mang nghich the
bool timhoanvi (int B[], int C[], int n){
	bool used[n+1] = {false};
	for (int i = n - 1; i >= 0; i--){
		int count = 0;
		for (int j = 1; j <= n ; j++){
			if (!used[j]) count++;
			if (count == B[i] + 1){
				C[i] = j;
				used[j] = true;
				break;
			}
		}
	}
}

//Mang
void PrintArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main (){
	int n = 9;
	int A[] = {5, 9, 1, 8, 2, 6, 4, 7, 3};
	int B[] = {2, 3, 6, 4, 0, 2, 2, 1, 0};
	int C[n];
	
	cout << "nghich the B:" << B[];
	timnghichthe(A,C,n);
	cout << "nghich the cua hoan vi A:" ; 
	PrintArray(C, n);
	
	timhoanvi(B,C,n);
	cout << "hoan vi cua nghich the B:";
	PrintArray(C, n);
	return 0;
}
