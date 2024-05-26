#pragma once
#include "Oto.h"
#include <vector>

using namespace std;

class QuanLyShowroom
{
private:
	vector<Oto*> danhSachXe;
	bool kiemTra(const string& ma) const;

public:

	QuanLyShowroom();
	~QuanLyShowroom();
	void themXe(Oto* xe);
	void xoaXe(const string& ma);
	void hienThiTatCaXe() const;
	void nhapCung();
	int demXeThueTruocBaLonHon(int triGia) const;
	void capNhatTriGiaXe(const string& ma, int triGiaMoi);
	vector<Oto*> layDanhSachXeKhachTheoNam(int nam) const;
	vector<Oto*> sapXepGiamDanTheoNamSanXuat() const;
};


