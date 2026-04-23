#pragma once
#include "cDiem.h"

class cTamGiac {
private:
    cDiem A, B, C;

    // Hàm hỗ trợ kiểm tra số thực bằng nhau
    bool isEqual(double a, double b) const;

public:
    cTamGiac();
    cTamGiac(cDiem a, cDiem b, cDiem c);
    ~cTamGiac();

    void nhap();
    void xuat() const;

    bool laTamGiacHopLe() const;
    void kiemTraLoai() const;
    double tinhChuVi() const;
    double tinhDienTich() const;

    void tinhTien(double dx, double dy);
    void quay(double gocDo);
    void phongTo(double k);
    void thuNho(double k);
};