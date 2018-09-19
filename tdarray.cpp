#include<iostream>
using namespace std;
class tdarray{
    int **ap,rows,cols;
public: 
    tdarray(){
        ap=NULL;
        rows=0;cols=0;
        
    }
    tdarray(int r,int c){
        rows=r;cols=c;
        ap=new int*[r]; 
        for(int i=0;i<r;i++)
        *(ap+i)=new int[c]; //ap[i]=new int[c];
    }
    void insertArray(){
        if(ap!=NULL){
            for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++){
                cout<<"Enter Element "<<i+1<<"x"<<j+1<<" : ";
                cin>>ap[i][j];
            }
        }
    }
tdarray operator +(tdarray t){
    if(rows==t.rows && cols==t.cols){
    tdarray temp;
    temp.rows=rows;temp.cols=cols;
    temp.ap=new int*[rows]; 
        for(int i=0;i<rows;i++)
        temp.ap[i]=new int[rows];
    for(int i=0 ;i<rows;i++)
    for(int j=0;j<cols;j++){
        temp.ap[i][j]=ap[i][j]+t.ap[i][j];
    }
    return temp;
    }
    else{
        tdarray tmp;
        cout<<"Couldnt Perform Addition : \n";
        return tmp;
    }

}
tdarray operator =(tdarray t){
    if(ap!=NULL)
    delete ap;
    ap=new int*[t.rows];
    for(int i=0;i<t.rows;i++)
    *(ap+i)=new int[t.cols];
    for(int i=0;i<t.rows;i++){
        for(int j=0;j<t.cols;j++){
            ap[i][j]=t.ap[i][j];
        }
    }
    rows=t.rows;cols=t.cols;
    return *(this);
}
tdarray operator +(int num){
    for(int i=0;i<rows;i++)
    for(int j=0;j<cols;j++)
    *(*(ap+i)+j)+=num; //ap[i][j]+=num;
    return *(this);
}
friend istream & operator >>(istream &,tdarray &);
friend ostream & operator <<(ostream &,tdarray);
friend tdarray operator +(int ,tdarray);
};
istream & operator >>(istream &cin,tdarray &a){
    cout<<"Enter NUmber of rows and cols : ";
    cin>>a.rows>>a.cols;
    a.ap=new int*[a.rows];
    for (int i=0;i<a.rows;i++){
            *(a.ap+i)=new int[a.cols]; //a.ap[i]=new int[a.cols];
    }
    for(int i=0;i<a.rows;i++)
            for(int j=0;j<a.cols;j++){
                cout<<"Enter Element "<<i+1<<"x"<<j+1<<" : ";
                cin>>a.ap[i][j];
            }
    return cin;
}
ostream & operator <<(ostream &cout,tdarray a){
    cout<<"Matrix is : \n";
    for(int i=0;i<a.rows;i++){
        for(int j=0;j<a.cols;j++)
         cout<<a.ap[i][j]<<"\t";
        cout<<endl;
    }
    return cout;

}
tdarray operator +(int num,tdarray t){
    for(int i=0;i<t.rows;i++)
    for(int j=0;j<t.cols;j++)
    *(*(t.ap+i)+j)+=num; //ap[i][j]+=num;
    return t;
}
int main(int argc, char const *argv[])
{
    tdarray t1,t2,t3;
    cin>>t1>>t2;
    cout<<t1<<t2;
    //t3=t1+t2;
    //cout<<t3;
    //t3=t1+6;
    t3=4+t1;
    cout<<t3;
    return 0;
}
