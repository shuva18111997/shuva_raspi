#include<iostream>
using namespace std;
class cube
{
    private:
    int side,volume;
    public:
    void take();
    void calculate();
    void out();

};
void cube::take()
{
    cout<<"Enter the sides of a cube:";
    cin>>side;
}
void cube::calculate()
{
    volume=side*side*side;

}
void cube::out()
{
    cout<<"The volume of the given cube is :";
    cout<<volume;
}
main()
{
    cube a;
    a.take();
    a.calculate();
    a.out();
    }
