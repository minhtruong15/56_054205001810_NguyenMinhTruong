#include "Employee.h"

class FullTimeEmployee : public Employee
{
private:
    double heSoLuong;
    int namKinhNghiem;

public:
    FullTimeEmployee(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, int luongCoBan, double heSoLuong, int namKinhNghiem);
    int tinhLuong() const override;
    void inThongTin() const override;
};