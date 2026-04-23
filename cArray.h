#pragma once

class cArray {
private:
    int n;       // Số lượng phần tử
    int* a;      // Con trỏ quản lý mảng động

    // Hàm hỗ trợ kiểm tra số nguyên tố (để private vì chỉ dùng nội bộ trong lớp)
    bool laSoNguyenTo(int val) const;

public:
    cArray();
    ~cArray();

    void taoNgauNhien(int size);
    void xuat() const;

    int demSoLanXuatHien(int x) const;
    bool kiemTraTangDan() const;

    void timLeNhoNhat() const;
    void timNguyenToLonNhat() const;

    void sapXepTang();
    void sapXepGiam();
};