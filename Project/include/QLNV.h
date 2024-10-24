#include <string>
#include <iostream>
#include "NhanVien.h"


using namespace std;

void QLNhanVienmenu() {
    NhanVien nv;
    int choice;
    nv.DocDSNhanVien();
    do {
        cout << "1. Them nhan vien" << endl;
        cout << "2. Xoa nhan vien" << endl;
        cout << "3. Sua nhan vien" << endl;
        cout << "4. Tim kiem nhan vien" << endl;
        cout << "5. Hien thi danh sach nhan vien" << endl;
        cout << "6. Luu danh sach nhan vien" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1:
            nv.ThemNhanVien();
            break;
        case 2:
            nv.XoaNhanVien();
            break;
        case 3:
            nv.SuaNhanVien();
            break;
        case 4:
            nv.TimKiemNhanVien();
            break;
        case 5:
            nv.HienThiDanhSachNhanVien();
            break;
        case 6:
            nv.LuuDSNhanVien();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    } while (choice != 0);
}