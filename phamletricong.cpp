#include "headers/header.cpp"

using namespace std;

class task0
{
private:
    fstream filename;
    int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;

public:
    task0() : filename("inputfile.txt", ios::in) {};
    bool readFile(task0 &a)
    {
        // check xem file co ton tai ko
        if (!a.filename)
        {
            return false;
        }
        // check xem file co noi dung ko
        if (a.filename.peek() == ifstream::traits_type::eof())
        {
            return false;
        }

        return true;
    }
};

int main()
{
    task0 t1;
    cout << t1.readFile(t1);
    return 0;
}