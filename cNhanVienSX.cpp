#include "cNhanVienSX.h"
#include <iostream>
#include <iomanip>

using namespace std;

void NgayThangNam::nhap() {
    cin >> ngay >> thang >> nam;
}

void NgayThangNam::xuat() const {
    cout << (ngay < 10 ? "0" : "") << ngay << "/"
        << (thang < 10 ? "0" : "") << thang << "/"
        << nam;
}

bool NgayThangNam::lonTuoiHon(const NgayThangNam& khac) const {
    if (nam != khac.nam) return nam < khac.nam;
    if (thang != khac.thang) return thang < khac.thang;
    return ngay < khac.ngay;
}

cNhanVienSX::cNhanVienSX() : maNV(""), hoTen(""), soSanPham(0), donGia(0) {
    ngaySinh.ngay = 1; ngaySinh.thang = 1; ngaySinh.nam = 2000;
}

double cNhanVienSX::tinhLuong() const {
    return soSanPham * donGia;
}

NgayThangNam cNhanVienSX::getNgaySinh() const {
    return ngaySinh;
}

void cNhanVienSX::nhap() {
    cin.ignore(); // Xóa bộ nhớ đệm trước khi nhập chuỗi
    cout << "Nhap ma NV: ";
    getline(cin, maNV);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (ngay thang nam, cach nhau khoang trang): ";
    ngaySinh.nhap();
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
    cout << "Nhap don gia 1 san pham: ";
    cin >> donGia;
}

void cNhanVienSX::xuat() const {
    cout << "Ma NV: " << maNV << " | Ho ten: " << hoTen << " | Ngay sinh: ";
    ngaySinh.xuat();
    cout << " | So SP: " << soSanPham << " | Don gia: " << fixed << setprecision(0) << donGia
        << " | Luong: " << tinhLuong() << " VND" << endl;
}