#include "cTamGiac.h"
#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

// Hàm khởi tạo
cTamGiac::cTamGiac() {}
cTamGiac::cTamGiac(cDiem a, cDiem b, cDiem c) : A(a), B(b), C(c) {}
cTamGiac::~cTamGiac() {}

bool cTamGiac::isEqual(double a, double b) const {
    return abs(a - b) < 1e-5;
}

void cTamGiac::nhap() {
    cout << "Nhap toa do dinh A (x y): "; A.nhap();
    cout << "Nhap toa do dinh B (x y): "; B.nhap();
    cout << "Nhap toa do dinh C (x y): "; C.nhap();
}

void cTamGiac::xuat() const {
    cout << "Tam giac: A"; A.xuat();
    cout << ", B"; B.xuat();
    cout << ", C"; C.xuat();
    cout << endl;
}

bool cTamGiac::laTamGiacHopLe() const {
    double a = B.tinhKhoangCach(C);
    double b = A.tinhKhoangCach(C);
    double c = A.tinhKhoangCach(B);
    return (a + b > c) && (a + c > b) && (b + c > a);
}

void cTamGiac::kiemTraLoai() const {
    if (!laTamGiacHopLe()) {
        cout << "Day khong phai tam giac hop le!" << endl;
        return;
    }

    double a = B.tinhKhoangCach(C);
    double b = A.tinhKhoangCach(C);
    double c = A.tinhKhoangCach(B);

    bool vuong = isEqual(a * a + b * b, c * c) || isEqual(a * a + c * c, b * b) || isEqual(b * b + c * c, a * a);
    bool can = isEqual(a, b) || isEqual(a, c) || isEqual(b, c);
    bool deu = isEqual(a, b) && isEqual(b, c);

    cout << "=> Loai tam giac: ";
    if (deu) cout << "Tam giac deu\n";
    else if (vuong && can) cout << "Tam giac vuong can\n";
    else if (vuong) cout << "Tam giac vuong\n";
    else if (can) cout << "Tam giac can\n";
    else cout << "Tam giac thuong\n";
}

double cTamGiac::tinhChuVi() const {
    if (!laTamGiacHopLe()) return 0;
    return B.tinhKhoangCach(C) + A.tinhKhoangCach(C) + A.tinhKhoangCach(B);
}

double cTamGiac::tinhDienTich() const {
    if (!laTamGiacHopLe()) return 0;
    double a = B.tinhKhoangCach(C);
    double b = A.tinhKhoangCach(C);
    double c = A.tinhKhoangCach(B);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c)); // Công thức Heron
}

void cTamGiac::tinhTien(double dx, double dy) {
    A.tinhTien(dx, dy);
    B.tinhTien(dx, dy);
    C.tinhTien(dx, dy);
}

void cTamGiac::quay(double gocDo) {
    double gocRad = gocDo * PI / 180.0;
    A.quay(gocRad);
    B.quay(gocRad);
    C.quay(gocRad);
}

void cTamGiac::phongTo(double k) {
    if (k <= 0) return;
    A.phongToThuNho(k);
    B.phongToThuNho(k);
    C.phongToThuNho(k);
}

void cTamGiac::thuNho(double k) {
    if (k <= 0) return;
    phongTo(1.0 / k);
}