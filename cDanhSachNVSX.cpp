#include "cDanhSachNVSX.h"
#include <iostream>
#include <iomanip>

using namespace std;

cDanhSachNVSX::cDanhSachNVSX() : n(0), ds(nullptr) {}

cDanhSachNVSX::~cDanhSachNVSX() {
    if (ds != nullptr) delete[] ds;
}

void cDanhSachNVSX::nhap() {
    do {
        cout << "Nhap so luong nhan vien san xuat: ";
        cin >> n;
    } while (n <= 0);

    if (ds != nullptr) delete[] ds;
    ds = new cNhanVienSX[n];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << endl;
        ds[i].nhap();
    }
}

void cDanhSachNVSX::xuat() const {
    cout << "\nDanh sach nhan vien san xuat" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
}

void cDanhSachNVSX::timMinLuong() const {
    if (n == 0) return;
    double minLuong = ds[0].tinhLuong();

    for (int i = 1; i < n; i++) {
        if (ds[i].tinhLuong() < minLuong) {
            minLuong = ds[i].tinhLuong();
        }
    }

    cout << "\nNhan vien co luong thap nhat(" << fixed << setprecision(0) << minLuong << " VND)" << endl;
    for (int i = 0; i < n; i++) {
        if (ds[i].tinhLuong() == minLuong) {
            ds[i].xuat();
        }
    }
}

double cDanhSachNVSX::tinhTongLuong() const {
    double tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].tinhLuong();
    }
    return tong;
}

void cDanhSachNVSX::timNguoiLonTuoiNhat() const {
    if (n == 0) return;

    cNhanVienSX oldest = ds[0];

    for (int i = 1; i < n; i++) {
        if (ds[i].getNgaySinh().lonTuoiHon(oldest.getNgaySinh())) {
            oldest = ds[i];
        }
    }

    cout << "\nNhan vien lon tuoi nhat" << endl;
    for (int i = 0; i < n; i++) {
        if (!ds[i].getNgaySinh().lonTuoiHon(oldest.getNgaySinh()) &&
            !oldest.getNgaySinh().lonTuoiHon(ds[i].getNgaySinh())) {
            ds[i].xuat();
        }
    }
}

void cDanhSachNVSX::sapXepTangDanTheoLuong() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].tinhLuong() > ds[j].tinhLuong()) {
                cNhanVienSX temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}