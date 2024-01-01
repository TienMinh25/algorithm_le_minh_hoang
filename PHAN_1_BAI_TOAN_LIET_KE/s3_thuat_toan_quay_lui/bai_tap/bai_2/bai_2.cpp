// Viết chương trình liệt kê các chỉnh hợp lặp chập k của n phần tử.
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

void printConfig(vector<int>& a, fstream& out){
    out << "(";
    for (int i = 1; i < a.size() - 1; i++) {
        out << a[i] << ", ";
    }
    out << a[a.size() - 1] << ")" << endl;   
}

void Try(int i, vector<int>& a, int n, int k, fstream& out) {
    for (int j = 1; j <= n; j++) {
        a[i] = j;
        if (i == k) {
            printConfig(a, out);
        }
        else {
            Try(i+1, a, n, k, out);
        }
    }
}

int main(){
    fstream inFile("./bai_2.inp"), outFile("./bai_2.out");
    int n, k;
    
    inFile >> n >> k;
    inFile.close();

    vector<int> a(k + 1);
    Try(1, a, n, k, outFile);

    outFile.close();
    return 0;
}