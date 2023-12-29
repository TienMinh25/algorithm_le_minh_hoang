#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;

void printConfig(vector<int>& a, fstream& out) {
    for (int i = 0; i < a.size(); i++) {
        out << a[i];
    }
    out << endl;
}

void Try(int i, vector<int>& a, fstream& out) {
    for(int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == a.size() - 1) {
            printConfig(a, out);
        }
        else Try(i+1, a, out);
    }
}

int main(){
    fstream inFile("./liet_ke.inp"), outFile("./liet_ke.out");
    int n;

    inFile >> n;
    inFile.close();
    vector<int> a(n);

    Try(0, a, outFile);

    outFile.close();
    return 0;
}