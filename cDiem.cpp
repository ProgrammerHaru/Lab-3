#include "cDiem.h"
#include <iostream>
#include <cmath>

using namespace std;

cDiem::cDiem(double _x, double _y) : x(_x), y(_y) {}

cDiem::~cDiem() {}

void cDiem::nhap() {
    cin >> x >> y;
}

void cDiem::xuat() const {
    cout << "(" << x << ", " << y << ")";
}

double cDiem::tinhKhoangCach(const cDiem& d) const {
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

void cDiem::tinhTien(double dx, double dy) {
    x += dx;
    y += dy;
}

// Quay điểm quanh gốc tọa độ (0,0)
void cDiem::quay(double gocRadian) {
    double x_new = x * cos(gocRadian) - y * sin(gocRadian);
    double y_new = x * sin(gocRadian) + y * cos(gocRadian);
    x = x_new;
    y = y_new;
}

// Phóng to thu nhỏ tỉ lệ k so với gốc tọa độ
void cDiem::phongToThuNho(double k) {
    x *= k;
    y *= k;
}