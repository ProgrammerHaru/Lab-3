#include <iostream>
#include "cListCandidate.h"

using namespace std;

int main() {
    cListCandidate quanLy;

    cout << "Chuong trinh quan ly thi sinh" << endl;
    quanLy.nhap();
    // Xuất thông tin các thí sinh có tổng điểm lớn hơn 15
    quanLy.xuatThiSinhTren15();

    // Tìm thí sinh có tổng điểm cao 
    quanLy.timThiSinhDiemCaoNhat();

    // Sắp xếp danh sách thí sinh giảm dần theo tổng điểm
    cout << "\nDanh sach sau khi sap xep giam dan theo tong diem" << endl;
    quanLy.sapXepGiamDan();
    quanLy.xuatTatCa();

    return 0;
}