#pragma once

class cDiem {
private:
    double x, y;

public:
    cDiem(double _x = 0, double _y = 0);
    ~cDiem();

    void nhap();
    void xuat() const;
    // Getter để lấy tọa độ phục vụ tính diện tích đa giác
    double getX() const;
    double getY() const;

    double tinhKhoangCach(const cDiem& d) const;
    void tinhTien(double dx, double dy);
    void quay(double gocRadian);
    void phongToThuNho(double k);
};