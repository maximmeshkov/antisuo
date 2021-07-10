#include "solver.h"
#include <QTextStream>
#include <cmath>
#include <iostream>

solver::solver()
{

}

void solver::setxKNP(int i)
{
    xKNP = i;
}
void solver::setxOP(int i)
{
    xOP = i;
}
void solver::setyKNP(int i)
{
    yKNP = i;
}
void solver::setyOP(int i)
{
    yOP = i;
}
void solver::sethKNP(int i)
{
    hKNP = i;
}
void solver::sethOP(int i)
{
    hOP = i;
}
void solver::setalphaOH(int i)
{
    alphaOH = i;
}
void solver::setaalphaTarget(int i)
{
    alphaTarget = i;
}
void solver::setdistCmdr(int i)
{
    distCmdr = i;
}

void solver::setepsTarget(int i)
{
    epsTarget=i;
}


float solver::getShy()
{
    return shy;
}
float solver::getKy()
{
    return ky;
}
float solver::getPS()
{
    return ps;
}
int solver::getDTT()
{
    return dtt;
}
int solver::getRTT()
{
    return rtt;
}
int solver::getLVL()
{
    return lvl;
}

void solver::solve()
{
    int xTarget = 0, yTarget = 0;
    int dx = 0, dy = 0;
    if (alphaTarget < 0)
        alphaTarget += 6000;
    if ((alphaTarget >= 0000) && (alphaTarget < 1500)) {
        dx = (int) distCmdr * std::cos((alphaTarget) *1.0472/1000);
        dy = (int) distCmdr * std::sin((alphaTarget) *1.0472/1000);
    } else if ((alphaTarget >= 1500) && (alphaTarget < 3000)) {
        dx = (int) -distCmdr * std::cos((3000 - alphaTarget) * 1.0472/1000);
        dy = (int) distCmdr * std::sin((3000 - alphaTarget) * 1.0472/1000);
    } else if ((alphaTarget >= 3000) && (alphaTarget < 4500)) {
        dx = (int) -distCmdr * std::cos((alphaTarget - 3000) * 1.0472/1000);
        dy = (int) -distCmdr * std::sin((alphaTarget - 3000) * 1.0472/1000);
    } else if ((alphaTarget >= 4500) && (alphaTarget < 6000)) {
        dx = (int) distCmdr * std::cos((6000 - alphaTarget) * 1.0472/1000);
        dy = (int) -distCmdr * std::sin((6000 - alphaTarget) * 1.0472/1000);
    } else {
    }
    xTarget = xKNP + dx;
    yTarget = yKNP + dy;

    std::cout << "xTarget=" << xTarget << "\t yTarget=" << yTarget << std::endl;
    //---------------------------------------------------------------------------//
    int dxt = xTarget - xOP;
    int dyt = yTarget - yOP;

    int rumbtt = round(std::atan2(abs(dyt),abs(dxt)) * 954.92); //int rumbtt = (int) (std::atan2(abs(dyt),abs(dxt)) * 954.92);

    if ((dxt >= 0) && (dyt >= 0))
        rtt = rumbtt;
    else if ((dxt <= 0) && (dyt >= 0))
        rtt = 3000 - rumbtt;
    else if ((dxt <= 0) && (dyt <= 0))
        rtt = rumbtt + 3000;
    else if ((dxt >= 0) && (dyt <= 0))
        rtt = 6000 - rumbtt;
    else {   }

    rtt=rtt-alphaOH;
    dtt =std::sqrt(dxt*dxt + dyt*dyt);

   //------------------------------------------------------------------------------//

    int hTarget=hKNP+(epsTarget*distCmdr/1000);
    std::cout << "hTarget=" << hTarget << std::endl;

    if (dtt!=0)
    {
        lvl=3000+((hTarget-hOP)/(0.001*dtt));
        ky=round(distCmdr*100/ (float) dtt)/100; //round(x*100)/100 для выводя сотых долей
        ps=abs(alphaTarget-alphaOH-rtt);
        shy=round(ps*100/(0.01*dtt))/100;
    }
}


