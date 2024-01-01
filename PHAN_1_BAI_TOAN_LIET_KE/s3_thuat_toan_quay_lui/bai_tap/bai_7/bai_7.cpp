/*
Một dãy (x1, x2, ..., xn) gọi là một hoán vị hoàn toàn của tập {1, 2, 3,..., n} nếu nó là một hoán vị
và thoả mãn xi != i với mọi i: 1 <= i <= n. Hãy viết chương trình liệt kê tất cả các hoán vị hoàn toàn
của tập trên (n nhập từ bàn phím)
- Do mình muốn đưa kết quả lên git và thuận tiện cho việc check lại kết quả sau này thì mình sẽ đọc dữ liệu từ
file `bai_7.inp` và ghi file ra `bai_7.out`
*/

#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void printCongfig(int n, vector<int> &a, fstream &out)
{
    out << "{";
    for (int i = 1; i <= n - 1; i++)
    {
        out << a[i] << ", ";
    }
    out << a[n] << "}" << endl;
}

void Try(int i, int n, vector<bool> &danhDau, vector<int> &a, fstream &out)
{
    for (int j = 1; j <= n; j++)
    {
        if (danhDau[j] && i != j)
        {
            a[i] = j;
            if (i == n)
            {
                printCongfig(n, a, out);
            }
            else
            {
                danhDau[j] = false;
                Try(i + 1, n, danhDau, a, out);
                danhDau[j] = true;
            }
        }
    }
}

int main()
{
    fstream inFile("./bai_7.inp"), outFile("./bai_7.out");
    int n;
    inFile >> n;
    inFile.close();

    vector<bool> danhDau(n + 1, true);
    vector<int> a(n + 1);
    a[0] = 0;

    Try(1, n, danhDau, a, outFile);
    outFile.close();

    return 0;
}