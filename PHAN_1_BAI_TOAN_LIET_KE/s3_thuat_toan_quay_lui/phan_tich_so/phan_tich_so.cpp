/*
Bài toán phân tích số: Cho một số nguyên dương n <= 30, hãy tìm tất cả các cách phân tích số n
thành tổng của các số nguyên dương, các cách phân tích là hoán vị của nhau chỉ tính là 1 cách.
*/
#include<vector>
#include<algorithm>
#include<iostream>
#include<fstream>

using namespace std;

void printResult(vector<int>& a, int i, int n, fstream& out){ 
    out << n << " = ";
    for (int j = 1; j < i; j++) {
        out << a[j] << " + ";
    }
    out << a[i] << endl;
}

void Try(int i, vector<int>& a, vector<int>& t, int n, fstream& out) {
    for (int j = a[i-1]; j <= (n - t[i-1])/2; j++){
        a[i] = j;
        t[i] = t[i-1] + j;
        Try(i + 1, a, t, n, out);
    }
    a[i] = n - t[i-1];
    printResult(a, i, n, out);
}

int main() {
    fstream inFile("./analyse.inp"), outFile("./analyse.out");
    int n;
    
    inFile >> n;
    inFile.close();

    vector<int> a(n + 1), t(n+1);
    a[0] = 1;
    t[0] = 0;

    Try(1, a, t, n, outFile);
    outFile.close();

    return 0;
}