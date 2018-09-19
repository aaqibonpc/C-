#include<iostream>
#include<string.h>
using namespace std;
class String{
    char *sp;
    int len;
public:
    String(){
        sp=NULL;
        len=0;
    }
    String(char *c){
        len=strlen(c);
        sp=new char[len+1];
        strcpy(sp,c);
    }
    String(const String &s1){
        len=s1.len;
        sp=new char[len];
        strcpy(sp,s1.sp);
    }
    String operator +(String s){
        String temp;
        temp.len=len+s.len;
        temp.sp=new char[temp.len+1];
        strcpy(temp.sp,sp);
        strcat(temp.sp,s.sp);
        return temp;
    }
    String operator =(String s){
        if(sp!=NULL)
        delete sp;
        sp=new char[s.len+1];
        strcpy(sp,s.sp);
        return *(this);
    }
    char operator [](int index){
        return sp[index];
    }
friend ostream & operator <<(ostream &,String);
friend istream & operator >>(istream &,String &);
};
ostream & operator <<(ostream &cout,String s){
    if(s.sp!=NULL)
    cout<<"String : "<<s.sp<<endl;
    else
    cout<<"String is NULL : "<<endl;
    return (cout);
}
istream & operator >>(istream &cin,String &s){
    char ch[100];
    cout<<"Enter String : ";
    cin>>ch;
    if(s.sp!=NULL)
    delete s.sp;
    s.sp=new char[strlen(ch)+1];
    strcpy(s.sp,ch);
    return cin;
}
int main(int argc, char const *argv[])
{
    String s1,s2("heeeyyyaa"),s3(s2),s4;
    cout<<s2;
    cout<<s3;
    s1=s2+s3;
    cout<<s1;
    cout<<s2[4]<<endl;
    cin>>s4;
    cout<<s4;
    return 0;
}
