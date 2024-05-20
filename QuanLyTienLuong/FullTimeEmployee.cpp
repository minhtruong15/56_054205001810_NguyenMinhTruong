#include "FullTimeEmployee.h"
#include <iostream>
using namespace std;


FullTimeEmployee::FullTimeEmployee(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, int luongCoBan, double heSoLuong, int namKinhNghiem)
    : Employee(ma, hoTen, ngayVaoLam, soDienThoai, luongCoBan), heSoLuong(heSoLuong), namKinhNghiem(namKinhNghiem) {}

int FullTimeEmployee::tinhLuong() const {
    int luongTheoHeSo = luongCoBan * heSoLuong;
    double luongTheoKinhNghiem = (namKinhNghiem * 0.05) * luongTheoHeSo;
    return luongTheoHeSo + luongTheoKinhNghiem;
}

void FullTimeEmployee::inThongTin() const {
    Employee::inThongTin();
    cout << ", He so luong: " << heSoLuong << ", So nam kinh nghiem: " << namKinhNghiem << endl;
}