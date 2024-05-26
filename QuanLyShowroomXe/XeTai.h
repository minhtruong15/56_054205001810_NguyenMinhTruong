#pragma once
#include  "Oto.h"

using namespace std;

class XeTai :public Oto
{
private:

	int taiTrong;

public:

	XeTai(const string& ma, const int& namSanXuat, double dungTichDongCo, int triGia, int taiTrong);
	int getTaiTrong() const;
	void setTaiTrong(int taiTrong);
	double tinhThue() const override;
	string toString() const override;
	void hienThiThongTin() const;

};

