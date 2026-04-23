#include "cListCandidate.h"
#include <iostream>

using namespace std;

cListCandidate::cListCandidate() : n(0), ds(nullptr) {}

cListCandidate::~cListCandidate() {
    if (ds != nullptr) {
        delete[] ds;
    }
}

void cListCandidate::nhap() {
    do {
        cout << "Nhap so luong thi sinh (n > 0): ";
        cin >> n;
    } while (n <= 0);

    // Cấp phát lại bộ nhớ nếu mảng đã tồn tại
    if (ds != nullptr) delete[] ds;
    ds = new cCandidate[n];

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin thi sinh thu " << i + 1 << " ---" << endl;
        ds[i].nhap();
    }
}

void cListCandidate::xuatTatCa() const {
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
    }
}

void cListCandidate::xuatThiSinhTren15() const {
    cout << "\nDANH SACH THI SINH CO TONG DIEM > 15" << endl;
    bool timThay = false;
    for (int i = 0; i < n; i++) {
        if (ds[i].tinhTongDiem() > 15) {
            ds[i].xuat();
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong co thi sinh nao co tong diem > 15." << endl;
    }
}

void cListCandidate::timThiSinhDiemCaoNhat() const {
    if (n == 0) return;

    cout << "\nTHI SINH CO TONG DIEM CAO NHAT" << endl;
    
    // Tìm mức điểm cao nhất
    float maxDiem = ds[0].tinhTongDiem();
    for (int i = 1; i < n; i++) {
        if (ds[i].tinhTongDiem() > maxDiem) {
            maxDiem = ds[i].tinhTongDiem();
        }
    }
    // In ra tất cả những thí sinh đạt mức điểm cao nhất đó (Phòng trường hợp thủ khoa bằng điểm nhau)
    for (int i = 0; i < n; i++) {
        if (ds[i].tinhTongDiem() == maxDiem) {
            ds[i].xuat();
        }
    }
}

void cListCandidate::sapXepGiamDan() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].tinhTongDiem() < ds[j].tinhTongDiem()) {
                cCandidate temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}