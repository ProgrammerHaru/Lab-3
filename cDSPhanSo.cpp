#include "cDSPhanSo.h"
#include <iostream>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

cDSPhanSo::cDSPhanSo() : n(0), ds(nullptr) {}

cDSPhanSo::~cDSPhanSo() {
    if (ds != nullptr) {
        delete[] ds;
    }
}

void cDSPhanSo::nhap() {
    do {
        cout << "Nhap so luong phan so: "; cin >> n;
    } while (n <= 0);

    if (ds != nullptr) delete[] ds;

    ds = new cPhanSo[n];
    for (int i = 0; i < n; i++) {
        cout << "--- Phan so thu " << i + 1 << " ---" << endl;
        ds[i].nhap();
    }
}

void cDSPhanSo::xuat() const {
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
        if (i < n - 1) cout << " ; ";
    }
    cout << endl;
}

cPhanSo cDSPhanSo::tinhTong() const {
    cPhanSo tong(0, 1);
    for (int i = 0; i < n; i++) {
        tong = tong.cong(ds[i]);
    }
    return tong;
}

cPhanSo cDSPhanSo::timMax() const {
    cPhanSo max = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].tinhGiaTri() > max.tinhGiaTri()) {
            max = ds[i];
        }
    }
    return max;
}

cPhanSo cDSPhanSo::timMin() const {
    cPhanSo min = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].tinhGiaTri() < min.tinhGiaTri()) {
            min = ds[i];
        }
    }
    return min;
}

void cDSPhanSo::timTuNguyenToMax() const {
    int maxTu = -1;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int tuHienTai = abs(ds[i].getTu()); // Xét giá trị tuyệt đối
        if (laSoNguyenTo(tuHienTai)) {
            if (maxTu == -1 || tuHienTai > maxTu) {
                maxTu = tuHienTai;
                index = i;
            }
        }
    }

    if (index != -1) {
        cout << "Phan so co tu la so nguyen to lon nhat la: ";
        ds[index].xuat();
        cout << endl;
    }
    else {
        cout << "Khong co phan so nao co tu la so nguyen to!" << endl;
    }
}

void cDSPhanSo::sapXepTang() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].tinhGiaTri() > ds[j].tinhGiaTri()) {
                cPhanSo temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

void cDSPhanSo::sapXepGiam() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].tinhGiaTri() < ds[j].tinhGiaTri()) {
                cPhanSo temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}