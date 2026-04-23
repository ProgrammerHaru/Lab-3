#include "cArray.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Hàm hỗ trợ kiểm tra số nguyên tố
bool cArray::laSoNguyenTo(int val) const {
    if (val < 2) return false;
    for (int i = 2; i <= sqrt(val); i++) {
        if (val % i == 0) return false;
    }
    return true;
}

// Khởi tạo
cArray::cArray() : n(0), a(nullptr) {}

// Giải phóng bộ nhớ
cArray::~cArray() {
    if (a != nullptr) {
        delete[] a;
    }
}

void cArray::taoNgauNhien(int size) {
    if (size <= 0) return;

    // Dọn dẹp mảng cũ nếu có
    if (a != nullptr) {
        delete[] a;
    }

    n = size;
    a = new int[n];

    for (int i = 0; i < n; i++) {
        // Sinh số ngẫu nhiên từ 1 đến 100
        a[i] = rand() % 100 + 1;
    }
}

void cArray::xuat() const {
    if (n == 0) {
        cout << "Mang rong!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int cArray::demSoLanXuatHien(int x) const {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

bool cArray::kiemTraTangDan() const {
    if (n <= 1) return true;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return false; // Phát hiện phần tử trước lớn hơn phần tử sau
        }
    }
    return true;
}

void cArray::timLeNhoNhat() const {
    int minLe = -1;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) { // Kiểm tra số lẻ
            if (!found || a[i] < minLe) {
                minLe = a[i];
                found = true;
            }
        }
    }

    if (found) {
        cout << "So le nho nhat trong mang la: " << minLe << endl;
    }
    else {
        cout << "Khong co so le nao trong mang!" << endl;
    }
}

void cArray::timNguyenToLonNhat() const {
    int maxNT = -1;
    bool found = false;

    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) { // Kiểm tra số nguyên tố
            if (!found || a[i] > maxNT) {
                maxNT = a[i];
                found = true;
            }
        }
    }

    if (found) {
        cout << "So nguyen to lon nhat trong mang la: " << maxNT << endl;
    }
    else {
        cout << "Khong co so nguyen to nao trong mang!" << endl;
    }
}

void cArray::sapXepTang() {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        swap(a[i], a[min_idx]);
    }
}

void cArray::sapXepGiam() {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[max_idx]) {
                max_idx = j;
            }
        }
        swap(a[i], a[max_idx]);
    }
}