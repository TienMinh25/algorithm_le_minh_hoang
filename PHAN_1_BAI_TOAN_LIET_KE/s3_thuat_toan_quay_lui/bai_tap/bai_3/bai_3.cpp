/*
Cho 2 số nguyên dương l, n. Hãy liệt kê các xâu nhị phân độ dài n sao cho có
bất kỳ 2 xâu con nào độ dài l liên tiếp nhau đều khác nhau.

Solution:
Dùng thuật toán quay lui. Ở mỗi bước chọn thử phần tử vào xâu X và kiểm tra xem đoạn hiện thời
(bắt đầu từ vị trí i-l+1 và có độ dài l) với đoạn liền kề trước đó (bắt đầu từ vị trí i-2*l+1 và có độ dài l)
xem có bằng nhau không. Nếu không thì ta tiếp tục quay lui chọn các phần tử cho đến khi đã chọn được n phần tử thì
tiến hành in ra.

Nhị phân độ dài dài 6, l = 2;
(khi xét đến phần tử thứ i thì ta cần phải kiểm tra dãy vừa làm ra (có độ dài l) bắt đầu ở đâu: i - l + 1, lúc này coi i
là vị trí cuối, i - l là vị trí cuối của dãy trước đó liền kề với dãy vừa làm ra).
Vị trí đầu của dãy trước đó liền kề: i - 2*l + 1

==> giá trị mà mỗi vị trí có thể thử sai là: 0 và 1
==> để nhằm xây dựng cấu hình cuối thoả mãn bài toán ==> vị trí so khớp phải có i - 2*l + 1 >= 1
    i - l + 1 >= l

0   1   2   3   4   5   6

    1   1   1   1   0   1
    1   1   1   1
        1   1   1   0
            1   1   0   1
*/
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void printConfig(vector<int> &a, fstream &out)
{
    for (int i = 1; i < a.size(); i++)
    {
        out << a[i];
    }
    out << endl;
}

// i chi xet den con gan cuoi cung ===> n - 2*l + 1
bool check(vector<int>& a, int n, int l) {
    bool check;
    for (int i = 1; i <= n - 2*l + 1; i++){
        check = false;
        vector<int> b(a.begin() + i, a.begin() + i + l);
        vector<int> c(a.begin() + i + l, a.begin() + i + 2*l);
        for (int k = 0; k < b.size(); k++) {
            if (b[k] != c[k]){
                check = true;
                break;
            }
        }
        if (!check) {
            return false;
        }
    }
    return true;
}

void Try(int i, int n, int l, vector<int> &a, fstream &out)
{
    for (int j = 0; j <= 1; j++)
    {
        a[i] = j;
        if (i == n) {
            if (check(a, n, l)) {
                printConfig(a, out);
            }
        }
        else {
            Try(i + 1, n, l, a, out);
        }
    }
}

int main()
{
    fstream inFile("./bai_3.inp"), outFile("./bai_3.out");
    int n, l;

    inFile >> n >> l;
    inFile.close();

    vector<int> a(n + 1);

    Try(1, n, l, a, outFile);
    outFile.close();
    return 0;
}