#pragma once

class cDiem {
private:
    double x, y;

public:
    // Khởi tạo và hủy bỏ
    cDiem(double _x = 0, double _y = 0);
    ~cDiem();

    // Nhập, xuất
    void nhap();
    void xuat() const;

    // Các phương thức toán học
    double tinhKhoangCach(const cDiem& d) const;
    void tinhTien(double dx, double dy);
    void quay(double gocRadian);
    void phongToThuNho(double k);
};