#include<iostream>
#include<math.h>
float PolReal(float x, float y)
{
    float w;
	w = (x * cos(y));
    return w;
}
float PolImag(float x, float y)
{
    float w;
    w = (x * sin(y));
    return w;
}
class Complex {
private:
    double Real, Imag;
public:
    Complex() {
        this->Real = 0.0;
        this->Imag = 0.0;
    }

    Complex(double real, double img) {
        this->Real = real;
        this->Imag = img;
    }

    friend Complex operator + (Complex const&, Complex const&);
    friend Complex operator - (Complex const&, Complex const&);
    friend Complex operator * (Complex const&, Complex const&);
    friend bool operator == (Complex const&, Complex const&);
    friend bool operator > (Complex const&, Complex const&);
    friend bool operator < (Complex const&, Complex const&);
    friend std::ostream& operator<< (std::ostream& out, Complex z);
    friend std::istream& operator>> (std::istream& is, Complex z);
};

Complex operator + (Complex const& c1, Complex const& c2)
{
    return Complex(c1.Real + c2.Real, c1.Imag + c2.Imag);
}
Complex operator - (Complex const& c1, Complex const& c2)
{
    return Complex(c1.Real - c2.Real, c1.Imag - c2.Imag);
}
Complex operator * (Complex const& c1, Complex const& c2)
{
    return Complex(((c1.Real * c2.Real) - (c1.Imag * c2.Imag)), ((c1.Real * c2.Imag) - (c1.Imag * c2.Real)));
}

bool operator ==(Complex const& c1, Complex const& c2)
{
    return c1.Real == c2.Real && c1.Imag == c2.Imag;
}
bool operator <(Complex const& c1, Complex const& c2)
{
    return c1.Real < c2.Real && c1.Imag < c2.Imag;
}
bool operator >(Complex const& c1, Complex const& c2)
{
    return c1.Real > c2.Real && c1.Imag > c2.Imag;
}
std::ostream& operator<<(std::ostream& out, Complex z)
{
	out <<z.Real << " + i" << z.Imag << std::endl;
	return out;
}
std::istream& operator>> (std::istream& is, Complex z)
{
    is >> z ;
    return is;
}
int main()
{
    float a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;
    Complex c1(PolReal(a1,a2), PolImag(a1, a2)), c2(PolReal(b1, b2), PolImag(b1, b2));
    Complex c3;
    std::cout << c1;
    std::cout << c2;
    bool equal = c1 == c2;
    bool smaller = c1 < c2;
    bool bigger = c1 > c2;
    if (equal == 1)
        std::cout << " Complex numbers are equal\n";
    if (bigger == 1)
        std::cout << " First complex number is bigger\n";
    if(smaller == 1)
        std::cout << " Second complex number is bigger\n";
    std::cout << equal << smaller << bigger << std::endl;
    c3 = c1 + c2; 
    std::cout << c3;
    c3 = c1 - c2;
    std::cout << c3;
    c3 = c1 * c2;
    std::cout << c3;
    return 0;
}
