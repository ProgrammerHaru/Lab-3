#pragma once
#include <string>

using namespace std;

struct NgayThangNam {
    int ngay, thang, nam;

    void nhap();
    void xuat() const;
    
    // Hàm kiểm tra xem ngày hiện tại có sinh TRƯỚC ngày kia không (tức là lớn tuổi hơn)
    bool lonTuoiHon(const NgayThangNam& khac) const;
};

class cNhanVienVP {
private:
    string maNV;
    string hoTen;
    NgayThangNam ngaySinh;
    double luong;

public:
    cNhanVienVP();
    
    // Các hàm Getter cần thiết để so sánh từ bên ngoài
    double getLuong() const;
    NgayThangNam getNgaySinh() const;

    void nhap();
    void xuat() const;
};