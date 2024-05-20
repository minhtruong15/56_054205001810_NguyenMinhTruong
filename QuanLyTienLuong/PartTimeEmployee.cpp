#include "PartTimeEmployee.h"
#include <iostream>

PartTimeEmployee::PartTimeEmployee(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, int luongCoBan, int soGioLamMoiTuan, double luongMoiGio)
    : Employee(ma, hoTen, ngayVaoLam, soDienThoai, luongCoBan), soGioLamMoiTuan(soGioLamMoiTuan), luongMoiGio(luongMoiGio) {}

int PartTimeEmployee::tinhLuong() const {
    int luongCanBan = luongCoBan * 0.3;
    int lamThemGio = 0;
    int gioLamTrungBinh = min(soGioLamMoiTuan, 40);
    int gioLamTangCa = max(soGioLamMoiTuan - 40, 0);
    int luongSanPham = gioLamTrungBinh * luongMoiGio + gioLamTangCa * luongMoiGio * 1.5;
    return luongCanBan + luongSanPham;
}

void PartTimeEmployee::inThongTin() const {
    Employee::inThongTin();
    cout << ", So gio lam viec moi tuan: " << soGioLamMoiTuan << ", Luong moi gio: " << luongMoiGio << endl;
}

void PartTimeEmployee::setSoGioLam(int gioLamMoiTuan) {
    this->soGioLamMoiTuan = gioLamMoiTuan;
}
