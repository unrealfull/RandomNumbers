#include <iostream>
#include <iomanip>
#include "nr.h"
using namespace std;

// Driver for routine ran4

int main(void)
{
        // choose sample size
        int sampleSize = 5;
        //sampleSize = 10;
        //sampleSize = 100;
        //sampleSize = 10000;

        int i;
        int idum[4]={-1,99,-99,99};
        Vec_DP random(sampleSize);

        cout << fixed << setprecision(6);
        for (i=0;i< sampleSize;i++) random[i]=NR::ran4(idum[i % 4]);
        cout << endl << "ran4 gets values: ";
        for (i=0;i< sampleSize;i++) cout << setw(15) << random[i];
        cout << endl;

        // File pointer
        std::ofstream outFile;

        // creates a new file
        string fileName = "ran4_" + to_string(sampleSize) + ".csv";
        outFile.open(fileName, std::ios::out);

        // save numbers in file
        for (i = 0; i < sampleSize; i++) {
            outFile << random[i] << endl;
        }

        // Close the file
        outFile.close();
        return 0;
}
