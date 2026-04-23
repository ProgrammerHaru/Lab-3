#pragma once
#include "cNhanVienSX.h"

class cDanhSachNVSX {
private:
    int n;
    cNhanVienSX* ds;

public:
    cDanhSachNVSX();
    ~cDanhSachNVSX();

    void nhap();
    void xuat() const;

    void timMinLuong() const;
    double tinhTongLuong() const;
    void timNguoiLonTuoiNhat() const;
    void sapXepTangDanTheoLuong();
};