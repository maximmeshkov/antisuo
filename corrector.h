#ifndef CORRECTOR_H
#define CORRECTOR_H

#include <QMainWindow>

class corrector
{
    int dtt = 0, rtt = 0;
    int refD1 = 0, refD2 = 0, refD3 = 0;
    int dD1 = 0, dD2 = 0, dD3 = 0;
    int dd1 = 0, dd2 = 0, dd3 = 0;
    float resultdD=0, resultdd=0;
    int resultDTR=0, resultRTR=0;
public:
    corrector();

    void setdtt(int dtt);
    void setrtt(int ddt);

    void setrefD1(int refD);
    void setrefD2(int refD);
    void setrefD3(int refD);

    void setdD1(int refdD);
    void setdD2(int refdD);
    void setdD3(int refdD);

    void setdd1(int refdd);
    void setdd2(int refdd);
    void setdd3(int refdd);

    int getResultdD();
    int getResultdd();
    int getResultDTR();
    int getResultRTR();

    void calculate();

};

#endif // CORRECTOR_H
