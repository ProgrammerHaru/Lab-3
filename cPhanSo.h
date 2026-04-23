#pragma once

class cPhanSo {
private:
    int tu, mau;

public:
    cPhanSo(int _tu = 0, int _mau = 1);

    void nhap();
    void xuat() const;
    void rutGon();

    // Trả về giá trị thực để so sánh lớn/nhỏ
    double tinhGiaTri() const;

    // Phép cộng dùng để tính tổng
    cPhanSo cong(const cPhanSo& other) const;

    // Lấy tử số ra để kiểm tra số nguyên tố
    int getTu() const;
};