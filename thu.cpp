#include<bits/stdc++.h>
#include<string>
#include "function_form.h"
using namespace std;
// tao struct thong tin sinh vien 
struct SV{
    string name;
    int diem;
    string id;
};
typedef struct SV sv;
//tao struct node cay cua sinh vien 
struct node{
    sv sinhvien; 
    struct node*left;
    struct node*right;
};
typedef  struct node tree;
// tao struct thong tin sinh vien trong thu vien
struct Thuvien{
    string idthe;
    string id;
    string name;
    int sosachmuon;
    int sosachtra;
};
typedef struct Thuvien thuvien; 
// tao node cay cua sinh vien trong thu vien 
struct nodethuvien{
    thuvien svmoi;
    struct nodethuvien *left;
    struct nodethuvien *right;
};
typedef struct nodethuvien treethuvien;

tree *createnode(sv sinhvien);
sv createSinhVien(string name,int diem ,string id);
thuvien createThuvien(string idthe,string id,string name,int sosachmuon,sosachtra);
tree*createNodethuvien(thuvien sinhvienmoi);

void showNhapsv(string &name ,int &diem,string &id);
void insertSinhvien(tree*&root,sv sinhvien);
void showThongtin(sv sinhvien);
void duyetNLR(tree *root);
void deleteNode(tree *&root,sv sinhvien);
void menu(int &choose);
void search(tree *root,string id);
void updateDiem(tree *&root ,string id ,int diem);
void updateName(tree *&root ,string id ,string name);
void insertThuvienSV(tree *&root,thuvien thuvien);



// tao node cay luu thong tin sinh vien 
tree *createnode(sv sinhvien){
     tree *p=new tree;
     p->sinhvien=sinhvien;
     p->left=nullptr;
     p->right=nullptr;
    return p;
 }
 // tao thong tin cho sinh vien
sv createSinhVien(string name,int diem ,string id){
    sv moi;
    moi.diem=diem;
    moi.name=form_name(name);
    moi.id=id;
    return moi;
}
// tao thong tin sinh vien trong thu vien 
thuvien createThuvien(string idthe,string id,string name,int sosachmuon,int sosachtra){
    thuvien moi;
    moi.idthe=idthe;
    moi.id=id;
    moi.name=name;
    moi.sosachmuon=sosachmuon;
    moi.sosachtra=sosachtra;
}
// tao node cay luu thong tin sinh vien trong thu vien
tree*createNodethuvien(thuvien sinhvienmoi){
     treethuvien *p=new treethuvien;
     p->moi=sinhvienmoi;
     p->left=nullptr;
     p->right=nullptr;
     return p;
}
// ham show thong tin cua sinh vien 
void showNhapsv(string &name ,int &diem,string &id){
    cin.ignore();
     cout<<"Nhap ten"<<endl;
     getline(cin,name);
     cout<<"Nhap diem"<<endl;
     cin>>diem;
     cout<<"Nhap id"<<endl;
     cin.ignore();
     getline(cin,id);

}
// them sinh vine moi vao cay sinh vien theo id
void insertSinhvien(tree*&root,sv sinhvien){
    if(root==nullptr){
     root=createnode(sinhvien);
   }
   else {
      tree *p=root;
      tree *parent=nullptr;
      while(p!=nullptr && p->sinhvien.id !=sinhvien.id){
         parent=p;
         if(p->sinhvien.id>sinhvien.id){
            p=p->left;
         }
         else if(p->sinhvien.id<sinhvien.id){
            p=p->right;
         }
      }
       if(p==nullptr){
          if(parent->sinhvien.id>sinhvien.id){
            parent ->left=createnode(sinhvien);
          }
          else if(parent->sinhvien.id<sinhvien.id){
            parent->right=createnode(sinhvien);
          }
      }
      // vi sao dat dong lenh do len truoc thi chuong trinh bi loi vi sao ??
      else if(parent->left->sinhvien.id ==sinhvien.id || parent->right->sinhvien.id ==sinhvien.id  ){
           cout<<"Phan tu da ton tai tren cay"<<endl;
           return ;
      }
   }
}
// ham xoa sinh vien trong cay theo id
void deleteNode(tree *&root,string id){
   if(root==nullptr){
      cout<<"Cay rong "<<endl;
   }
   else {
      tree*p=root;
      tree*parent=nullptr;
       while(p!=nullptr && p->sinhvien.id !=id){
         parent=p;
         if(p->sinhvien.id>id){
            p=p->left;
         }
         else if(p->sinhvien.id<id){
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
              p->sinhvien.id=themang->sinhvien.id;
              p=themang;
         }
         tree*t=nullptr;
         if(p->left==nullptr){
            t=p->right;
         }
         else if(p->right==nullptr){
            t=p->left;
         }
         if(parent->sinhvien.id>id ){
            parent->left=t;
         }
         else if(parent->sinhvien.id<id){
            parent->right=t;
         }
         delete p;
      }
   }
}
//ham tim kiem sinh vien theo id va show thong tin sinh vien 
void search(tree *root,string id){
      tree *p=root;
    if(p==nullptr){
        cout<<"Cay rong"<<endl;
    }
    else{
         while(p!=nullptr && p->sinhvien.id !=id){
        
         if(p->sinhvien.id>id){
            p=p->left;
         }
         else if(p->sinhvien.id<id){
            p=p->right;
         }
      }
        if(p==nullptr){
            cout<<"Khong tim thay sinh vien "<<endl;
        }
        else{
            cout<<"Tim thay sinh vien"<<endl;
            showThongtin(p->sinhvien);
        }
    }
}
// form show thong tin sinh vien 
void showThongtin(sv sinhvien){
    cout<<"Name :" <<sinhvien.name<<endl;
    cout<<"Diem :" <<sinhvien.diem<<endl;
    cout<<"id:" <<sinhvien.id<<endl;
    cout<<"------------------------"<<endl;
}
// ham duyet show thong tin sinh vien
void duyetNLR(tree *root){
      if(root!=nullptr){
        showThongtin(root->sinhvien);
        duyetNLR(root->left);
        duyetNLR(root->right);
      }
}
// ham cap nhat diem sinh vien dua theo id 
void updateDiem(tree *&root ,string id ,int diem){
    tree *p=root;
    if(p==nullptr){
        cout<<"Cay rong"<<endl;
    }
    else{
         while(p!=nullptr && p->sinhvien.id !=id){
        
         if(p->sinhvien.id>id){
            p=p->left;
         }
         else if(p->sinhvien.id<id){
            p=p->right;
         }
      }
        if(p==nullptr){
            cout<<"Khong tim thay sinh vien can cap nhat "<<endl;
        }
        else{
           p->sinhvien.diem=diem;
           cout<<"Da cap nhat diem"<<endl;
        }
    }
}
// ham cap nhat ten sinh vien theo id 
void updateName(tree *&root ,string id ,string name){
    tree *p=root;
    if(p==nullptr){
        cout<<"Cay rong"<<endl;
    }
    else{
         while(p!=nullptr && p->sinhvien.id !=id){
        
         if(p->sinhvien.id>id){
            p=p->left;
         }
         else if(p->sinhvien.id<id){
            p=p->right;
         }
      }
        if(p==nullptr){
            cout<<"Khong tim thay sinh vien can cap nhat "<<endl;
        }
        else{
           p->sinhvien.name=name;
           cout<<"Da cap nhat diem"<<endl;
        }
    }
}
// them thong tin sinh vien trong thu vien theo id 
void insertThuvienSV(treethuvien *&root,thuvien thuvien){
     if(root==nullptr){
     root=createNodethuvien(thuvien);
   }
   else {
      treethuvien *p=root;
      treethuvien *parent=nullptr;
      while(p!=nullptr && p->svmoi.idthe!=thuvien.idthe){
         parent=p;
         if(p->svmoi.idthe>thuvien.id){
            p=p->left;
         }
         else if(p->svmoi.idthe<thuvien.id){
            p=p->right;
         }
      }
       if(p==nullptr){
          if(parent->svmoi.idthe>thuvien.idthe){
            parent ->left=createNodethuvien(thuvien);
          }
          else if(parent->svmoi.idthe<thuvien.idthe){
             parent ->right=createNodethuvien(thuvien);
          }
      }
      // vi sao dat dong lenh do len truoc thi chuong trinh bi loi vi sao ??
      else if(parent->left->svmoi.idthe ==thuvien.idthe || parent->right->svmoi.idthe ==thuvien.idthe  ){
           cout<<"Phan tu da ton tai tren cay"<<endl;
           return ;
      }
   }
}


void menu(int &choose){
       cout<<"=============Menu================"<<endl;
       cout<<"1.Them "<<endl;
       cout<<"2.Duyet "<<endl;
       cout<<"3.Xoa theo id"<<endl;
       cout<<"4.Tim kiem thong tin theo id"<<endl;
       cout<<"5.Cap nhat diem theo id"<<endl;       
       cout<<"0.thoat"<<endl;
       cout<<"nhap lua chon "<<endl;
       cin>>choose;
       while(choose<0||choose>6){
           cout<<"nhap lua chon "<<endl;
           cin>>choose;
       } 
}
int main(){
    int choose;
    string name;
    int diem;
    string id;
    tree*root=nullptr;
    sv sinhvien;
    while(true){
        menu(choose);
        switch(choose){
            case 1:
            showNhapsv(name,diem,id);
            sinhvien=createSinhVien(name,diem,id); 
            insertSinhvien(root,sinhvien);
            break;
            case 2:
            duyetNLR(root);
            system("pause");
            break;
            case 3:
            cout<<"Nhap id sinh vien can xoa"<<endl;
            cin.ignore();
            getline(cin,id);
            deleteNode(root,id);
            break;
            case 4:
             cout<<"Nhap id sinh vien can tim kiem"<<endl;
             cin.ignore();
             getline(cin,id);
             search(root,id);
             break;
             case 5:
             cout<<"Hay nhap id sinh vien can chinh sua diem"<<endl;
             cin.ignore();
             getline(cin,id);
             cout<<"Hay nhap diem can sua"<<endl;
             cin>>diem;
             updateDiem(root,id,diem);
             break ;
            case 0:
            return 0;
        }
       system("pause");
       system("cls");
    }
    return 0;
}