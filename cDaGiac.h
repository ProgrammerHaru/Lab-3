#pragma once
#include "cDiem.h"

class cDaGiac {
private:
    int n; // Số lượng đỉnh
    cDiem* dinh; // Con trỏ quản lý mảng động các đỉnh

public:
    cDaGiac();
    ~cDaGiac();

    void nhap();
    void xuat() const;

    double tinhChuVi() const;
    double tinhDienTich() const;

    void tinhTien(double dx, double dy);
    void quay(double gocDo);
    void phongTo(double k);
    void thuNho(double k);
};