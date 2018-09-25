#include<iostream>
#include<stdio.h>
using namespace std;
FILE * pFile;
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
    cout<<"\nEnter Students Roll No: ";
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
    cout<<"Grade : "<<d.grade<<endl;
    return cout;
}
void generateResult(DAC_STUDENT d[],int n){
    
    pFile = fopen ("myfile.txt","w");

    for(int i=0;i<n;i++){
        d[i].totm=d[i].m1+d[i].m2+d[i].m3;
        d[i].avg=d[i].totm/3;
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
        fputs("Roll No : ",pFile);
    	fprintf(pFile,"%d",d[i].rollno);
        fputs("\nName : ",pFile);
    	fprintf(pFile,"%s",d[i].name);
        fputs("\nModule 1 : ",pFile);
    	fprintf(pFile,"%d",d[i].m1);
        fputs("\nModule 2 : ",pFile);
    	fprintf(pFile,"%d",d[i].m2);
        fputs("\nModule 3 : ",pFile);
    	fprintf(pFile,"%d",d[i].m3);
        fputs("\nTotal Marks : ",pFile);
    	fprintf(pFile,"%d",d[i].totm);
        fputs("\nGrade : ",pFile);
    	fprintf(pFile,"%c",d[i].grade);
        fputs("\n\n",pFile);
        
    }
    fclose(pFile);
}
int main(int argc, char const *argv[])
{
    DAC_STUDENT d1,d2;
    int n=0;
    cout<<"Enter Number of Students : ";
    cin>>n;
    DAC_STUDENT d[n];
    for (int i=0;i<n;i++){
        cout<<"\nEnter Detail for Student "<<i+1<<" : ";
        cin>>d[i];
    }
    generateResult(d,n);
    cout<<"Result : \n";
    for(int i=0;i<n;i++){
        cout<<d[i];
    }
    
    return 0;
}
