#ifndef NHACUNGCAP_H
#define NHACUNGCAP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhaCungCap {
    private:
        string tenNCC, tenSpNhap, soDienThoai;
        double giaSanPham;
        int soLuong;
        vector<NhaCungCap> listNCC;

    public:
        NhaCungCap();
        NhaCungCap(string tenNCC, string tenSpNhap, int soLuong, double giaSanPham, string soDienThoai);
        
        void themNCC();
        void xoaNCC();
        void suaNCC();
        void hienThiNCC();
        void timKiemNCC();
        void luuNCC();
        void docNCC();
        void hienThi(const int &i);

};

#endif // NHACUNGCAP_H