#pragma once
#include "cNhanVienVP.h"

class cDanhSachNVVP {
private:
    int n;
    cNhanVienVP* ds;

public:
    cDanhSachNVVP();
    ~cDanhSachNVVP();

    void nhap();
    void xuat() const;

    void timMaxLuong() const;
    double tinhTongLuong() const;
    void timNguoiLonTuoiNhat() const;
    void sapXepTangDanTheoLuong();
};