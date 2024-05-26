#include "Oto.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

Oto::Oto(const string& ma, const int& namSanXuat, double dungTichDongCo, int triGia) :ma(ma), namSanXuat(namSanXuat), dungTichDongCo(dungTichDongCo), triGia(triGia) {
	if (namSanXuat > 2024) {
		this->namSanXuat = namSanXuat;
	}
	if (dungTichDongCo < 0) {
		this->dungTichDongCo = dungTichDongCo;
	}
	if (triGia < 0) {
		this->triGia = triGia;
	}
	if (ma.empty()) {
		this->ma = "-";
	}
}

string Oto::getMa() const {
	return ma;
}

void Oto::setMa(const string& ma) {
	this->ma = ma;
}

int Oto::getNamSanXuat() const {
	return namSanXuat;
}

void Oto::setNamSanXuat(const int& namSanXuat) {
	if (namSanXuat > 2024) {
		throw invalid_argument("Nam san xuat khong hop le");
	}
	this->namSanXuat = namSanXuat;
}

double Oto::getDungTichDongCo() const {
	return dungTichDongCo;
}

void Oto::setDungTichDongCo(double dungTichDongCo) {
	if (dungTichDongCo < 0) {
		throw invalid_argument("Dung tich dong co khong hop le");
	}
	this->dungTichDongCo = dungTichDongCo;
}

int Oto::getTriGia() const {
	return triGia;
}

void  Oto::setTriGia(int triGia) {
	if (triGia < 0) {
		throw invalid_argument("Tri gia khong hop le");
	}
	this->triGia = triGia;
}

void Oto::hienThiThongTin()const {
	cout << setw(20) << left << "Ma" << setw(15) << "Nam San Xuat" << setw(20) << "Dung Tich Dong Co" << setw(20) << "Tri Gia" << endl;
	cout << setw(20) << left << ma << setw(15) << namSanXuat << setw(20) << dungTichDongCo << setw(20) << triGia << endl;
}