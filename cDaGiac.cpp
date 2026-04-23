#include "cDaGiac.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

cDaGiac::cDaGiac() : n(0), dinh(nullptr) {}
//Giải phóng bộ nhớ
cDaGiac::~cDaGiac() {
    if (dinh != nullptr) {
        delete[] dinh;
    }
}

void cDaGiac::nhap() {
    do {
        cout << "Nhap so luong dinh cua da giac (n >= 3): ";
        cin >> n;
    } while (n < 3);
    // Dọn dẹp bộ nhớ nếu đã có mảng từ trước
    if (dinh != nullptr) delete[] dinh;

    dinh = new cDiem[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap toa do dinh thu " << i + 1 << " (x y): ";
        dinh[i].nhap();
    }
}

void cDaGiac::xuat() const {
    cout << "Da giac " << n << " dinh: ";
    for (int i = 0; i < n; i++) {
        dinh[i].xuat();
        if (i < n - 1) cout << " - ";
    }
    cout << endl;
}

double cDaGiac::tinhChuVi() const {
    if (n < 3) return 0;
    double chuVi = 0;
    for (int i = 0; i < n; i++) {
        chuVi += dinh[i].tinhKhoangCach(dinh[(i + 1) % n]);
    } // Nối điểm hiện tại với điểm kế tiếp. Điểm cuối (n-1) nối với điểm đầu (0).
    return chuVi;
}
// Tính diện tích bằng công thức tọa độ dây giày (Shoelace Formula)
double cDaGiac::tinhDienTich() const {
    if (n < 3) return 0;
    double dienTich = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        dienTich += (dinh[i].getX() * dinh[j].getY()) - (dinh[j].getX() * dinh[i].getY());
    }
    return abs(dienTich) / 2.0;
}

void cDaGiac::tinhTien(double dx, double dy) {
    for (int i = 0; i < n; i++) {
        dinh[i].tinhTien(dx, dy);
    }
}

void cDaGiac::quay(double gocDo) {
    double gocRad = gocDo * PI / 180.0;
    for (int i = 0; i < n; i++) {
        dinh[i].quay(gocRad);
    }
}

void cDaGiac::phongTo(double k) {
    if (k <= 0) return;
    for (int i = 0; i < n; i++) {
        dinh[i].phongToThuNho(k);
    }
}

void cDaGiac::thuNho(double k) {
    if (k <= 0) return;
    phongTo(1.0 / k);
}

