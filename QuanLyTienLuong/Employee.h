#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee
{
protected:
	string ma;
	string hoTen;
	string ngayVaoLam;
	string soDienThoai;
	int luongCoBan;

public:
	Employee(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, int luongCoBan);
	virtual ~Employee();
	string getMa() const;
	void setMa(const string& ma);
	string getHoTen() const;
	void setHoTen(const string& hoTen);
	string getNgayVaoLam() const;
	void setNgayVaoLam(const string& ngayVaoLam);
	string getSoDienThoai() const;
	void setSoDienThoai(const string& soDienThoai);
	int getLuongCoBan() const;
	void setLuongCoBan(int luongCoBan);
	virtual int tinhLuong() const = 0;
	virtual void inThongTin() const;
	bool isDate(const string& date) const;
	string currentDate() const;
	bool isPhone(const string& soDienThoai) const;
};