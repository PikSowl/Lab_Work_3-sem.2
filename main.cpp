#include <iostream>
using std::cin;
using std::cout;
using std::copy;
using std::ostream;
using std::istream;
using std::swap;
using std::endl;

class Complex
{
private:
    double real;
    double image;
    int mas[10] = {1,2,3,4};

public:
    Complex(double a = 0.0, double b = 0.0) : real(a), image(b){}

    Complex(const Complex& z) : real(z.real), image(z.image)
    {
        cout << "copy" << endl;
    }

    Complex& operator=(Complex z)
    {
        cout << "copy assignment" << endl;
        swap(real,z.real);
        swap(image,z.image);
        return *this;
    }

    Complex& operator+=(const Complex& z)
    {
        this->real += z.real;
        this->image += z.image;
        return *this;
    }

    Complex& operator*=(const Complex& z)
    {
        Complex temp = *this;
        this->real = temp.real * z.real - temp.image * z.image;
        this->image = temp.real * z.image + temp.image * z.real;
        return *this;
    }

    int& operator[](int index)
    {
        return mas[index];
    }

    int& at(int index)
    {
        if(0<=index && index < 10)
            return mas[index];
    }

    Complex& operator++()
    {
        this->real +=1;
        return *this;
    }

    Complex operator++(int)
    {
        Complex temp = *this;
        this->real +=1;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Complex& z);
    friend istream& operator>>(istream& in, Complex& z);

    ~Complex() {
        cout << "destructor" << endl;
    }
};

Complex operator+(const Complex& z1, const Complex& z2)
{
    Complex temp = z1;
    temp += z2;
    return temp;
}

Complex operator*(const Complex& z1, const Complex& z2)
{
    Complex temp = z1;
    temp *= z2;
    return temp;
}

ostream& operator<<(ostream& out, const Complex& z)
{
    out << z.real << " + " << z.image << "i, ";
    return out;
}

istream& operator>>(istream& in, Complex& z)
{
    in >> z.real >> z.image;
    return in;
}

int main()
{
    Complex z1(1.1, 3), z2(3,5);

    cout << z1 << z2 << endl;
    Complex z3 = ++z1;
    cout << z1 << z2 << z3 << endl;
    z2 *= z1;
    cout << z1 << z2 << z3 << endl;

    cin >> z1 >> z2;
    cout << z1 << z2 << endl;
    z3 = z1 * z2;
    cout << z1 << z2 << z3 << endl;
    return 0;
}