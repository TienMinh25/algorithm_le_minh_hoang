#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

void printConfig(vector<int>& x, fstream& out){
    for (int i = 1; i < x.size() - 1; i++){
        out << "( " << i << ", " << x[i] << " ); ";
    }
    out << "( " << x.size() - 1 << ", " << x[x.size() - 1] << " );" << endl;
}

void Try(int i, vector<bool>& cot, vector<bool>& d1, vector<bool>& d2, vector<int>& x, int n, fstream& outFile){
    // i la hang
    // j la cot de thu
    for (int j = 1; j <= n; j++) {
        if (cot[j] && d1[i-j+n] && d2[i+j-1]) {
            x[i] = j;
            if (i == n) {
                printConfig(x, outFile);
            }
            else {
                cot[j] = false; d1[i-j+n] = false; d2[i+j-1] = false;
                Try(i+1, cot, d1, d2, x, n, outFile);
                cot[j] = true; d1[i-j+n] = true; d2[i+j-1] = true;
            }
        }
    }
}

int main(){
    fstream inFile("./queens.inp"), outFile("./queens.out");
    int n;
    inFile >> n;
    inFile.close();

    // d1 la duong cheo chinh, d2 la duong cheo phu
    vector<bool> cot(n + 1, true), d1(2*n, true), d2(2*n, true);
    vector<int> x(n+1);

    Try(1, cot, d1, d2, x, n, outFile);

    outFile.close();
    return 0;
}