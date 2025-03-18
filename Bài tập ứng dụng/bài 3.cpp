#include <iostream>
usingnamespace std;

struct phongthi {
    int sophong;
    char nha;
    int khanangchua;
};

const int MAX_PHONG_THI = 200; // so phong thi toi da

int main() {p
    phongthi danhsachphongthi[MAX_PHONG_THI] = {
        {101, 'A', 150},
        {102, 'B', 200},
        {103, 'A', 100},
        {104, 'C', 250},
        {105, 'B', 180}
    };
int soluongphongthi = 5; // so phong thi

//sap xep va in theo kha nang chua giam dan
for (int i = 0; i < soluongphongthi - 1; i++) {
    for (int j = i + 1; j < soluongphongthi; j++) {
        if (danhsachphongthi[i].khanangchua < danhsachphongthi[j].khanangchua) {
            phongthi temp = danhsachphongthi[i];
            danhsachphongthi[i] = danhsachphongthi[j];
            danhsachphongthi[j] = temp;
        }
    }
}
std::cout << "Danh sach phong thi sap xep theo kha nang chua giam dan:\n";
for (int i = 0; i < soluongphongthi; i++) {
    std::cout << "So Phong " << danhsachphongthi[i].sophong << ", Nha " << danhsachphongthi[i].nha << ", Kha nang chua: " << danhsachphongthi[i].khanangchua << std::endl;
}
std::cout << std::endl;

//sap xep va in theo nha tang dan, so phong tang dan
for (int i = 0; i < soluongphongthi - 1; i++) {
    for (int j = i + 1; j < soluongphongthi; j++) {
        if (danhsachphongthi[i].nha > danhsachphongthi[j].nha || (danhsachphongthi[i].nha == danhsachphongthi[j].nha && danhsachphongthi[i].sophong > danhsachphongthi[j].sophong)) {
            phongthi temp = danhsachphongthi[i];
            danhsachphongthi[i] = danhsachphongthi[j];
            danhsachphongthi[j] = temp;
        }
    }
}

std::cout << "Danh sach phong thi sap xep theo nha tang dan, so phong tang dan:\n";
for (int i = 0; i < soluongphongthi; i++) {
    std::cout << "So Phong " << danhsachphongthi[i].sophong << ", Nha " << danhsachphongthi[i].nha << ", Kha nang chua: " << danhsachphongthi[i].khanangchua << std::endl;
}
std::cout << std::endl;

//sap xep va in theo nha tang dan, kha nang chua giam dan
for (int i = 0; i < soluongphongthi - 1; i++) {
    for (int j = i + 1; j < soluongphongthi; j++) {
        if (danhsachphongthi[i].nha > danhsachphongthi[j].nha || (danhsachphongthi[i].nha == danhsachphongthi[j].nha && danhsachphongthi[i].khanangchua < danhsachphongthi[j].khanangchua)) {
            phongthi temp = danhsachphongthi[i];
            danhsachphongthi[i] = danhsachphongthi[j];
            danhsachphongthi[j] = temp;
        }
    }
}
std::cout << "Danh sach phong thi sap xep theo nha tang dan, kha nang chua giam dan:\n";
for (int i = 0; i < soluongphongthi; i++) {
    std::cout << "So Phong " << danhsachphongthi[i].sophong << ", Nha " << danhsachphongthi[i].nha << ", Kha nang chua: " << danhsachphongthi[i].khanangchua << std::endl;
}
return 0;
}
