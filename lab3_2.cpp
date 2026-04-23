#include <iostream>
#include "cDaGiac.h"

using namespace std;

int main() {
    cDaGiac dg;
    cout << "Nhap da giac" << endl;
    dg.nhap();

    cout << "\nThong tin da giac" << endl;
    dg.xuat();
    cout << "Chu vi: " << dg.tinhChuVi() << endl;
    cout << "Dien tich: " << dg.tinhDienTich() << endl;

    cout << "\nKiem thu phep bien doi" << endl;

    cout << "1. Tinh tien vector(2, 2):" << endl;
    dg.tinhTien(2, 2);
    dg.xuat();

    cout << "2. Phong to len 2 lan:" << endl;
    dg.phongTo(2);
    dg.xuat();

    cout << "3. Quay 90 do:" << endl;
    dg.quay(90);
    dg.xuat();

    return 0;
}