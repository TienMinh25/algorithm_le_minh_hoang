// Liệt kê các chỉnh hợp không lặp chập k của tập S = {1, 2, 3, 4, 5, ..., n}
// file inp chứa dữ liệu là n và k
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void printConfig(vector<int>& a, int k, fstream& out) {
    out << "{ ";
    for (int i = 1; i < k; i++) {
        out << a[i] << ", ";
    }
    out << a[k] << " }" << endl;
}   

void Try(vector<int>& a, int i, int k, int n, vector<bool>& danhDau, fstream& out) {
    for (int j = 1; j <= n; j++) {
        if (danhDau[j]) {
            a[i] = j;
            if (i == k) {
                printConfig(a, k, out);
            }
            else {
                danhDau[j] = false;
                Try(a, i+1, k, n, danhDau, out);
                danhDau[j] = true;
            }
        }
    }
}

int main(){
    fstream inFile("./arrange.inp"), outFile("./arrange.out");
    int n, k;
    
    inFile >> n >> k;
    inFile.close();

    vector<bool> danhDau(n + 1, true);
    vector<int> a(k + 1);

    Try(a, 1, k, n, danhDau, outFile);
    outFile.close();
    return 0;
}