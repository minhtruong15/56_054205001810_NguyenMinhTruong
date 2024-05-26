#include "QuanLyShowroom.h"
#include "XeKhach.h"
#include "XeTai.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

QuanLyShowroom::QuanLyShowroom() {}

QuanLyShowroom::~QuanLyShowroom() {
    for (auto xe : danhSachXe) {
        delete xe;
    }
}
bool QuanLyShowroom::kiemTra(const string& ma) const {
    return std::any_of(danhSachXe.begin(), danhSachXe.end(), [ma](const Oto* x) {
        return x->getMa() == ma;
        });
}
void QuanLyShowroom::themXe(Oto* xe) {
    if (xe != nullptr) {
        if (!kiemTra(xe->getMa())) {
            danhSachXe.push_back(xe);
        }
        else {
            cout << "Xe da ton tai trong danh sach." << endl;
        }
    }
}



void QuanLyShowroom::xoaXe(const string& ma) {
    if (!kiemTra(ma)) {
        cout << "Khong tim thay xe co ma: " << ma << endl;
        return;
    }
    cout << "Thong tin xe can xoa: " << endl;
    for (const auto& xe : danhSachXe) {
        if (xe->getMa() == ma) {
            xe->hienThiThongTin();
            cout << "Ban chac chan muon xoa xe nay? (Y/N): ";
            char luachon;
            cin >> luachon;
            if (luachon == 'Y' || luachon == 'y') {
                auto it = std::remove_if(danhSachXe.begin(), danhSachXe.end(), [ma](const Oto* xe) {
                    return xe->getMa() == ma;
                    });
                danhSachXe.erase(it, danhSachXe.end());
                cout << "Xoa xe thanh cong." << endl;
            }
            else {
                cout << "Huy xoa xe." << endl;
            }
            return;
        }
    }
}

void QuanLyShowroom::hienThiTatCaXe() const {
    cout << "Danh sach xe oto khach: " << endl;
    cout << setw(18) << left << "Ma" << setw(15) << "Nam San Xuat" << setw(20) << "Dung Tich Dong Co" << setw(20) << "Tri Gia" << endl;

    for (const auto& xe : danhSachXe) {
        if (dynamic_cast<XeKhach*>(xe) != nullptr) {
            xe->hienThiThongTin();

        }
    }

    cout << "Danh sach xe oto tai: " << endl;
    cout << setw(18) << left << "Ma" << setw(15) << "Nam San Xuat" << setw(20) << "Dung Tich Dong Co" << setw(20) << "Tri Gia" << endl;

    for (const auto& xe : danhSachXe) {
        if (dynamic_cast<XeTai*>(xe) != nullptr) {
            xe->hienThiThongTin();

        }
    }
}
void QuanLyShowroom::nhapCung() {
    danhSachXe.push_back(new XeKhach("K01", 2023, 3.0, 400000000, "Xe Du Lich", 12));
    danhSachXe.push_back(new XeKhach("K02", 2024, 2.5, 800000000, "Xe Bus", 8));
    danhSachXe.push_back(new XeKhach("K03", 2023, 4.0, 200000000, "Xe Ban Tai", 4));
    danhSachXe.push_back(new XeTai("T01", 2024, 2.0, 500000000, 300));
    danhSachXe.push_back(new XeTai("T02", 2023, 2.0, 300000000, 100));
}

int QuanLyShowroom::demXeThueTruocBaLonHon(int triGia) const {
    int count = 0;
    for (const auto& xe : danhSachXe) {
        if (xe->tinhThue() > triGia) {
            count++;
        }
    }
    return count;
}

vector<Oto*> QuanLyShowroom::layDanhSachXeKhachTheoNam(int nam) const {
    vector<Oto*> danhSachXeKhach;
    for (const auto& xe : danhSachXe) {
        if (dynamic_cast<XeKhach*>(xe) != nullptr && xe->getNamSanXuat() == nam) {
            danhSachXeKhach.push_back(xe);
        }
    }
    return danhSachXeKhach;
}

void QuanLyShowroom::capNhatTriGiaXe(const string& ma, int triGiaMoi) {
    for (auto& xe : danhSachXe) {
        if (xe->getMa() == ma) {
            xe->setTriGia(triGiaMoi);
            cout << "Cap nhat tri gia xe thanh cong" << endl;
            return;
        }
    }
    cout << "Khong tim thay xe co ma: " << ma << endl;
}

vector<Oto*> QuanLyShowroom::sapXepGiamDanTheoNamSanXuat() const {
    vector<Oto*> sapXep = danhSachXe;
    sort(sapXep.begin(), sapXep.end(), [](const Oto* a, const Oto* b) {
        return a->getNamSanXuat() > b->getNamSanXuat();
        });
    return sapXep;
}
