#include "Employee.h"

class PartTimeEmployee : public Employee {
private:
    int soGioLamMoiTuan;
    int luongMoiGio;

public:
    PartTimeEmployee(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, int luongCoBan, int soGioLamMoiTuan, double luongMoiGio);
    int tinhLuong() const override;
    void inThongTin() const override;
    void setSoGioLam(int gioLamMoiTuan); 
};
