#include<iostream>
#include<fstream>
using namespace std;

// Khai bao thong tin sinh vien
struct SinhVien {
    int MaSo;
    char HovaDem[20];
    char Tensv[40];
    int Ngay, Thang, Nam;
    char Phai[4];
    float DiemTB;
};

// Khai bao ham kiem tra trung ma
bool TrungMa(SinhVien ds[], int n, int MaSo);

void NhapDanhSach(SinhVien ds[], int &n) { // Nhap toi thieu 10 sinh vien
    cout << "Nhap so luong sinh vien: "; 
    cin >> n;
    while (n < 10) {
        cout << "Nhap lai: ";
        cin >> n;
    }
    
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        
        do {
            cout << "Ma so: ";
            cin >> ds[i].MaSo;
            if (TrungMa(ds, i, ds[i].MaSo)) {
                cout << "Ma so bi trung. Nhap lai.\n";
            }
        } while (TrungMa(ds, i, ds[i].MaSo));
        
        cin.ignore();
        cout << "Ho va dem: ";
        cin.getline(ds[i].HovaDem, 20);
        cout << "Ten: ";
        cin.getline(ds[i].Tensv, 40);
        cout << "Ngay sinh (dd mm yyyy): ";
        cin >> ds[i].Ngay >> ds[i].Thang >> ds[i].Nam;
        cout << "Phai (Nam/Nu): ";
        cin >> ds[i].Phai;
        cout << "Diem trung binh: ";
        cin >> ds[i].DiemTB;
    }
}

bool TrungMa(SinhVien ds[], int n, int MaSo) { // Kiem tra ma so trung
    for (int i = 0; i < n; i++) {
        if (ds[i].MaSo == MaSo)
            return true;
    }
    return false;
}

void GhiFile(SinhVien ds[], int n) {
    ofstream file("SINHVIEN.DAT", ios::binary);
    if (!file) {
        cout << "Loi mo file";
        return;
    }
    file.write((char*)ds, n * sizeof(SinhVien));
    file.close();
    cout << "Da luu danh sach sinh vien vao SINHVIEN.DAT" << endl;
}

// Sap xep danh sach theo thu tu tang dan
void SapXepTheoMa(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].MaSo > ds[j].MaSo) {
                SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void XuatDanhSach(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Ma so: " << ds[i].MaSo;
        cout << "Ho va dem: " << ds[i].HovaDem;
        cout << "Ten: " << ds[i].Tensv;
        cout << "Ngay sinh: " << ds[i].Ngay << "/" << ds[i].Thang << "/" << ds[i].Nam;
        cout << "Phai: " << ds[i].Phai;
        cout << "Diem trung binh: " << ds[i].DiemTB << "\n";
    }
}

int main() {
    SinhVien ds[100];
    int n;
    
    NhapDanhSach(ds, n);
    SapXepTheoMa(ds, n);
    GhiFile(ds, n);
    XuatDanhSach(ds, n);
    
    return 0;
}
