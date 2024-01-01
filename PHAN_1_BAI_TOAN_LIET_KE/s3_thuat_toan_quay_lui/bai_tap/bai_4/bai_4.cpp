/*
Với n = 5, k = 3, vẽ cây tìm kiếm quay lui của chương trình liệt kê
tổ hợp chập k của tập {1, 2, 3, ..., n}
*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void printConfig(int k, vector<int> &a, fstream &out)
{
    out << "{ ";
    for (int i = 1; i <= k - 1; i++)
    {
        out << a[i] << ", ";
    }
    out << a[k] << " }" << endl;
}

void Try(int i, int k, int n, vector<int> &a, fstream &out)
{
    for (int j = a[i-1] + 1; j <= n - k + i; j++)
    {
        a[i] = j;
        if (i == k)
        {
            printConfig(k, a, out);
        }
        else
        {
            Try(i + 1, k, n, a, out);
        }
    }
}

int main()
{
    fstream inFile("./bai_4.inp"), outFile("./bai_4.out");
    int n, k;

    inFile >> n >> k;
    inFile.close();

    vector<int> a(k + 1);

    Try(1, k, n, a, outFile);
    outFile.close();
    return 0;
}