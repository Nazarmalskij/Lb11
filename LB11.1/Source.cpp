#include <iostream>
#include<fstream>
#include <Windows.h>
#include <time.h>
#include <stdio.h>
using namespace std;

void Create(const char* File_Name);
void Process(const char* File_Name, const char* File_Result, const int x);
void Print(const char* File_Result);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Create("FirstFile.dat");
    Print("FirstFile.dat");

    Process("FirstFile.dat", "Result.dat",0);
    Print("Result.dat");

    return 0;
}
void Create(const char* File_Name)
{
    ofstream First_File(File_Name, ios::binary);

    int y;

    for (int i = 0; i < 20; i++)
    {
        y = (2 * (20 * 1.)) * rand() / RAND_MAX - (20 * 1.);
        First_File.write((char*)&y, sizeof(y));
    }
}
void Process(const char* File_Name, const char* File_Result, const int x)
{
    ifstream First_File(File_Name, ios::binary);
    ofstream Second_File(File_Result, ios::binary);

    int y;
    int z;
    int max = -10;
    int min = 0;
    while (First_File.read((char*)&y, sizeof(y)))
        {
            if (y < 0 && (y > max))
            {
                max =y;
            }
        }
 
    Second_File.write((char*) &max, sizeof(max));

    ifstream ifs;
    ifs.clear();//видаляємо флаги помилок та eof
    ifs.seekg(0, ios::beg);


    while (First_File.read((char*)&z, sizeof(z)))
    {
        if (z > 0 && (z < min))
        {
            min = z;
        }
    }

    Second_File.write((char*)&min, sizeof(min));

}

void Print(const char* File_Result)
{
    cout << "Вміст файлу: ";

    ifstream Second_File(File_Result, ios::binary);

    int y;
    while (Second_File.read((char*)&y, sizeof(y)))
        cout << y << " ";
    cout << endl;
}