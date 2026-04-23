#include "cNhanVienVP.h"
#include <iostream>
#include <iomanip> // Dùng để định dạng xuất tiền lương

using namespace std;

//Cài đặt NgayThangNam
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

cNhanVienVP::cNhanVienVP() : maNV(""), hoTen(""), luong(0) {
    ngaySinh.ngay = 1; ngaySinh.thang = 1; ngaySinh.nam = 2000;
}

double cNhanVienVP::getLuong() const { return luong; }
NgayThangNam cNhanVienVP::getNgaySinh() const { return ngaySinh; }

void cNhanVienVP::nhap() {
    cin.ignore();
    cout << "Nhap ma NV: ";
    getline(cin, maNV);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (ngay thang nam, cach nhau boi khoang trang): ";
    ngaySinh.nhap();
    cout << "Nhap luong: ";
    cin >> luong;
}

void cNhanVienVP::xuat() const {
    cout << "Ma NV: " << maNV << " | Ho ten: " << hoTen << " | Ngay sinh: ";
    ngaySinh.xuat();
    cout << " | Luong: " << fixed << setprecision(0) << luong << " VND" << endl;
}