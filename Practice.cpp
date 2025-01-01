#include <iostream>
#include <math.h>
#include <string>

using namespace std;
class tinh
{
public:
    // tinh(int a = 0, int b = 0)
    // {
    //     this->a = a;
    //     this->b = b;
    // }
    friend istream &operator>>(istream &is, tinh &t)
    {
        cout << "Nhap 2 so a,b: ";
        is >> t.a >> t.b;
        return is;
    }
    friend ostream &operator<<(ostream &os, const tinh &p)
    {
        os << "Tong 2 so la: " << p.a + p.b;
        os << "\nHieu 2 so la: " << p.a - p.b;
        return os;
    }

private:
    int a, b;
};

class BT
{
public:
    friend istream &operator>>(istream &in, BT &a)
    {
        do
        {
            cout << "Nhap so nguyen x: ";
            in >> a.x;
        } while (a.x > 10);
        return in;
    }
    friend ostream &operator<<(ostream &out, BT &a)
    {
        a.y = 2 * a.x; // Initialize y before using it
        for (int l = 0; l < 20; l++)
        {
            for (int j = 0; j < 10; j++)
            {
                a.A[l][j] = l * float(a.x) - 2 * j / float(a.y);
                out << "A[" << l << "][" << j << "] = " << a.A[l][j] << endl;
            }
        }
        return out;
    }

private:
    float A[20][10];
    int x, y;
};

class testConstructorDestructor
{
private:
    int a, b;
    char c[100];

public:
    testConstructorDestructor(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    ~testConstructorDestructor() {};
    friend istream &operator>>(istream &in, testConstructorDestructor &a)
    {
        cout << "\nNhap xau c: ";
        in.ignore();
        in.getline(a.c, 100);
        return in;
    }
    friend ostream &operator<<(ostream &out, testConstructorDestructor &b)
    {
        out << "Tich 2 so nguyen a*b = " << b.a * b.b;
        out << "\nXau ban vua nhap: " << b.c;
        return out;
    }
};

int main()
{
    testConstructorDestructor q1(3, 5);
    cin >> q1;
    cout << q1;
    return 0;
}