#include "cCandidate.h"
#include <iostream>

using namespace std;

cCandidate::cCandidate() : ma(""), ten(""), ngaySinh(""), diemToan(0), diemVan(0), diemAnh(0) {}

void cCandidate::nhap() {
    // Xóa bộ nhớ đệm trước khi dùng getline để tránh lỗi trôi lệnh khi nhập chuỗi
    cin.ignore();

    cout << "Nhap ma thi sinh: ";
    getline(cin, ma);

    cout << "Nhap ten thi sinh: ";
    getline(cin, ten);

    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);

    cout << "Nhap diem Toan, Van, Anh (cach nhau boi khoang trang): ";
    cin >> diemToan >> diemVan >> diemAnh;
}

void cCandidate::xuat() const {
    cout << "[Ma: " << ma << " | Ten: " << ten
        << " | Ngay sinh: " << ngaySinh
        << " | Toan: " << diemToan << ", Van: " << diemVan << ", Anh: " << diemAnh
        << " | TONG: " << tinhTongDiem() << "]" << endl;
}

float cCandidate::tinhTongDiem() const {
    return diemToan + diemVan + diemAnh;
}