#include "corrector.h"
#include <iostream>

corrector::corrector() {}

void corrector::setdtt(int dtt)
{
    this->dtt = dtt;
}
void corrector::setrtt(int rtt)
{
    this->rtt = rtt;
}

void corrector::setrefD1(int refD)
{
    refD1 = refD*1000;
}
void corrector::setrefD2(int refD)
{
    refD2 = refD*1000;
}
void corrector::setrefD3(int refD)
{
    refD3 = refD*1000;
}

void corrector::setdD1(int dD)
{
    dD1 = dD;
}
void corrector::setdD2(int dD)
{
    dD2 = dD;
}
void corrector::setdD3(int dD)
{
    dD3 = dD;
}

void corrector::setdd1(int dd)
{
    dd1 = dd;
}
void corrector::setdd2(int dd)
{
    dd2 = dd;
}
void corrector::setdd3(int dd)
{
    dd3 = dd;
}

int corrector::getResultdD()
{
    return (int) resultdD;
}
int corrector::getResultdd()
{
    return (int) resultdd;
}
int corrector::getResultDTR()
{
    return resultDTR;
}
int corrector::getResultRTR()
{
    return resultRTR;
}

void corrector::calculate()
{
    int D1 = refD1 - dD1;
    int D2 = refD2 - dD2;
    int D3 = refD3 - dD3;
     std::cout << "D1=" << D1 <<"\t D2=" << D2 << "\t D3=" << D3 << std::endl;
    if ((dtt <= D2)&&((D2-D1)!=0)) {
        resultdD =  ((float)(dtt - D1) / (D2 - D1)) * (dD2 - dD1) + dD1;
        resultdd =  ((float)(dtt - D1) / (D2 - D1)) * (dd2 - dd1) + dd1;
        std::cout << "resultdD1=" << resultdD << "\t resultdd1=" << resultdd << std::endl;
    } else if((D3-D2)!=0) {
        resultdD = ((float)(dtt - D2) / (D3 - D2)) * (dD3 - dD2) + dD2;
        resultdd = ((float)(dtt - D2) / (D3 - D2)) * (dd3 - dd2) + dd2;
        std::cout << "resultdD2=" << resultdD << "\t resultdd2=" << resultdd << std::endl;
    }
    resultDTR = dtt + resultdD;
    resultRTR = rtt + resultdd;
    std::cout << " resultDTR=" <<  resultDTR << "\t  resultRTR=" <<  resultRTR << std::endl;
}
