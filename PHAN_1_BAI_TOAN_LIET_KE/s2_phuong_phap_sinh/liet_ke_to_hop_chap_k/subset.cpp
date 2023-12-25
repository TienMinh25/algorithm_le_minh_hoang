#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

int main(){
    fstream inFile, outFile;
    inFile.open("subset.inp", ios::in);

    int num1, num2;
    inFile >> num1 >> num2;
    inFile.close();
    outFile.open("subset.out", ios::out);
    vector<int> array(num2);
    for (int i = 0; i < num2; i++) {
        array[i] = i + 1;
    }

    int i = num2 - 1;
    do {
        i = num2 - 1;
        outFile << "{ ";
        for (int j = 0; j < num2; j++) {
            outFile << array[j] << " ";
        }
        outFile << "}" << endl;
        while ( i >= 0 && array[i] == num1 - num2 + i + 1) i--;
        array[i] = array[i] + 1;
        for (int j = i + 1; j < num2; j++) {
            array[j] = array[j - 1] + 1;
        }
    }
    while (i >= 0);
    outFile.close();
    return 0;
}