#include <iostream>
#include <cmath>

using namespace std;

class Complex {
    friend Complex operator*(const Complex &, const Complex &);
    friend Complex operator-(const Complex &, const Complex &);
    friend Complex operator+(const Complex &, const Complex &);

public:
    explicit Complex(int re = 0, int im = 0) : real(re), imaginary(im) {}

    void print() const;

    Complex operator--();
    Complex operator--(int);
    Complex operator++();
    Complex operator++(int);

private:
    int real;
    int imaginary;
};

int main() {
    Complex x(2, 3), y(3, 4);
    x.print();
    y.print();

    Complex a = x * y;
    Complex b = x + y;
    Complex c = x - y;
    Complex d = ++x;
    Complex e = --y;

    cout << "-----------------------------------------" << endl;
    cout << "x * y ===> ";
    a.print();
    cout << "x + y ===> ";
    b.print();
    cout << "x - y ===> ";
    c.print();
    cout << "++x ===> ";
    d.print();
    cout << "--y ===> ";
    e.print();
}

Complex operator*(const Complex &x, const Complex &y) {
    return Complex((x.real * y.real) - (x.imaginary * y.imaginary),
                   (x.real * y.imaginary) + (x.imaginary * y.real));
}

Complex operator-(const Complex &x, const Complex &y) {
    return Complex(x.real - y.real, x.imaginary - y.imaginary);
}

Complex operator+(const Complex &x, const Complex &y) {
    return Complex(x.real + y.real, x.imaginary + y.imaginary);
}

void Complex::print() const {
    cout << "Your number is: " << real;
    if (imaginary >= 0)
        cout << " + " << imaginary << "i" << endl;
    else
        cout << " - " << -imaginary << "i" << endl;
}

Complex Complex::operator++() {
    ++real;
    return *this;
}

Complex Complex::operator--() {
    --real;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    ++real;
    return temp;
}

Complex Complex::operator--(int) {
    Complex temp = *this;
    --real;
    return temp;
}
