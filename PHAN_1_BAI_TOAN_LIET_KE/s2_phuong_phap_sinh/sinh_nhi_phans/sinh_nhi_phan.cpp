#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    string line;
    int number;
    fstream outfile;
    fstream infile;
    infile.open("bstr.inp", ios::in);
    outfile.open("bstr.out", ios::out);

    while (getline(infile, line)) {
        number = stoi(line);
    }
    infile.close();
    vector<int> array(number, 0);
    int i = number;
    do {
        i = number - 1;
        for (int j = 0; j < array.size(); j++) {
            outfile << array[j] << " ";
        }
        outfile << "\n";
        while (i >= 0 && array[i] != 0) {
            i--;
        }
        array[i] = 1;
        for (int j = i + 1; j < array.size(); j++) {
            array[j] = 0;
        }
    }
    while (i >= 0);
    outfile.close();
    return 0;
}