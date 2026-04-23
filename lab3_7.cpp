#include <iostream>
#include <iomanip>
#include "cDanhSachNVVP.h"

using namespace std;

int main() {
    cDanhSachNVVP congTy;

    cout << "CHUONG TRINH QUAN LY NHAN VIEN VAN PHONG" << endl;
    congTy.nhap();

    congTy.xuat();

    congTy.timMaxLuong();

    cout << "\n=> Tong luong cong ty phai tra: "
        << fixed << setprecision(0) << congTy.tinhTongLuong() << " VND" << endl;

    congTy.timNguoiLonTuoiNhat();

    cout << "\nDANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG" << endl;
    congTy.sapXepTangDanTheoLuong();
    congTy.xuat();

    return 0;
}