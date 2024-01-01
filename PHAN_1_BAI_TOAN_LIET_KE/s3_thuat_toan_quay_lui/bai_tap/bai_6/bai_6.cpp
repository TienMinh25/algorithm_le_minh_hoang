/*
Liệt kê tất cả các tập con của tập S gồm n số nguyên {S1, S2, S3,..., Sn} nhập vào từ bàn phím
Chỉ liệt kê các tập con có max - min <= T (T cho trước)
file bai_6.inp chua T
ghi ket qua ra file bai_6.out

Solution:
    Dùng thuật toán quay lui cho từng kích thước của 1 tập con S
    chạy từ 1 ---> n; với k thay đổi để dùng Try
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void printConfig(int k, int t, vector<int> &a, vector<int> &b, fstream &out)
{
    if (a[b[k]] - a[b[1]] <= t)
    {
        out << "( ";
        for (int i = 1; i <= k - 1; i++)
        {
            out << a[b[i]] << ", ";
        }
        out << a[b[k]] << " )" << endl;
    }
}

void Try(int i, int n, int k, int t, vector<int> &a, vector<int> &b, fstream &out)
{
    for (int j = b[i - 1] + 1; j <= n - k + i; j++)
    {
        b[i] = j;
        if (i == k)
            printConfig(k, t, a, b, out);
        else
            Try(i + 1, n, k, t, a, b, out);
    }
}

int main()
{
    fstream inFile("./bai_6.inp"), outFile("./bai_6.out");
    int t, n;
    inFile >> t;
    inFile.close();
    cout << "Mời bạn nhập vào số phần tử của tập S: " << endl;
    cin >> n;

    vector<int> a(n + 1);
    vector<int> b(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap a[" << i << "]: ";
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    for (int j = 1; j <= n; j++)
    {
        Try(1, n, j, t, a, b, outFile);
    }

    outFile.close();
    return 0;
}
