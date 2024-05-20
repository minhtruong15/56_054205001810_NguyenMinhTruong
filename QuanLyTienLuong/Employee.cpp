#include "Employee.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip> 
using namespace std;

Employee::Employee(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, int luongCoBan) : ma(ma), hoTen(hoTen), luongCoBan(luongCoBan)
{
    if (!isDate(ngayVaoLam) || ngayVaoLam > currentDate()) {
        this->ngayVaoLam = currentDate();
    }
    if (!isPhone(soDienThoai)) {
        this->soDienThoai = "0000000000";
    }
    else {
        this->soDienThoai = soDienThoai;
    }
}

Employee::~Employee() {}

string Employee::getMa() const {
    return ma;
}

void Employee::setMa(const string& ma) {
    this->ma = ma;
}

string Employee::getHoTen() const {
    return hoTen;
}

void Employee::setHoTen(const string& hoTen) {
    this->hoTen = hoTen;
}

string Employee::getNgayVaoLam() const {
    return ngayVaoLam;
}

void Employee::setNgayVaoLam(const string& ngayVaoLam) {
    if (isDate(ngayVaoLam) && ngayVaoLam <= currentDate()) {
        this->ngayVaoLam = ngayVaoLam;
    }
    else {
        cout << "Ngay nhap vao khong hop le hoac lon hon ngay hien tai!" << endl;
    }
}

string Employee::getSoDienThoai() const {
    return soDienThoai;
}

void Employee::setSoDienThoai(const string& soDienThoai) {
    if (isPhone(soDienThoai)) {
        this->soDienThoai = soDienThoai;
    }
}

int Employee::getLuongCoBan() const {
    return luongCoBan;
}

void Employee::setLuongCoBan(int luongCoBan) {
    if (luongCoBan >= 0) {
        this->luongCoBan = luongCoBan;
    }
}

void Employee::inThongTin() const {
    cout << "Ma So: " << ma << ", Ho Ten: " << hoTen << ", Ngay Vao lam: " << ngayVaoLam << ", So Dien Thoai: " << soDienThoai << ", Luong Co Ban: " << luongCoBan;
}

bool Employee::isDate(const string& date) const {

    return true;
}

string Employee::currentDate() const {
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);
    char buf[11];
    strftime(buf, sizeof(buf), "%d-%m-%Y", &now);
    return buf;
}


bool Employee::isPhone(const string& soDienThoai) const {
    return soDienThoai.length() == 10 && soDienThoai[0] == '0' && all_of(soDienThoai.begin(), soDienThoai.end(), ::isdigit);
}