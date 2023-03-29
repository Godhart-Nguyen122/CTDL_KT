#include<bits/stdc++.h>
#include "function_form.h"
using namespace std;
struct khachhang{
   string IdKh;
   string IdHD;
   string tenHD;
   string Ngayvay;
   string Ngaydaihan;
   unsigned int tiencon;
};
typedef struct khachhang khachhang;

struct dskh{
    khachhang kh;
    struct dskh *left;
    struct dskh *right;
};
typedef struct dskh dskh;
void NhapHD(string &makh,string &mahd,string &tenHD,string &ngayvay,string &ngaydaihan,unsigned int &tiencon){
    cin.ignore();
    cout<<"Nhap MaKH :"<<endl;
    getline(cin,makh);
    cout<<"Nhap MaHD :"<<endl;
    getline(cin,mahd);
    cout<<"Nhap TenHD :"<<endl;
    getline(cin,tenHD);
    cout<<"Nhap Ngay vay :"<<endl;
    getline(cin,ngayvay);
    cout<<"Nhap Ngay Dai han :"<<endl;
    getline(cin,ngaydaihan);
    cout<<"Nhap Tiencon :"<<endl;
    cin>>tiencon;
}
void show(){
    cout<<setw(10)<<"Ma kh "<<setw(20);
    cout<<"Ma Hop dong"<<setw(20)<<"Ngay Vay"<<setw(20)<<"Ngay dao han "<<setw(15)<<"Con du"<<endl; 
}

int main(){
    show();
    return 0;
}