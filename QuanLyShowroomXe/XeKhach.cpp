#include "XeKhach.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

XeKhach::XeKhach(const string& ma, const int& namSanXuat, double dungTichDongCo, int triGia, const string& loaiXe, const int& soCho) :Oto(ma, namSanXuat, dungTichDongCo, triGia), loaiXe(loaiXe), soCho(soCho) {
	if (soCho < 2 || soCho>50) {
		this->soCho = 2;
	}
}
string XeKhach::getLoaiXe()const {
	return loaiXe;
}
void XeKhach::setLoaiXe(const string& loaiXe) {
	this->loaiXe = loaiXe;
}
int XeKhach::getSoCho() const {
	return soCho;
}
void XeKhach::setSoCho(const int& soCho) {
	if (soCho >= 2 && soCho <= 50) {
		this->soCho = soCho;
	}
	else {
		throw invalid_argument("So cho khong hop le");
	}
}
double XeKhach::tinhThue() const {
	double vat = 0.1 * triGia;
	double thueTieuThuDacBiet = 0.0;
	if (soCho >= 5) {
		thueTieuThuDacBiet = 0.3 * triGia;
	}
	else {
		thueTieuThuDacBiet = 0.5 * triGia;
	}
	double thueTruocBa = 0.0;
	if (soCho <= 9) {
		thueTruocBa = 0.1 * triGia;
	}
	else if (loaiXe == "Xe Ban Tai") {
		thueTruocBa = 0.06 * triGia;
	}
	else {
		thueTruocBa = 0.02 * triGia;
	}
	return vat + thueTieuThuDacBiet + thueTruocBa;
}
string XeKhach::toString() const {
	return "Ma: " + ma + "- Nam San Xuat: " + to_string(namSanXuat) + "- Dung Tich Dong Co: " + to_string(dungTichDongCo) + "- Tri Gia: " + to_string(triGia) + "- Loai Xe " + loaiXe + "- So Cho: " + to_string(soCho);
}
void XeKhach::hienThiThongTin() const {
	cout << setw(20) << ma << setw(15) << namSanXuat << setw(20) << dungTichDongCo << setw(20) << triGia << endl;
	cout << "Loai Xe: " << loaiXe << endl;
	cout << "So Cho: " << soCho << endl;
}