#include<iostream>
using namespace std ;
// Sap xep doi cho truc tiep
void InterchangeSort( int a[] , int n) {
	for( int i = 0; i < n - 1; i++) {
		for( int j = i+1; j < n; j++) {
			if(a[i] > a[j]) {
				swap( a[i] , a[j]) ;
			}
		}
	}
}

// Sap xep chon truc tiep
void SelectionSort( int a[] , int n) {
	int min ;
	for( int i = 0; i < n - 1; i++) {
		min = i ;
		for( int j = i+1; j < n; j++) {
			if( a[j] < a[min]) {
				min = j ;
			if( min != j) {
				swap( a[min] , a[i]) ;
			}
			}
		}
	}
}

// Sap xep chen truc tiep
void InsertionSort( int a[] , int n) {
	int pos , x ;
	for( int i = 0; i < n; i++) {
		x = a[i] ;
		pos = i ;
		while( pos > 0 && x < a[pos-1]) {
			a[pos] = a[pos-1] ;
			pos-- ;
		}
		a[pos] = x ;
	}
}

// Sap xep noi bot
void BubbleSort( int a[] , int n) {
	for( int i = 0; i < n - 1; i++) {
		for( int j = n-1; j > i; j--) {
			if( a[j] < a[j-1]) {
				swap( a[j] , a[j-1]) ;
			}
		}
	}
}

int main() {
	int a[] = {39,8,5,1,3,6,9,12,4,7,10} ;
	int n = sizeof(a) / sizeof(a[0]) ;
	
	InterchangeSort(a, n) ;
	
	SelectionSort(a, n) ;
	
	InsertionSort(a, n) ;
	
	BubbleSort(a, n) ;
	
	for( int i = 0; i < n; i++) {
		cout<< a[i] << " " ;
	}
	
	return 0 ;
}