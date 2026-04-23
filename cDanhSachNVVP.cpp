#include "cDanhSachNVVP.h"
#include <iostream>
#include <iomanip>

using namespace std;

cDanhSachNVVP::cDanhSachNVVP() : n(0), ds(nullptr) {}

cDanhSachNVVP::~cDanhSachNVVP() {
    if (ds != nullptr) delete[] ds;
}

void cDanhSachNVVP::nhap() {
    do {
        cout << "Nhap so luong nhan vien van phong: ";
        cin >> n;
    } while (n <= 0);

    if (ds != nullptr) delete[] ds;
    ds = new cNhanVienVP[n];

    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        ds[i].nhap();
    }
}

void cDanhSachNVVP::xuat() const {
    cout << "\n--- DANH SACH NHAN VIEN ---" << endl;
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
}

void cDanhSachNVVP::timMaxLuong() const {
    if (n == 0) return;
    double maxLuong = ds[0].getLuong();

    // Tìm mức lương cao nhất
    for (int i = 1; i < n; i++) {
        if (ds[i].getLuong() > maxLuong) {
            maxLuong = ds[i].getLuong();
        }
    }

    cout << "\n--- NHAN VIEN CO LUONG CAO NHAT (" << fixed << setprecision(0) << maxLuong << " VND) ---" << endl;
    // In ra tất cả những ai đạt mức lương này (trường hợp có nhiều người cùng mức lương max)
    for (int i = 0; i < n; i++) {
        if (ds[i].getLuong() == maxLuong) {
            ds[i].xuat();
        }
    }
}

double cDanhSachNVVP::tinhTongLuong() const {
    double tong = 0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].getLuong();
    }
    return tong;
}

void cDanhSachNVVP::timNguoiLonTuoiNhat() const {
    if (n == 0) return;

    // Giả sử người đầu tiên lớn tuổi nhất
    cNhanVienVP oldest = ds[0];

    for (int i = 1; i < n; i++) {
        if (ds[i].getNgaySinh().lonTuoiHon(oldest.getNgaySinh())) {
            oldest = ds[i];
        }
    }

    cout << "\nNHAN VIEN LON TUOI NHAT" << endl;
    // In ra những người có cùng ngày sinh với người lớn tuổi nhất
    for (int i = 0; i < n; i++) {
        if (!ds[i].getNgaySinh().lonTuoiHon(oldest.getNgaySinh()) &&
            !oldest.getNgaySinh().lonTuoiHon(ds[i].getNgaySinh())) {
            ds[i].xuat();
        }
    }
}

void cDanhSachNVVP::sapXepTangDanTheoLuong() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].getLuong() > ds[j].getLuong()) {
                cNhanVienVP temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}