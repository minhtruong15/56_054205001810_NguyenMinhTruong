#include <iostream>
#include <vector>
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
using namespace std;

void nhapCung(vector<Employee*>& employees) {
    employees.push_back(new FullTimeEmployee("FT001", "Nguyen Van Chung", "2024-10-09", "0123456789", 1800000, 3.0, 5));
    employees.push_back(new FullTimeEmployee("FT002", "Tran Minh Diep", "2024-05-15", "098765432", 15000000, 2.0, 4));
    employees.push_back(new FullTimeEmployee("FT004", "Nguyen Minh Hieu", "2022-11-15", "0987654321", 2000000, 2.5, 3));
    employees.push_back(new PartTimeEmployee("PT001", "Le Van Cau", "2018-12-09", "0912345678", 1500000, 35, 100000));
    employees.push_back(new PartTimeEmployee("PT002", "Ngo Tran Minh The", "2021-10-09", "0909876543", 1600000, 45, 95000));
    employees.push_back(new FullTimeEmployee("FT003", "Hoang Van Minh", "1990-12-11", "0923456789", 1700000, 2.0, 1));
}

void Menu() {
    cout << "===================MENU=================\n";
    cout << "1. Them nhan vien\n";
    cout << "2. Hien thi danh sach nhan vien da co\n";
    cout << "3. Thoat \n";
    cout << "========================================\n";
    cout << " Noi ban nhap lua chon : ";
}

void themEmployee(vector<Employee*>& employees) {
    string ma, hoTen, ngayVaoLam, soDienThoai;
    double luongCanBan;
    int kieu;
    cout << " Nhap ma nhan vien: "; cin >> ma;
    cout << "Nhap ho va ten nhan vien: "; cin.ignore(); getline(cin, hoTen);
    cout << "Nhap ngay vao lam (DD-MM-YYYY):"; cin >> ngayVaoLam;
    cout << "Nhap so dien thoai: "; cin >> soDienThoai;
    cout << "Nhap luong can ban: "; cin >> luongCanBan;
    do {
        cout << "Nhap loai nhan vien: (1- Toan Thoi Gian , 2 - Ban Thoi Gian): "; cin >> kieu;
    } while (kieu != 1 && kieu != 2);

    if (kieu == 1) {
        double heSoLuong;
        int namKinhNghiem;
        cout << "Nhap he so luong: "; cin >> heSoLuong;
        cout << "Nhap so nam kinh nghiem: "; cin >> namKinhNghiem;
        employees.push_back(new FullTimeEmployee(ma, hoTen, ngayVaoLam, soDienThoai, luongCanBan, heSoLuong, namKinhNghiem));
    }
    else {
        int soGioLamViecMoiTuan;
        double luongMoiGio;
        cout << "Nhap so gio lam viec moi tuan: "; cin >> soGioLamViecMoiTuan;
        cout << "Nhap luong moi gio: "; cin >> luongMoiGio;
        employees.push_back(new PartTimeEmployee(ma, hoTen, ngayVaoLam, soDienThoai, luongCanBan, soGioLamViecMoiTuan, luongMoiGio));
    }
}


void danhsachEmployee(const vector<Employee*>& employees) {
    cout << " Danh sach nhan vien: \n";
    cout << "=========================================================\n";
    for (const Employee* Employee : employees) {
        Employee->inThongTin();
    }
    cout << "=========================================================\n";
}
bool compareNgayVaoLam(const Employee* e1, const Employee* e2) {
    string d1 = e1->getNgayVaoLam().substr(6, 4) + e1->getNgayVaoLam().substr(3, 2) + e1->getNgayVaoLam().substr(0, 2);
    string d2 = e2->getNgayVaoLam().substr(6, 4) + e2->getNgayVaoLam().substr(3, 2) + e2->getNgayVaoLam().substr(0, 2);
    return d1 > d2;
void xoaNhanVien(vector<Employee*>&employee)
{
    string ma;
    int chon;
    cout << "Nhap ma nhan vien can xoa: ";
    cin.ignore();
    getline(cin, ma);
    int (vitri = timvitritheoma(employee, ma);
    if (viTri != -1)
    {
        cout << "Ban chac chan muon xoa khong!!" << endl;
        cout << "Xoa thi nhap phim 1!!" << endl;
        cout << "chon: ";
        if (chon == 1)
        {
            employee.erase(employee.begin() + vitri);
            cout << "Da xoa thanh cong!!" << endl;
        }
        else
        {
            cout << "Khong muon xoa!!" << endl;
        }


    }
    else
    {
        cout << "Khong tim thay ma nhan vien can xoa !!" << endl;
    }
}

int main() {
    vector<Employee*> employees;
    nhapCung(employees);

    int chon;
    do {
        Menu();
        cin >> chon;
        switch (chon) {
        case 1:
            themEmployee(employees);
            break;
        case 2:
            danhsachEmployee(employees);
            break;
        case 3:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Nhap khong hop le!!! Vui long nhap lai.\n";
            break;
        }
    } while (chon != 3);
    for (Employee* Employee : employees) {
        delete Employee;
    }
    return 0;
}