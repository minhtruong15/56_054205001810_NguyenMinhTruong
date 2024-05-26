#include "QuanLyShowroom.h"
#include "XeKhach.h"
#include "XeTai.h"
#include "Oto.h"
#include <iostream>
#include <iomanip>

using namespace std;

void nhapCung(QuanLyShowroom& showroom) {
	showroom.nhapCung();
}


void menu(QuanLyShowroom& showroom) {
	int chon;
	do {
		cout << "============================ MENU ============================ " << endl;
		cout << "1.Them xe vao danh sach." << endl;
		cout << "2.Hien thi danh sach xe co san." << endl;
		cout << "3.Hien thi toan bo danh sach xe." << endl;
		cout << "4.Dem so luong xe co tri gia > tri gia can tim" << endl;
		cout << "5.Lay danh sach cac xe khach duoc san xuat vao nam." << endl;
		cout << "6.Cap nhat tri gia xe voi ma so." << endl;
		cout << "7.Sap xep danh sach xe giam dan theo nam san xuat." << endl;
		cout << "0.Thoat chuong trinh." << endl;
		cout << "==============================================================" << endl;
		cout << "Moi ban nhap lua chon cua ban: ";
		cin >> chon;

		switch (chon) {
		case 0: {
			cout << "Da thoat chuong trinh." << endl;
			break;
		}
		case 1: {
			string ma, loaiXe;
			int namSanXuat, soCho;
			double dungTichDongCo, taiTrong, triGia;
			int loai;
			cout << "Nhap loai xe ban muon them (1 - Xe Khach, 2 - Xe Tai):";
			cin >> loai;
			cout << "Moi ban nhap ma xe(Xe Khach -> K**, Xe Tai T**):";
			cin >> ma;
			cout << "Moi ban nhap nam san xuat( nam<=2024 ):";
			cin >> namSanXuat;
			cout << "Moi ban nhap dung tich dong co (>=0): ";
			cin >> dungTichDongCo;
			cout << "Nhap tri gia(>=0):";
			cin >> triGia;
			try {
				if (loai == 1) {
					cout << "Moi nhap loai xe (Xe Bus, Xe Du Lich,Xe Ban Tai, Xe Khac):";
					cin.ignore();
					getline(cin, loaiXe);
					cout << "Nhap so cho (>=2,<=50):";
					cin >> soCho;
					showroom.themXe(new XeKhach(ma, namSanXuat, dungTichDongCo, triGia, loaiXe, soCho));
					cout << " Ban da them xe thanh cong." << endl;
				}
				else if (loai == 2) {
					cout << " Nhap tai trong(>0):";
					cin >> taiTrong;
					showroom.themXe(new XeTai(ma, namSanXuat, dungTichDongCo, triGia, taiTrong));
				}
				else {
					cout << "Loai xe khong hop le." << endl;
				}
			}
			catch (const exception& danhsach) {
				cout << danhsach.what() << endl;
			}
			break;
		}
		case 2:
			cout << "Danh sach xe mau:" << endl;
			nhapCung(showroom);
			showroom.hienThiTatCaXe();
			break;
		case 3:
			showroom.hienThiTatCaXe();
			break;
		case 4: {
			double triGia;
			cout << "Nhap gia tri can dem: ";
			cin >> triGia;
			int soLuongXe = showroom.demXeThueTruocBaLonHon(triGia);
			cout << "So luong xe co thue truoc ba lon hon " << triGia << ":" << endl;
			break;
		}
		case 5: {
			int nam;
			cout << "Nhap nam can tim :";
			cin >> nam;
			showroom.layDanhSachXeKhachTheoNam(nam);
			break;
		}
		case 6: {
			string ma;
			double triGiaMoi;
			cout << "Nhap ma xe can cap nhat tri gia: ";
			cin >> ma;
			cout << "Nhap tri gia moi: ";
			cin >> triGiaMoi;
			showroom.capNhatTriGiaXe(ma, triGiaMoi);
			break;
		}
		case 7:
			showroom.sapXepGiamDanTheoNamSanXuat();
			break;
		default:
			cout << "Lua chon khong hop le !!! Vui long nhap lai.";
			break;
		}
	} while (chon != 0);
}
int main() {
	QuanLyShowroom showroom;
	menu(showroom);
	return 0;
}
