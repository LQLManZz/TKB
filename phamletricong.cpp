#include "headers/header.cpp"

#define MAX_LINES 5
#define MAX_LINE_LENGTH 17

using namespace std;

class task0
{
private:
    int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;
    string data[MAX_LINES][MAX_LINE_LENGTH];
    string filename, line;

public:
    task0(const string &filename) : filename(filename) {}
    // thay cac ki tu thanh space
    void spaceFilter(string &line)
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '[' || line[i] == ']' || line[i] == ',')
            {
                line[i] = ' ';
            }
        }
    }
    // in mang 2D ra man hinh
    void printArray()
    {
        for (int i = 0; i < MAX_LINES; i++)
        {
            for (int j = 0; j < MAX_LINE_LENGTH; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool readFile()
    {
        fstream file(filename, ios::in);
        // check xem file co ton tai ko
        if (!file)
        {
            return false;
        }
        // check xem file co noi dung ko
        if (file.peek() == ifstream::traits_type::eof())
        {
            return false;
        }
        // read file roi dua vao mang 2D
        int i = 0;
        while (getline(file, line) && i < MAX_LINES)
        {
            spaceFilter(line);
            stringstream ss(line);
            string num;
            int j = 0;
            while (ss >> num && j < MAX_LINE_LENGTH)
            {
                data[i][j] = num;
                j++;
            }
            i++;
        }
        file.close();

        printArray();
        return true;
    }
};

class task1
{
private:
public:
};

int main()
{
    task0 t1("inputfile.txt");
    t1.readFile();
    return 0;
}