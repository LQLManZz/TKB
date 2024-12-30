// // #include <iostream>
// // using namespace std;

// // int main()
// // {
// //     char x[100];
// //     cin.ignore();
// //     cin.getline(x, 100);
// //     cout << x;
// //     return 0;
// // }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int i, j;
//     int *pa, a[4][6];
//     pa = (int *)a;
//     cout << "\nNhap vao cac phan tu cua mang:";
//     for (i = 0; i < 4; i++)
//         for (j = 0; j < 6; j++)
//         {
//             cout << "a[" << i << "][" << j << "]=";
//             cin >> *(pa + i * 6 + j);
//         }
//     cout << "\n\n";
//     for (i = 0; i < 4; i++)
//     {
//         for (j = 0; j < 6; j++)
//             cout << "   a[" << i << "][" << j << "]=" << *(pa + i * 6 + j);
//         cout << "\n";
//     }
//     getchar();
// }

#include <iostream>
#include <math.h>
using namespace std;
class tinh
{
public:
    tinh(int a = 0, int b = 0)
    {
        tinh::a = a;
        tinh::b = b;
    }
    friend istream &operator>>(istream &is, tinh t)
    {
        cout << "Nhap 2 so a,b :";
        is >> t.a >> t.b;
        return is;
    }
    friend ostream &operator<<(ostream &os, tinh p)
    {
        os << "Tong 2 so la: " << p.a + p.b;
        os << "\nHieu 2 so la: " << p.a - p.b;
        return os;
    }

private:
    int a, b;
};

int main()
{
    tinh s1;
    cin >> s1;
    cout << s1;
    return 0;
}