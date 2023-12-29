// Dữ liệu nằm ở file liet_ke.inp chứa 2 số là n và k
/*
Trong đó: 
    - n là phần tử max trong tập S = {1, 2, 3, 4, 5, ...., n}
    - k là số phần tử mà 1 tập con nên có
*/
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void printResult(vector<int>& a, fstream& out, int k) {
    out << "{ ";
    for (int i = 1; i < k; i++) {
        out << a[i] << ", ";
    }
    out << a[k] << " }" << endl;
}

// x[i-1] + 1 <= x[i] <= n - k + i
/*
    Bài này ta xét rằng khi sinh theo thuật toán quay lui ===> xem nó là cấu hình dạng {x1, x2,..., xk}
    ở đây thì x1 < x2 < x3 < ... < xk
    Ta có nhận xét:
        - xk <= n
        - x(k-1) <= xk - 1 <= n - 1
    ====> x(i-1) + 1 <= xi <= n - k + i
*/
void Try(int i, vector<int>& a, int k, int n, fstream& out) {
    for (int j = a[i - 1] + 1; j <= n - k + i; j++) {
        a[i] = j;
        if (i == k) {
            printResult(a, out, k);
        }
        else Try(i+1, a, k, n, out);
    }
}

int main() {
    fstream inFile("./liet_ke.inp"), outFile("./liet_ke.out");
    int n, k;
    inFile >> n >> k;
    inFile.close();

    vector<int> a(k + 1);
    for (int i = 0; i < a.size(); i++) {
        a[i] = i;
    }

    Try(1, a, k, n, outFile);
    outFile.close();
    return 0;
}
