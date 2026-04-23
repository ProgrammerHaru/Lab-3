#include <iostream>
#include <iomanip>
#include "cDanhSachNVSX.h"

using namespace std;

int main() {
    cDanhSachNVSX congTy;

    cout << "Chuong trinh quan ly NV san xuat" << endl;
    congTy.nhap();

    congTy.xuat();

    congTy.timMinLuong();

    cout << "\n=> Tong luong cong ty phai tra: "
        << fixed << setprecision(0) << congTy.tinhTongLuong() << " VND" << endl;

    congTy.timNguoiLonTuoiNhat();

    cout << "\nDanh sach sau khi sap xep tang dan theo luong" << endl;
    congTy.sapXepTangDanTheoLuong();
    congTy.xuat();

    return 0;
}