#include<bits/stdc++.h>
#include "function_form.h"
using namespace std;


struct khachhang{
//    string IdKh;
//    string IdHD;
//    string tenHD;
//    string Ngayvay;
//    string Ngaydaihan;
   unsigned int tiencon;
   string id;
};
struct node {
    khachhang kh;
    struct node *left;
    struct node *right;
};
typedef struct khachhang khachhang;
typedef struct node tree;

khachhang createKh(string idkh,string idhd,string tenhd,string ngayvay,string ngaydaihan,int tiencon){
     khachhang kh;
}
tree createNode(khachhang kh){
      tree *root=new tree;
      root->kh=kh;
      root->left=nullptr;
      root->right=nullptr;
      return root;
} 
void insertNodeTree(tree *&root, int x){
     if(root==nullptr){
        root->kh.tiencon=x;
     }
     else{
        tree*p=root;
        while()
     }
}
void deleteNode(tree *&root,int x){
   if(root==nullptr){
      cout<<"Cay rong "<<endl;
   }
   else {
      tree*p=root;
      tree*parent=nullptr;
      while(p!=nullptr &&p->data!=x){
         parent=p;
         if(p->data>x){
            p=p->left;
         }
         else if(p->data<x){
            p=p->right;
         }
      }
      if(p==nullptr){
         cout<<"Khong tim thay node can xoa"<<endl;
      }
      else{
         if(p->left !=nullptr && p->right !=nullptr){
              tree *themang=p->right;
              while(themang->left !=nullptr){
                  parent=themang;
                  themang=themang->left;
              }
              p->data=themang->data;
              p=themang;
         }
         tree*t=nullptr;
         if(p->left==nullptr){
            t=p->right;
         }
         else if(p->right==nullptr){
            t=p->left;
         }
         if(parent->data>x ){
            parent->left=t;
         }
         else if(parent->data<x){
            parent->right=t;
         }
         delete p;
      }
   }
}
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
void menu(int &choose){
       cout<<"=============Menu================"<<endl;
       cout<<"1. "<<endl;
       cout<<"2. "<<endl;
       cout<<"3."<<endl;
       cout<<"4."<<endl;
       cout<<"0.Thoat"<<endl;
       cout<<"Nhap lua chon "<<endl;
       cin>>choose;
       while(choose<0||choose>4){
           cout<<"Nhap lua chon "<<endl;
           cin>>choose;
       } 
}
int main(){
    int choose;
    while(true){
        menu(choose);
        system("pause");
        system("cls");
    }
    return 0;
}