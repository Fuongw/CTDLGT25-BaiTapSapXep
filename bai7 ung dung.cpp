#include<iostream>
using namespace std ;
int main() {
	int n, a[1000] ;
	cin>> n ;
	for( int i = 0; i < n; i++) {
		cin>> a[i] ;
	}
	
	int index = 0 ;
	for( int i = 0; i < n; i++) {
		if( a[i] % 2 == 0) {
			swap( a[i] , a[index]) ;
			index++ ;
		}
	}
	
	for( int i = 0; i < n; i++) {
		cout<< a[i] << " " ;
	}
	return 0 ;
}