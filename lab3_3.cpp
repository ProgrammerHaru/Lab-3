#include <iostream>
#include "cDSPhanSo.h"

using namespace std;

int main() {
    cDSPhanSo list;

    cout << "Nhap danh sach phan so" << endl;
    list.nhap();

    cout << "\nDanh sach vua nhap" << endl;
    list.xuat();

    cout << "\nKiem thu cac chuc nang" << endl;

    cout << "1. Tong cac phan so: ";
    cPhanSo tong = list.tinhTong();
    tong.xuat(); cout << endl;

    cout << "2. Phan so lon nhat: ";
    cPhanSo max = list.timMax();
    max.xuat(); cout << endl;

    cout << "3. Phan so nho nhat: ";
    cPhanSo min = list.timMin();
    min.xuat(); cout << endl;

    cout << "4. ";
    list.timTuNguyenToMax();

    cout << "5. Sap xep danh sach TANG DAN:" << endl;
    list.sapXepTang();
    list.xuat();

    cout << "6. Sap xep danh sach GIAM DAN:" << endl;
    list.sapXepGiam();
    list.xuat();

    return 0;
}