#include "headers/header.cpp"

#define MAX_LINES 5
#define MAX_LINE_LENGTH 17

using namespace std;

class task0
{
protected:
    int LF1[17], LF2[17], EXP1, EXP2, T1, T2, E;

private:
    string data[MAX_LINES][MAX_LINE_LENGTH];
    string filename, line;
    string *pData;

public:
    // ham thuc hien task 0
    bool readFile(const string &filename)
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

        // check xem noi dung file co hop le ko
        if (!checkIfFileValid(filename))
        {
            return false;
        }

        // read file roi dua vao mang 2D
        int i = 0;
        pData = (string *)data;
        while (getline(file, line) && i < MAX_LINES)
        {
            spaceFilter(line);
            stringstream ss(line);
            string num;
            int j = 0;
            while (ss >> num && j < MAX_LINE_LENGTH)
            {
                *(pData + i * MAX_LINE_LENGTH + j) = num;
                j++;
            }
            i++;
        }

        // insert data vao cac bien
        insertData(LF1, pData, 0, 0, 1000);
        insertData(LF2, pData, 1, 0, 1000);
        insertData(EXP1, EXP2, pData, 2, 0, 600);
        insertData(T1, T2, pData, 3, 0, 3000);
        insertData(E, pData, 4, 0, 99);

        // printArray(pData);
        // cout << endl;

        file.close();

        return true;
    }

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

    // check xem noi dung file co hop le ko
    bool checkIfFileValid(const string &filename)
    {
        fstream file(filename, ios::in);
        string lineTemp;
        int elem;
        int count = 0;
        while (getline(file, lineTemp))
        {
            spaceFilter(lineTemp);
            if (lineTemp.empty())
                break;
            stringstream ss1(lineTemp);
            while (ss1 >> elem)
            {
                count++;
            }
            count++;
        }
        if (count < 44)
            return false;
        return true;
    }

    // in mang ra man hinh
    void printArray(int *pLF)
    {
        for (int i = 0; i < MAX_LINE_LENGTH; i++)
        {
            cout << *(pLF + i) << " ";
        }
    }
    void printArray(string *pData)
    {
        for (int i = 0; i < MAX_LINES; i++)
        {
            for (int j = 0; j < MAX_LINE_LENGTH; j++)
            {
                cout << *(pData + i * MAX_LINE_LENGTH + j) << " ";
            }
            cout << endl;
        }
    }

    // insert data vao cac bien
    void insertData(int *pLF, string *pData, const int &row, const int &min, const int &max)
    {
        for (int i = 0; i < MAX_LINE_LENGTH; i++)
        {
            *(pLF + i) = stoi(*(pData + row * MAX_LINE_LENGTH + i));
            *(pLF + i) = clamp(*(pLF + i), min, max);
        }
    }
    void insertData(int &A, int &B, string *pData, const int &row, const int &min, const int &max)
    {
        A = stoi(*(pData + row * MAX_LINE_LENGTH));
        A = clamp(A, min, max);
        B = stoi(*(pData + row * MAX_LINE_LENGTH + 1));
        B = clamp(B, min, max);
    }
    void insertData(int &C, string *pData, const int &row, const int &min, const int &max)
    {
        C = stoi(*(pData + row * MAX_LINE_LENGTH));
        C = clamp(C, min, max);
    }

    // check data da duoc dua vao cac bien chua
    void printInheritance()
    {
        printArray(LF1);
        cout << endl;
        printArray(LF2);
        cout << endl;
        cout << EXP1 << endl;
        cout << EXP2 << endl;
        cout << T1 << endl;
        cout << T2 << endl;
        cout << E << endl;
    }
};

class task1 : public task0
{
private:
    int sumPow = 0;
    int w[17] = {1, 2, 3, 4, 5, 7, 8, 9, 10, 12, 15, 18, 20, 30, 40, 50, 70};

public:
    task1(const string &filename)
    {
        readFile(filename);
    }

    // ham thuc hien task1
    void gatherForces()
    {
        for (int i = 0; i < MAX_LINE_LENGTH; i++)
        {
            sumPow += ((LF1[i] + LF2[i]) * w[i]);
        }
        cout << "Power level = " << sumPow << endl;
    }
};

class task2 : public task0
{
private:
    string falseTarget[3][2] = {"0", "Kon Tum",
                                "1", "Pleiku",
                                "2", "Gia Lai"};
    string rightTarget[5][2] = {"3", "Buon Ma Thuot",
                                "4", "Duc Lap",
                                "5", "Dak Lak",
                                "6", "National Route 21",
                                "7", "National Route 14"};
    vector<int> IDfilter;
    string *pRT;

public:
    task2(const string &filename)
    {
        readFile(filename);
    }

    // ham thuc hien task2.1
    void determineRightTarget(const string &target)
    {
        checkLineNumber(target, IDfilter);

        // check so phan tu cua mang ID, tu do dua ra ket qua
        int IDsize = IDfilter.size();
        pRT = (string *)rightTarget;
        switch (IDsize)
        {
        case 0:
            cout << "INVALID";
            break;
        // case 1:
        //     targetRef(IDfilter[0], pRT);
        //     break;
        // case 2:
        //     int ID = (*max_element(IDfilter.begin(), IDfilter.end()) % 5) + 3;
        //     targetRef(ID, pRT);
        //     break;
        // case 3:
        //     int ID = (*max_element(IDfilter.begin(), IDfilter.end()) % 5) + 3;
        //     targetRef(ID, pRT);
        //     break;
        default:
            cout << "INVALID";
            break;
        }
    }

    // doi chieu target
    void targetRef(const int &ID, string *target)
    {
        if (3 <= ID && ID <= 7)
        {
            for (int i = 0; i < 5; i++)
            {
                if (stoi(*(target + i * 2 + 1)) == ID)
                {
                    cout << *(target + i * 2 + 1) << endl;
                }
            }
        }
        else if (0 <= ID && ID <= 3)
        {
            cout << "DECOY" << endl;
        }
        else
            cout << "INVALID" << endl;
    }

    // check xem input co so khong
    void checkLineNumber(const string &input, vector<int> &vector)
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (48 <= (int)input[i] && (int)input[i] <= 57)
            {
                vector.push_back((int)input[i] - 48);
            }
        }
    }

    // ham thuc hien task2.2
    void decodeTarget() {}
};

int main()
{
    string filename = "inputfile.txt";

    // exec task0
    task0 t0;
    // t0.readFile(filename);

    // exec task1
    task1 t1(filename);
    // t1.gatherForces();

    // exec task2
    task2 t2(filename);
    t2.determineRightTarget("Kon3 Tum");
    return 0;
}