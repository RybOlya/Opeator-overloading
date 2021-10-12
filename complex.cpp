#include <iostream>
#include <math.h>
#include <complex>
class Number {
public:
    float argument, A, z[8], angle;

    float ar = A * sin(angle);
    float br = A * cos(angle);
    friend std::ostream& operator<< (std::ostream& out, const Number& point);
};
float PolReal(int A, float angle)
{
    return A * sin(angle);
}
float PolImag(int A, float angle)
{
    return A * cos(angle);
}
class Den
{    
public:
    Number op;
    double pi = 3.14159265359;
    int A1, A2;// = 4 = 9;
    float angle1= pi / 6, angle2  = pi / 3;
    float a[2] = { PolReal(A1,angle1), PolReal(A2,angle2)};
    float b[2] = { PolImag(A1,angle1), PolImag(A2,angle2)};

};
 
void print(Number op) {
    std::cout << op.z[0] << " + i" << op.z[1] << std::endl;
}
Number operator +(Number A, Den B)
{
    Number op;
    op.z[0] = B.a[0] + B.a[1];
    op.z[1] = B.b[0] + B.b[1];
    return op;
}
Number operator -(Number A, Den B)
{
    Number op;
    op.z[0] = B.a[0] - B.a[1];
    op.z[1] = B.b[0] - B.b[1];
    return op;
}
Number operator *(Number A, Den B)
{
    Number op;
    op.z[0] = (B.a[0] * B.a[1]) - (B.b[0] * B.b[1]);
    op.z[1] = (B.a[0] * B.b[1]) + (B.a[1] * B.b[0]);
    std:: cout << op.z[0];
    return op;
}
bool operator ==(Number A, Den B)
{
    return B.a[0] == B.a[1] && B.b[0] == B.b[1];
    //return op;
}
bool operator <(Number A, Den B)
{
    return B.a[0] < B.a[1] && B.b[0] < B.b[1];
}
bool operator >(Number A, Den B)
{
    return B.a[0] > B.a[1] && B.b[0] > B.b[1];
}
//Number operator <<(Number A, Den B)
//{
//    Number op;
//    std::cout << op.z[0] << " + i" << op.z[1] << std::endl;
//}
std::ostream& operator<<(std::ostream& out, const Number& point)
{
    Number op;
    out << point.z[0] << " + i" << point.z[1] << std::endl;

    return out;
}
std::istream& operator>> (std::istream& in, Den& point)
{
    // Поскольку operator>> является другом класса Point, то мы имеем прямой доступ к членам Point.
    // Обратите внимание, параметр point (объект класса Point) должен быть неконстантным, чтобы мы имели возможность изменить члены класса
    in >> point.A1;
    in >> point.A2;
    //in >> point.angle1;
    //in >> point.angle1;
    return in;
}
int main()
{
    //Number fin;
    Number A, fin;
    Den B,point;
    std::cin >> point;
    bool b1 = A == B;
    bool b2 = A < B;
    bool b3 = A > B;
    std::cout << b1 << b2 << b3 <<std::endl;
    std::cout  << B.a[0] << " + i" << B.b[0] << " + " << B.a[1] << " + i" << B.b[1] << " = ";
    fin = A + B;
    print(fin);
    std::cout << B.a[0] << " + i" << B.b[0] << " - " << B.a[1] << " + i" << B.b[1] << " = ";
    fin = A - B;
    print(fin);
    std::cout << B.a[0] << " + i" << B.b[0] << " * " << B.a[1] << " + i" << B.b[1] << " = ";
    fin = A * B;
    print(fin);

    return 0;
}