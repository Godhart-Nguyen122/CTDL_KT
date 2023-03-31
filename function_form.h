#include<bits/stdc++.h>
using namespace std;

string form_name(string s);
bool check_number(string s);
bool check_day(int day,int month, int year);
string formddmmyy(int day, int month ,int year);


string form_name(string s){
    string tmp;
    stringstream ss(s);
    string result="";
    while(ss>>tmp){
         tmp[0]=toupper(tmp[0]);
         for(int i=1;i<tmp.length();i++){
            tmp[i]=tolower(tmp[i]);
         }
         result=result+tmp+" ";
    }
    return result;
}
bool check_number(string s){
    for(int i=0;i<s.length();i++){
        if(!(s[i]>=48 && s[i]<=57)){
            return false;
        }
    }
    return true;
}

bool check_day(int day,int month, int year){
    int date[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(year %400 ==0){
        date[2]=29;
    }
    else {
        date[2]=28;
    }
    if(day<=0||day>=32 ||month <=0 ||month >=13 ||year <0){
        return false;
    }
    if(day>date[month]){
        return false;
    }
    return true;
}
string formddmmyy(int day, int month ,int year){
    string days ,months,years;
    years=to_string(year);
    if(day<10){
        days="0"+to_string(day);
    }
    if(month <10){
        months="0"+to_string(month);
    }
    return days+"/"+months+"/"+years;
}
bool check_Id(){
    
}