#include<iostream>
using namespace std;
class Polar{
    int r,a;
    static int count;
public:
    Polar(){
        r=0,a=0;
        count++;
    }
    Polar(int x,int y){
        r=x,a=y;
        count++;
    }
    int getCount(){
        return count;
    }
    ~Polar(){
        count--;
    }
};
int Polar::count;
int main(int argc, char const *argv[])
{
    Polar p1,p2;
    {
        Polar p3,p4;
        cout<<"Count : "<<p1.getCount();
    }
    cout<<"\nCount : "<<p1.getCount()<<endl;
    return 0;
}
