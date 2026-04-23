#pragma once
#include "cCandidate.h"

class cListCandidate {
private:
    int n;              // Số lượng thí sinh
    cCandidate* ds;     // Mảng động chứa danh sách thí sinh

public:
    cListCandidate();
    ~cListCandidate();

    void nhap();
    void xuatTatCa() const;

    void xuatThiSinhTren15() const;
    void timThiSinhDiemCaoNhat() const;
    void sapXepGiamDan();
};