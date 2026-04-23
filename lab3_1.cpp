#include <iostream>
#include "cTamGiac.h"

using namespace std;

int main() {
    cTamGiac tg;
    cout << "Nhap tam giac" << endl;
    tg.nhap();

    if (!tg.laTamGiacHopLe()) {
        cout << "Loi: 3 diem khong tao thanh tam giac!" << endl;
        return 1;
    }

    cout << "\nThong tin tam giac" << endl;
    tg.xuat();
    tg.kiemTraLoai();
    cout << "Chu vi: " << tg.tinhChuVi() << endl;
    cout << "Dien tich: " << tg.tinhDienTich() << endl;

    cout << "\nKiem thu phep doi" << endl;

    cout << "1. Tinh tien vector(2, 3):" << endl;
    tg.tinhTien(2, 3);
    tg.xuat();

    cout << "2. Phong to len 2 lan:" << endl;
    tg.phongTo(2);
    tg.xuat();

    cout << "3. Quay 90 do:" << endl;
    tg.quay(90);
    tg.xuat();

    return 0;
}