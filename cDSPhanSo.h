#pragma once
#include "cPhanSo.h"

class cDSPhanSo {
private:
    int n;          // Số lượng phân số
    cPhanSo* ds;    // Mảng động

public:
    cDSPhanSo();
    ~cDSPhanSo();

    void nhap();
    void xuat() const;

    cPhanSo tinhTong() const;
    cPhanSo timMax() const;
    cPhanSo timMin() const;
    void timTuNguyenToMax() const;

    void sapXepTang();
    void sapXepGiam();
};