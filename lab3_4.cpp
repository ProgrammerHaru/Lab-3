#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cArray.h"

using namespace std;

int main() {
    srand(time(0));
    // Khởi tạo seed cho hàm rand() dựa trên thời gian thực
    // Giúp mảng sinh ra khác nhau ở mỗi lần chạy chương trình
    cArray mang;
    int soLuong;

    cout << "Nhap so luong phan tu muon tao ngau nhien: ";
    cin >> soLuong;

    mang.taoNgauNhien(soLuong);

    cout << "\n1. Mang ngau nhien vua tao:\n";
    mang.xuat();

    int x;
    cout << "\n2. Nhap gia tri x can dem: ";
    cin >> x;
    cout << "=> So lan xuat hien cua " << x << " la: " << mang.demSoLanXuatHien(x) << endl;

    cout << "\n3. Kiem tra mang tang dan: " << (mang.kiemTraTangDan() ? "Dung" : "Sai") << endl;

    cout << "\n4. ";
    mang.timLeNhoNhat();

    cout << "\n5. ";
    mang.timNguyenToLonNhat();

    cout << "\n6. Sap xep mang TANG DAN:\n";
    mang.sapXepTang();
    mang.xuat();

    cout << "Kiem tra lai xem mang da tang dan chua: " << (mang.kiemTraTangDan() ? "Dung" : "Sai") << endl;

    cout << "\n7. Sap xep mang GIAM DAN:\n";
    mang.sapXepGiam();
    mang.xuat();

    return 0;
}