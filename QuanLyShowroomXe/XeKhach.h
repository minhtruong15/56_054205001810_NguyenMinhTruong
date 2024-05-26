#pragma once
#include "Oto.h"

using namespace std;

class XeKhach :public Oto
{
private:
	string loaiXe;
	int soCho;
public:
	XeKhach(const string& ma, const int& namSanXuat, double dungTichDongCo, int triGia, const string& loaiXe, const int& soCho);
	string getLoaiXe() const;
	void setLoaiXe(const string& loaiXe);
	int getSoCho() const;
	void setSoCho(const int& soCho);
	double tinhThue() const override;
	string toString() const override;
	void hienThiThongTin() const;
};

