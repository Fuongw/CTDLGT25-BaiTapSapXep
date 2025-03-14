#include <iostream>
usingnamespace std;

//a. dinh nghia cau truc du lieu de luu tru cac du lieu trong bo nho trong cua may tinh
struct Sohang {
    double heso;
    int bac;
};

//b. van dung mot thuat toan
double tinhgiatri(Sohang a[], int n, double x) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        double t = 1;
        for (int j = 0; j < a[i].bac; j++) {
            t *= x;
        }
        s += a[i].heso * t;
    }
    return s;
}

//sap xep cac so hang trong day theo thu tu tang dan cua cac bac
int main() {
    int n;
    cout << "Nhap so luong so hang: ";
    cin >> n;
    Sohang* a = new Sohang[n]; // cap phat bo nho dong cho mang a co n phan tu

    for (int i = 0; i < n; i++) {
        cout << "Nhap he so cua so hang thu " << i + 1 << ": ";
        cin >> a[i].heso;
        do{
            cout << "Nhap bac cua so hang thu " << i + 1 << ": ";
            cin >> a[i].bac;
            if (a[i].bac < 0 || a[i].bac > 100){
                cout << "Bac khong hop le, nhap lai!" << endl;
            }
        }while(a[i].bac < 0 || a[i].bac > 100);

    }

    // sap xep cac so hang theo bac tang dan
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].bac > a[j + 1].bac) {
                Sohang temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Cac so hang sau khi sap xep theo bac tang dan: " << endl;
    for(int i = 0; i < n; i++){
        cout << a[i].heso << "x^" << a[i].bac << endl;
    }

    cout << "Nhap x: ";
    double x;
    cin >> x;
    cout << "Gia tri cua da thuc tai x = " << x << " la: " << tinhgiatri(a, n, x) << endl;

    delete[] a; // giai phong bo nho

    return 0;
}

