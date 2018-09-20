#include<iostream>
#include<stdio.h>
using namespace std;
class DAC_STUDENT{
    int rollno,m1,m2,m3,totm;
    float avg;
    char name[20],grade;
public:
friend istream & operator >>(istream &,DAC_STUDENT &);
friend ostream & operator <<(ostream &,DAC_STUDENT);
friend void generateResult(DAC_STUDENT [],int);
};
istream & operator >>(istream &cin,DAC_STUDENT &d){
    cout<<"Enter Students Roll No: ";
    cin>>d.rollno;
    cout<<"Enter Name : ";
    cin>>d.name;
    cout<<"Enter Marks in Module 1 : ";
    cin>>d.m1;
    cout<<"Enter Marks in Module 2 : ";
    cin>>d.m2;
    cout<<"Enter Marks in Module 3 : ";
    cin>>d.m3;
    return cin;
}
ostream & operator <<(ostream &cout,DAC_STUDENT d){
    cout<<"Roll No : "<<d.rollno<<endl;
    cout<<"Name : "<<d.name<<endl;
    cout<<"Module 1 : "<<d.m1<<endl;
    cout<<"Module 2 : "<<d.m2<<endl;
    cout<<"Module 3 : "<<d.m3<<endl;
    cout<<"Total Marks : "<<d.totm<<endl;
    cout<<"Grade : "<<d.totm<<endl;
    return cout;
}
void generateResult(DAC_STUDENT d[],int n){
    FILE * pFile;
    pFile = fopen ("myfile.txt","a");
    for(int i=0;i<n;i++){
        d[i].totm=d[i].m1+d[i].m2+d[i].m3;
        if(d[i].avg>=90)
        d[i].grade='A';
        else if(d[i].avg >=80)
        d[i].grade='B';
        else if(d[i].avg >=70)
        d[i].grade='C';
        else if(d[i].avg >=60)
        d[i].grade='D';
        else if(d[i].avg >=50)
        d[i].grade='E';
        else
        d[i].grade='F';
        fputs("\nRoll No : "+d[i].rollno,pFile);
        
    }
    fclose(pFile);
}
int main(int argc, char const *argv[])
{
    DAC_STUDENT d1,d2,d[5];

    cin>>d[0];
    generateResult(d,5);
    cout<<d[0];
    return 0;
}
