#include "cDaThuc.h"
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Hàm chuẩn hóa: Lùi bậc n nếu hệ số của bậc n bằng 0
void cDaThuc::chuanHoa() {
    while (n > 0 && heSo[n] == 0) {
        n--;
    }
}

// Khởi tạo đa thức bậc 0 (P(x) = 0)
cDaThuc::cDaThuc() : n(0) {
    heSo = new double[1];
    heSo[0] = 0;
}

// Khởi tạo mảng khi biết trước bậc
cDaThuc::cDaThuc(int bac) : n(bac) {
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        heSo[i] = 0;
    }
}

// Copy Constructor: Đảm bảo sao chép mảng an toàn khi return object
cDaThuc::cDaThuc(const cDaThuc& other) : n(other.n) {
    heSo = new double[n + 1];
    for (int i = 0; i <= n; i++) {
        heSo[i] = other.heSo[i];
    }
}

// Dọn dẹp bộ nhớ
cDaThuc::~cDaThuc() {
    if (heSo != nullptr) {
        delete[] heSo;
    }
}

void cDaThuc::nhap() {
    cout << "Nhap bac cua da thuc: ";
    cin >> n;

    // Cấp phát lại mảng dựa trên bậc mới
    if (heSo != nullptr) delete[] heSo;
    heSo = new double[n + 1];

    cout << "Nhap cac he so (tu bac cao nhat xuong bac 0):" << endl;
    for (int i = n; i >= 0; i--) {
        cout << "He so cua x^" << i << ": ";
        cin >> heSo[i];
    }
    chuanHoa(); // Tránh nhập hệ số bậc cao nhất là 0
}

void cDaThuc::xuat() const {
    if (n == 0 && heSo[0] == 0) {
        cout << "0" << endl;
        return;
    }

    bool isFirst = true;
    for (int i = n; i >= 0; i--) {
        if (heSo[i] == 0) continue; // Bỏ qua phần tử 0

        // In dấu
        if (!isFirst) {
            if (heSo[i] > 0) cout << " + ";
            else cout << " - ";
        }
        else {
            if (heSo[i] < 0) cout << "-";
            isFirst = false;
        }

        double val = abs(heSo[i]);
        // Không in số 1 nếu có chữ x đi kèm (ví dụ: in x^2 thay vì 1x^2)
        if (val != 1 || i == 0) cout << val;

        if (i > 0) {
            cout << "x";
            if (i > 1) cout << "^" << i;
        }
    }
    cout << endl;
}

double cDaThuc::tinhGiaTri(double x) const {
    double kq = 0;
    for (int i = 0; i <= n; i++) {
        kq += heSo[i] * pow(x, i);
    }
    return kq;
}

cDaThuc cDaThuc::cong(const cDaThuc& other) const {
    int maxBac = max(n, other.n);
    cDaThuc kq(maxBac); // Tạo đa thức kết quả với bậc lớn nhất

    for (int i = 0; i <= maxBac; i++) {
        double a = (i <= n) ? heSo[i] : 0;          // Nếu vượt quá bậc của đa thức hiện tại thì coi như hệ số = 0
        double b = (i <= other.n) ? other.heSo[i] : 0; // Tương tự cho đa thức trước
        kq.heSo[i] = a + b;
    }
    kq.chuanHoa();
    return kq;
}

cDaThuc cDaThuc::tru(const cDaThuc& other) const {
    int maxBac = max(n, other.n);
    cDaThuc kq(maxBac);

    for (int i = 0; i <= maxBac; i++) {
        double a = (i <= n) ? heSo[i] : 0;
        double b = (i <= other.n) ? other.heSo[i] : 0;
        kq.heSo[i] = a - b;
    }
    kq.chuanHoa(); // bậc cao nhất có thể bị triệt tiêu
    return kq;
}