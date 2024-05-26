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
    cout << "1. Them Employee\n";
    cout << "2. Hien thi danh sach Employee da co\n";
    cout << "3. Xoa Employee\n";
    cout << "4. Cap nhat gio lam cho nhan vien\n";
    cout << "5. Thoat \n";
    cout << "========================================\n";
    cout << " Noi ban nhap lua chon : ";
}

void themEmployee(vector<Employee*>& employees) {
    string ma, hoTen, ngayVaoLam, soDienThoai;
    double luongCoBan;

    cout << "Nhap ma Employee: "; cin >> ma;
    cout << "Nhap ho va ten Employee: "; cin.ignore(); getline(cin, hoTen);
    cout << "Nhap ngay vao lam (DD-MM-YYYY): "; cin >> ngayVaoLam;
    cout << "Nhap so dien thoai: "; cin >> soDienThoai;
    cout << "Nhap luong co ban: "; cin >> luongCoBan;

    int kieu;
    cout << "Nhap loai Employee (1- Toan Thoi Gian, 2 - Ban Thoi Gian): "; cin >> kieu;

    if (kieu == 1) {
        double heSoLuong;
        int namKinhNghiem;
        cout << "Nhap he so luong: "; cin >> heSoLuong;
        cout << "Nhap so nam kinh nghiem: "; cin >> namKinhNghiem;
        employees.push_back(new FullTimeEmployee(ma, hoTen, ngayVaoLam, soDienThoai, luongCoBan, heSoLuong, namKinhNghiem));
    }
    else {
        int soGioLamMoiTuan;
        int luongMoiGio;
        cout << "Nhap so gio lam viec moi tuan: "; cin >> soGioLamMoiTuan;
        cout << "Nhap luong moi gio: "; cin >> luongMoiGio;
        employees.push_back(new PartTimeEmployee(ma, hoTen, ngayVaoLam, soDienThoai, luongCoBan, soGioLamMoiTuan, luongMoiGio));
    }
    cout << "Da them Employee thanh cong.\n";
}


void xoaEmployee(vector<Employee*>& employees) {
    string ma;
    cout << "Nhap ma Employee muon xoa: ";
    cin >> ma;
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->getMa() == ma) {
            delete* it;
            employees.erase(it);
            cout << "Da xoa Employee co ma " << ma << endl;
            return;
        }
    }
    cout << "Khong tim thay Employee co ma " << ma << endl;
}

void capNhatGioLam(vector<Employee*>& employees) {
    string ma;
    int gioLamMoi;
    cout << "Nhap ma Employee muon cap nhat gio lam: ";
    cin >> ma;
    cout << "Nhap so gio lam moi: ";
    cin >> gioLamMoi;
    for (auto employee : employees) {
        if (employee->getMa() == ma) {
            PartTimeEmployee* partTimeEmployee = dynamic_cast<PartTimeEmployee*>(employee);
            if (partTimeEmployee != nullptr) {
                partTimeEmployee->setSoGioLam(gioLamMoi);
                cout << "Da cap nhat so gio lam cho Employee co ma " << ma << endl;
                return;
            }
            else {
                cout << "Employee co ma " << ma << " khong phai la nhan vien Ban Thoi Gian." << endl;
                return;
            }
        }
    }
    cout << "Khong tim thay Employee co ma " << ma << endl;
}

void danhsachEmployee(const vector<Employee*>& employees) {
    cout << "Danh sach nhan vien :\n";
    for (const auto& emp : employees) {
        emp->inThongTin();
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
            xoaEmployee(employees);
            break;
        case 4:
            capNhatGioLam(employees);
            break;
        case 5:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Nhap khong hop le!!! Vui long nhap lai.\n";
            break;
        }
    } while (chon != 5);

    for (auto Employee : employees) {
        delete Employee;
    }
    return 0;
}



    

