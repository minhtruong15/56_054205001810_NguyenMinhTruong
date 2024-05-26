#pragma once
#include <iostream>
#include <string>

using namespace std;

class Oto {
protected:

	string ma;
	int namSanXuat;
	double dungTichDongCo;
	int triGia;

public:
	Oto(const string& ma, const int& namSanXuat, double dungTichDongCo, int triGia);
	string getMa() const;
	void setMa(const string& ma);
	int getNamSanXuat() const;
	void setNamSanXuat(const int& namSanXuat);
	double getDungTichDongCo() const;
	void setDungTichDongCo(double dungTichDongCo);
	int getTriGia() const;
	void setTriGia(int triGia);
	virtual double tinhThue() const = 0;
	virtual string toString() const = 0;
	virtual void hienThiThongTin() const;
	virtual ~Oto() = default;
};

