#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class NhanVien{
private:
    string maNhanVien , hoTen , caLamViec , soDienThoai , email;
    vector<NhanVien> danhSachNhanVien;

public:
    NhanVien();
    NhanVien(string maNhanVien, string hoTen, string caLamViec, string soDienThoai, string email);
    void ThemNhanVien();
    void XoaNhanVien();
    void SuaNhanVien();
    void TimKiemNhanVien();
    void HienThiDanhSachNhanVien();
    void LuuDSNhanVien();
    void DocDSNhanVien();
    void HienThi(const int& i);
};

#endif // NHANVIEN_H