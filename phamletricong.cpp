#include "headers/header.cpp"

using namespace std;

#define MAX_LINES 5
#define MAX_LINE_LENGTH 17

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
    void printArray(int *pLF, const int &size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << *(pLF + i) << " ";
        }
        cout << endl;
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
        cout << endl;
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
        printArray(LF1, MAX_LINE_LENGTH);
        cout << endl;
        printArray(LF2, MAX_LINE_LENGTH);
        cout << endl;
        cout << EXP1 << endl;
        cout << EXP2 << endl;
        cout << T1 << endl;
        cout << T2 << endl;
        cout << E << endl;
    }

    // tinh tong so quan trong moi quan doan LF
    int sumLF(const int *pRT)
    {
        int S = 0;
        for (int i = 0; i < MAX_LINE_LENGTH; i++)
        {
            S += *(pRT + i);
        }
        return S;
    }
};

class task1 : virtual public task0
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

class task2 : virtual public task0
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
    string (*pFunc)(const string);

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
        int ID = 0;
        switch (IDsize)
        {
        case 0:
            cout << "INVALID";
            break;
        case 1:
            targetRef(IDfilter[0], pRT);
            break;
        case 2:
            ID = ((IDfilter[0] + IDfilter[1]) % 5) + 3;
            targetRef(ID, pRT);
            break;
        case 3:
            ID = (*max_element(IDfilter.begin(), IDfilter.end()) % 5) + 3;
            targetRef(ID, pRT);
            break;
        default:
            cout << "INVALID";
            break;
        }
    }

    // ham thuc hien task2.2
    void decodeTarget(const string &message)
    {
        pRT = (string *)rightTarget;
        if (EXP1 >= 300 && EXP2 >= 300)
        {
            cout << decodeMessage(message, caesarCipher, pRT) << endl;
        }
        else if (EXP1 < 300 || EXP2 < 300)
        {
            cout << decodeMessage(message, stringReverse, pRT) << endl;
        }
    }

    // doi chieu target
    void targetRef(const int &ID, string *target)
    {
        if (3 <= ID && ID <= 7)
        {
            for (int i = 0; i < 5; i++)
            {
                if (stoi(*(target + i * 2)) == ID)
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
            if (isdigit(input[i]))
            {
                vector.push_back((int)input[i] - 48);
            }
        }
    }

    // giai ma va doi chieu voi muc tieu can danh chiem
    string decodeMessage(const string &message, string (task2::*pFunc)(const string &), string *pRT)
    {
        string messageDecoded = (this->*pFunc)(message);
        transform(messageDecoded.begin(), messageDecoded.end(), messageDecoded.begin(), ::tolower);
        for (int i = 0; i < 5; i++)
        {
            string temp = *(pRT + i * 2 + 1);
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if (messageDecoded == temp)
            {
                return *(pRT + i * 2 + 1);
            }
        }
        return "INVALID";
    }

    // giai ma bang pp Caesar Cipher
    string caesarCipher(const string &message)
    {
        int shift = (EXP1 + EXP2) % 26;
        string messageDecoded = "";
        for (int i = 0; i < message.size(); i++)
        {
            if (!isdigit(message[i]) && !isalpha(message[i]) && message[i] != ' ')
            {
                return "INVALID";
            }
            if (islower(message[i]))
            {
                messageDecoded += (message[i] - 'a' + shift) % 26 + 'a';
                continue;
            }
            if (isupper(message[i]))
            {
                messageDecoded += (message[i] - 'A' + shift) % 26 + 'A';
                continue;
            }
            if (isdigit(message[i]) || message[i] == ' ')
            {
                messageDecoded += message[i];
                continue;
            }
        }
        return messageDecoded;
    }

    // giai ma bang pp Dao Nguoc Chuoi
    string stringReverse(const string &message)
    {
        string messageDecoded = "";
        for (int i = message.size() - 1; i >= 0; i--)
        {
            messageDecoded += message[i];
        }
        return messageDecoded;
    }
};

class task3 : virtual public task0
{
private:
    float delT1 = 0, delT2 = 0;

public:
    task3(const string &filename)
    {
        readFile(filename);
    }

    // ham thuc hien task3
    void manageLogistics()
    {
        int sLF1 = sumLF(LF1),
            sLF2 = sumLF(LF2);
        if (E == 0)
            ifEis0(delT1, delT2, sLF1, sLF2);
        else if (E >= 1 && E <= 9)
            ifEis19(delT1, delT2, sLF1, sLF2);
        else if (E >= 10 && E <= 29)
            ifEis1029(delT1, delT2, sLF1, sLF2);
        else if (E >= 30 && E <= 59)
            ifEis3059(delT1, delT2, sLF1, sLF2);
        cout << T1 << " " << T2 << endl;
    }

    // neu E = 0
    void ifEis0(float &delT1, float &delT2, const int &sLF1, const int &sLF2)
    {
        delT1 = (((float)sLF1 / (sLF1 + sLF2)) * (T1 + T2)) * (1 + ((float)(EXP1 - EXP2) / 100));
        delT2 = (float)(T1 + T2) - delT1;
        T1 += round(delT1);
        T2 += round(delT2);
    }

    // neu E thuoc [1,9]
    void ifEis19(float &delT1, float &delT2, const int &sLF1, const int &sLF2)
    {
        T1 -= round((E * 0.01) * T1);
        T2 -= round((E * 0.005) * T2);
    }

    // neu E thuoc [10,29]
    void ifEis1029(float &delT1, float &delT2, const int &sLF1, const int &sLF2)
    {
        T1 = min(T1 + (E * 50), 3000);
        T2 = min(T2 + (E * 50), 3000);
    }

    // neu E thuoc [30,59]
    void ifEis3059(float &delT1, float &delT2, const int &sLF1, const int &sLF2)
    {
        T1 += round((E * 0.005) * T1);
        T2 += round((E * 0.002) * T2);
    }
};

class task4 : virtual public task0
{
private:
    int battleField[10][10];
    float S = 0;
    int *pRT;

public:
    task4() {};
    task4(const string &filename)
    {
        readFile(filename);
    }

    // ham thuc hien task4
    void planAttack()
    {
        S = (sumLF(LF1) + sumLF(LF2)) + (EXP1 + EXP2) * 5 + (T1 + T2) * 2;
        pRT = (int *)battleField;
        insertBattleField(pRT, 10, "battleField.txt");
        // showBattleField(pRT, 10);
        checkBattleField(pRT, S);
        S = round(S);
        cout << S << endl;
    }

    // nhap ma tran
    void insertBattleField(int *pRT, const int &rowcol, const string &filename)
    {
        fstream file(filename, ios::in);
        string line, num;
        int i = 0;
        stringstream ss(line);
        while (getline(file, line) && i < rowcol)
        {
            int j = 0;
            stringstream s(line);
            while (s >> num && j < rowcol)
            {
                *(pRT + i * rowcol + j) = stoi(num);
                j++;
            }
            i++;
        }

        file.close();
    }

    // xuat ma tran
    void showBattleField(int *pRT, const int &rowcol)
    {
        for (int i = 0; i < rowcol; i++)
        {
            for (int j = 0; j < rowcol; j++)
            {
                cout << *(pRT + i * rowcol + j) << " ";
            }
            cout << endl;
        }
    }

    // duyet ma tran va cap nhat S tai moi vi tri
    void checkBattleField(const int *pRT, float &S)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i % 2 == 0)
                    S -= (*(pRT + i * 10 + j) * 2 / 3);
                else
                    S -= (*(pRT + i * 10 + j) * 3 / 2);
            }
        }
    }
};

class task5 : virtual public task0, public task4
{
private:
    int supply[5][5];
    int *pRT;

public:
    task5(const string &filename)
    {
        readFile(filename);
    }

    // sap xep theo thu tu tang dan
    void sortAscending(int *pRT)
    {
        for (int i = 0; i < 24; i++)
        {
            for (int j = i; j < 25; j++)
            {
                if (*(pRT + i) > *(pRT + j))
                {
                    int temp = *(pRT + i);
                    *(pRT + i) = *(pRT + j);
                    *(pRT + j) = temp;
                }
            }
        }
    }

    // chon 5 o tiep te trong mang supply
    void pickSupply(const int *pRT, const int &shortfall)
    {
        int pickedSup[5];
        for (int i = 0; i < 5; i++)
        {
            pickedSup[i] = *(pRT + i);
        }
        int i = 4,
            k = 25;
        while (addEleArr(pickedSup) < shortfall && i >= 0)
        {
            int j = i + 1;
            while (addEleArr(pickedSup) < shortfall && j < k)
            {
                pickedSup[i] = *(pRT + j);
                j++;
            }
            i--;
            k--;
        }
        printArray(pickedSup, 5);
        cout << addEleArr(pickedSup) << endl;
    }

    // cong cac phan tu trong mang
    int addEleArr(const int *pS)
    {
        int S = 0;
        for (int i = 0; i < 5; i++)
        {
            S += *(pS + i);
        }
        return S;
    }

    // ham thuc hien task5
    void resupply(const int &shortfall)
    {
        pRT = (int *)supply;
        insertBattleField(pRT, 5, "supply.txt");
        // showBattleField(pRT, 5);
        sortAscending(pRT);
        pickSupply(pRT, shortfall);
        // showBattleField(pRT, 5);
    }
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
    // t2.determineRightTarget("Kon4 Tum7");
    // t2.decodeTarget("Pal cUd");

    // exec task3
    task3 t3(filename);
    // t3.manageLogistics();

    // exec task4
    task4 t4(filename);
    // t4.planAttack();

    // exec task5
    task5 t5(filename);
    // t5.resupply(1050);
    return 0;
}