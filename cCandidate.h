#pragma once
#include <string>

using namespace std;

class cCandidate {
private:
    string ma;
    string ten;
    string ngaySinh;
    float diemToan, diemVan, diemAnh;

public:
    cCandidate();

    void nhap();
    void xuat() const;

    // Hàm tính tổng điểm
    float tinhTongDiem() const;
};