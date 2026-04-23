#include "cPhanSo.h"
#include <iostream>
#include <cmath>

using namespace std;

// Hàm hỗ trợ tìm Ước chung lớn nhất
int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

cPhanSo::cPhanSo(int _tu, int _mau) : tu(_tu), mau(_mau) {}

void cPhanSo::nhap() {
    cout << "Nhap tu so: "; cin >> tu;
    do {
        cout << "Nhap mau so (khac 0): "; cin >> mau;
    } while (mau == 0);
}

void cPhanSo::xuat() const {
    if (mau == 1) cout << tu;
    else if (mau < 0) cout << -tu << "/" << -mau; // Chuyển dấu trừ lên tử
    else cout << tu << "/" << mau;
}

void cPhanSo::rutGon() {
    int ucln = UCLN(tu, mau);
    if (ucln != 0) {
        tu /= ucln;
        mau /= ucln;
    }
    // Chuẩn hóa dấu
    if (mau < 0) {
        tu = -tu;
        mau = -mau;
    }
}

double cPhanSo::tinhGiaTri() const {
    return (double)tu / mau;
}

cPhanSo cPhanSo::cong(const cPhanSo& other) const {
    cPhanSo kq;
    kq.tu = tu * other.mau + other.tu * mau;
    kq.mau = mau * other.mau;
    kq.rutGon();
    return kq;
}

int cPhanSo::getTu() const {
    return tu;
}