#pragma once
#include <string>

using namespace std;

//cấu trúc ngày sinh
struct NgayThangNam {
    int ngay, thang, nam;

    void nhap();
    void xuat() const;

    // Hàm kiểm tra xem ngày hiện tại có sinh trước ngày kia không (lớn tuổi hơn)
    bool lonTuoiHon(const NgayThangNam& khac) const;
};

class cNhanVienSX {
private:
    string maNV;
    string hoTen;
    NgayThangNam ngaySinh;
    int soSanPham;
    double donGia;

public:
    cNhanVienSX();

    // Các hàm Getter
    double tinhLuong() const;
    NgayThangNam getNgaySinh() const;

    void nhap();
    void xuat() const;
};