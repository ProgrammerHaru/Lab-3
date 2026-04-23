#pragma once

class cDaThuc {
private:
    int n; // Bậc của đa thức
    double* heSo; // Mảng động chứa hệ số, phần tử heSo[i] đi với x^i

    // Hàm hỗ trợ chuẩn hóa bậc đa thức (hạ bậc nếu hệ số cao nhất bị triệt tiêu sau khi cộng/trừ)
    void chuanHoa();

public:
    // Các hàm khởi tạo và hủy
    cDaThuc();                                // Khởi tạo đa thức bậc 0
    cDaThuc(int bac);                         // Khởi tạo đa thức khi biết trước bậc
    cDaThuc(const cDaThuc& other);            // Copy Constructor
    ~cDaThuc();                               // Giải phóng bộ nhớ


    void nhap();
    void xuat() const;
    double tinhGiaTri(double x) const;


    cDaThuc cong(const cDaThuc& other) const;
    cDaThuc tru(const cDaThuc& other) const;
};