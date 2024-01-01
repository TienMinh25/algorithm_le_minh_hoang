/*
Sửa lại thủ tục in kết quả (Print Result) trong bài xếp hậu để có thể vẽ hình bàn cờ và các cách đặt
hậu ra màn hình.
*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void printConfig(vector<int> &x, fstream &out)
{
    int n = x.size();
    for (int i = 1; i <= n - 1; i++)
    {
        out << "[";
        int j = 1;
        while (j != x[i])
        {
            out << " ,";
            j++;
        }
        out << "h";
        if (j == n)
        {
            out << "]";
        }
        else
        {
            j++;
            while (j != n)
            {
                j++;
                out << " ,";
            }
            out << " ]";
        }
        out << endl;
    }
}

void Try(int i, vector<bool> &cot, vector<bool> &d1, vector<bool> &d2, vector<int> &x, int n, fstream &out)
{
    for (int j = 1; j <= n; j++)
    {
        if (cot[j] && d1[i - j + n] && d2[i + j - 1])
        {
            x[i] = j;
            if (i == n)
            {
                printConfig(x, out);
                out << endl
                    << "-------------------------------------------------------------" << endl;
            }
            else
            {
                cot[j] = false;
                d1[i - j + n] = false;
                d2[i + j - 1] = false;
                Try(i + 1, cot, d1, d2, x, n, out);
                cot[j] = true;
                d1[i - j + n] = true;
                d2[i + j - 1] = true;
            }
        }
    }
}

int main()
{
    fstream inFile("./queens.inp"), outFile("./queens.out");
    // d1: i - j + n
    // d2: i + j - 1
    // d1 la duong cheo chinh, d2 la duong cheo phu
    int n;
    inFile >> n;
    inFile.close();

    vector<bool> cot(n + 1, true), d1(2 * n, true), d2(2 * n, true);
    vector<int> x(n + 1);

    Try(1, cot, d1, d2, x, n, outFile);

    outFile.close();
    return 0;
}