#include<iostream>
#include<math.h>
using namespace std;
class Point{
    float x,y;
public:
    Point(){
        y=0;
        x=0;
    }
    void get(){
        cout<<"Enter values for X and Y : ";
        cin>>x>>y;
    }



    friend float diff(Point,Point);
};
float diff(Point p1,Point p2){
    return (sqrt((pow(p2.x,2)-pow(p1.x,2))-(pow(p2.y,2)-pow(p1.y,2))));
}
int main(int argc, char const *argv[])
{
    Point p1,p2;
    p1.get();
    p2.get();
    cout<<"Difference is : "<<diff(p1,p2)<<endl;

    return 0;
}
