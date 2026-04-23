#include <iostream>
#include "cDaThuc.h"

using namespace std;

int main() {
    cDaThuc P, Q;

    cout << "Nhap da thuc P(x)" << endl;
    P.nhap();

    cout << "\nNhap da thuc Q(x)" << endl;
    Q.nhap();

    cout << "\n==============================\n";
    cout << "P(x) = "; P.xuat();
    cout << "Q(x) = "; Q.xuat();

    double x;
    cout << "\nNhap gia tri x de tinh P(x): ";
    cin >> x;
    cout << "=> P(" << x << ") = " << P.tinhGiaTri(x) << endl;

    cout << "\nPhep tinh da thuc" << endl;

    cDaThuc Tong = P.cong(Q);
    cout << "P(x) + Q(x) = ";
    Tong.xuat();

    cDaThuc Hieu = P.tru(Q);
    cout << "P(x) - Q(x) = ";
    Hieu.xuat();

    return 0;
}