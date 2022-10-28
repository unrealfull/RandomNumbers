#include <iostream>
#include <iomanip>
#include <cmath>
#include "nr.h"
using namespace std;

// Driver for routines ran0, ran1, ran2, ran3

DP fnc(const DP x1, const DP x2, const DP x3, const DP x4)
{
        return sqrt(x1*x1+x2*x2+x3*x3+x4*x4);
}

void integ(DP func(int &))
{
        const unsigned long twotoj[16]={0x1L,0x2L,0x4L,0x8L,0x10L,
          0x20L,0x40L,0x80L,0x100L,0x200L,0x400L,0x800L,0x1000L,
          0x2000L,0x4000L,0x8000L};
        const DP PI=3.141592653589793238;
        int i,idum=(-1),j,jpower,k;
        DP x1,x2,x3,x4;
        Vec_INT iy(3);
        Vec_DP yprob(3);

        // Calculates pi statistically using volume of unit n-sphere
        for (i=0;i<3;i++) iy[i]=0;
        cout << "volume of unit n-sphere, n = 2, 3, 4" << endl;
        cout << "# points      pi       (4/3)*pi   (1/2)*pi^2";
        cout << endl << endl;
        cout << fixed << setprecision(6);
        for (j=0;j<15;j++) {
          for (k=twotoj[j];k>=0;k--) {
            x1=func(idum);
            x2=func(idum);
            x3=func(idum);
            x4=func(idum);
            if (fnc(x1,x2,0.0,0.0) < 1.0) ++iy[0];
            if (fnc(x1,x2,x3,0.0) < 1.0) ++iy[1];
            if (fnc(x1,x2,x3,x4) < 1.0) ++iy[2];
          }
          jpower=twotoj[j+1];
          for (i=0;i<3;i++)
            yprob[i]=DP(twotoj[i+2])*iy[i]/jpower;
          for (i=0;i<3;i++) yprob[i]=DP(twotoj[i+2])*iy[i]/jpower;
          cout << setw(6) << jpower << setw(12) << yprob[0];
          cout << setw(12) << yprob[1] << setw(12) << yprob[2] << endl;
        }
        cout << endl << "actual" << setw(12) << PI;
        cout << setw(12) << 4.0*PI/3.0 << setw(12) << 0.5*PI*PI << endl;
        cin.get();
}

void getAndSaveNumbers(string ran, int sampleSize) {

    int idum = -1;

    // File pointer
    std::ofstream outFile;

    // creates a new file
    outFile.open(ran + "_" + to_string(sampleSize) + ".csv", std::ios::out);

    if (ran == "ran0")
    {
        // save points in file
        for (int i = 0; i < sampleSize; ++i)
            outFile << NR::ran0(idum) << endl;
    }
    else if (ran == "ran1")
    {
        // save points in file
        for (int i = 0; i < sampleSize; ++i)
            outFile << NR::ran1(idum) << endl;
    }
    else if (ran == "ran2")
    {
        // save points in file
        for (int i = 0; i < sampleSize; ++i)
            outFile << NR::ran2(idum) << endl;
    }
    else if (ran == "ran3")
    {
        // save points in file
        for (int i = 0; i < sampleSize; ++i)
            outFile << NR::ran3(idum) << endl;
    }

    // Close the file
    outFile.close();
}

int main(void)
{

    // ran0:
    getAndSaveNumbers("ran0", 5);
    getAndSaveNumbers("ran0", 10);
    getAndSaveNumbers("ran0", 100);
    getAndSaveNumbers("ran0", 10000);

    // ran1:
    getAndSaveNumbers("ran1", 5);
    getAndSaveNumbers("ran1", 10);
    getAndSaveNumbers("ran1", 100);
    getAndSaveNumbers("ran1", 10000);

    // ran2:
    getAndSaveNumbers("ran2", 5);
    getAndSaveNumbers("ran2", 10);
    getAndSaveNumbers("ran2", 100);
    getAndSaveNumbers("ran2", 10000);

    // ran3:
    getAndSaveNumbers("ran3", 5);
    getAndSaveNumbers("ran3", 10);
    getAndSaveNumbers("ran3", 100);
    getAndSaveNumbers("ran3", 10000);

    return 0;
}
