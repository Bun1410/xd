#include "NhaCungCap.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

NhaCungCap::NhaCungCap(){};
NhaCungCap::NhaCungCap(string tenNCC, string tenSpNhap, int soLuong, double giaSanPham, string soDienThoai)
    : tenNCC(tenNCC), tenSpNhap(tenSpNhap), soLuong(soLuong), giaSanPham(giaSanPham), soDienThoai(soDienThoai){};

void NhaCungCap::themNCC(){
    cout << "Nhap ten nha cung cap: ";
    cin.ignore();
    getline(cin, tenNCC);
    cout << "Nhap ten san pham nhap: ";
    getline(cin, tenSpNhap);
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cout << "Nhap gia san pham: ";
    cin >> giaSanPham;
    cout << "Nhap so dien thoai: ";
    cin >> soDienThoai;
    cout << "Them nha cung cap thanh cong" << endl;
    NhaCungCap* ncc = new NhaCungCap(tenNCC, tenSpNhap, soLuong, giaSanPham, soDienThoai);
    listNCC.push_back(*ncc);
}

void NhaCungCap::xoaNCC(){
    string tenNCC;
    cout << "Nhap ten nha cung cap can xoa: ";
    cin >> tenNCC;
    for(int i = 0; i < listNCC.size(); i++){
        if(listNCC[i].tenNCC == tenNCC){
            listNCC.erase(listNCC.begin() + i);
            cout << "Xoa thanh cong" << endl;
            return;
        }
    }
    cout << "Khong tim thay nha cung cap" << endl;
}

void NhaCungCap::suaNCC(){
    string tenNCC;
    cout << "Nhap ten nha cung cap can sua: ";
    cin >> tenNCC;
    for(int i = 0; i < listNCC.size(); i++){
        if(listNCC[i].tenNCC == tenNCC){
            cout << "Nhap ten nha cung cap: ";
            getline(cin, listNCC[i].tenNCC);
            cout << "Nhap ten san pham nhap: ";
            getline(cin, listNCC[i].tenSpNhap);
            cout << "Nhap so luong: ";
            cin >> listNCC[i].soLuong;
            cout << "Nhap gia san pham: ";
            cin >> listNCC[i].giaSanPham;
            cout << "Nhap so dien thoai: ";
            cin.ignore();
            getline(cin, listNCC[i].soDienThoai);
            cout << "Sua thanh cong" << endl;
            return;
        }
    }
    cout << "Khong tim thay nha cung cap" << endl;
}

void NhaCungCap::timKiemNCC(){
    string tenNCC;
    cout << "Nhap ten nha cung cap can tim: ";
    cin >> tenNCC;
    for(int i = 0 ; i < listNCC.size(); i++){
        if(listNCC[i].tenNCC == tenNCC){
            cout << "|  STT  |      Ten nha cung cap      |        Ten San Pham nhap      |   So luong  |   Gia San Pham   |               So Dien Thoai              |" << endl;
            hienThi(i);
    }
    cout << "Khong tim thay nha cung cap" << endl;
}

void NhaCungCap::hienThi(const int &i){
    cout << "| " << i+1;
    int dem = 0;
    while(1){
        if(dem < 6 - to_string(i+1).length()){
            cout << " ";
            dem++;
        }
        else break;
    }
    cout << "| " << listNCC[i].tenNCC;
    for(int j = 0; j < 30 - listNCC[i].tenNCC.length(); j++){
        cout << " ";
    }
    cout << "| " << listNCC[i].tenSpNhap;
    for(int j = 0; j < 30 - listNCC[i].tenSpNhap.length(); j++){
        cout << " ";
    }
    for(int j = 0; j < 12 - to_string(listNCC[i].soLuong).length(); j++){
        cout << " ";
    }
    cout << listNCC[i].soLuong;
    for(int j = 0; j < 15 - to_string(listNCC[i].giaSanPham).length(); j++){
        cout << " ";
    }
    cout << listNCC[i].giaSanPham;
    cout << "       | " << listNCC[i].soDienThoai;
    for(int j = 0; j < 45 - listNCC[i].soDienThoai.length(); j++){
        cout << " ";
    }
    cout << "|" << endl;
}

void NhaCungCap::hienThiListNCC(){
    cout << "|  STT  |      Ten nha cung cap      |        Ten San Pham nhap      |   So luong  |   Gia San Pham   |               So Dien Thoai              |" << endl;
    for(int i = 0; i < listNCC.size(); i++){
        hienThi(i);
    }
}

void NhaCungCap::luuNCC(){
    ofstream file("data/nhacungcap.txt");
    for(int i = 0; i < listNCC.size(); i++){
        file << listNCC[i].tenNCC << ";";
        file << listNCC[i].tenSpNhap << ";";
        file << listNCC[i].soLuong << ";";
        file << listNCC[i].giaSanPham << ";";
        file << listNCC[i].soDienThoai << endl;";
    }
    cout << "Luu thanh cong" << endl;
    file.close();
}

void NhaCungCap::docNCC(){
    ifstream file("data/nhacungcap.txt");
    if(!file.is_open()){
        cout << "Khong the mo file" << endl;
        return;
    }
    listNCC.clear();
    while(!file.eof()){
        getline(file, tenNCC, '; ');
        getline(file, tenSpNhap, '; ');
        getline >> soLuong,'; ';
        getline >> giaSanPham, '; ';
        getline(file, soDienThoai);
        if(tenNCC != ""){
            NhaCungCap ncc(tenNCC, tenSpNhap, soLuong, giaSanPham, soDienThoai);
            listNCC.push_back(ncc);
        }
    }
    cout << "Doc thanh cong" << endl;
    file.close();
}