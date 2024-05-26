#include "XeTai.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

XeTai::XeTai(const string& ma, const int& namSanXuat, double dungTichDongCo, int triGia, int taiTrong)
	:Oto(ma, namSanXuat, dungTichDongCo, triGia), taiTrong(taiTrong) {
	if (taiTrong < 0) {
		this->taiTrong = 0;
	}
}

int XeTai::getTaiTrong() const {
	return taiTrong;
}

void XeTai::setTaiTrong(int taiTrong) {
	if (taiTrong < 0) {
		throw invalid_argument("Tai trong khong phu hop");
	}
	this->taiTrong = taiTrong;
}

double XeTai::tinhThue()const {
	double vat = 0.1 * triGia;
	double thueTruocBa = 0.0;
	if (taiTrong < 950) {
		thueTruocBa = 0.02 * triGia;
	}
	else {
		thueTruocBa = 0.05 * triGia;
	}
	return vat + thueTruocBa;
}

string XeTai::toString() const {
	return"Ma: " + ma + "- Nam San Xuat: " + to_string(namSanXuat) + "- Dung Tich Dong Co: " + to_string(dungTichDongCo) + "- Tri Gia: " + to_string(triGia) + "- Tai Trong: " + to_string(taiTrong);
}

void XeTai::hienThiThongTin() const {
	cout << setw(20) << ma << setw(15) << namSanXuat << setw(20) << dungTichDongCo << setw(20) << triGia << endl;
	cout << "Tai Trong: " << taiTrong << endl;
}