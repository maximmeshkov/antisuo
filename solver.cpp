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


    std::cout << "distCmdr=" << distCmdr << std::endl;
    std::cout << "dx=" << dx << "\t dy=" << dy << std::endl;
    std::cout << "xTarget=" << xTarget << "\t yTarget=" << yTarget << std::endl;
    //---------------------------------------------------------------------------//
    int dxt = xTarget - xOP;
    int dyt = yTarget - yOP;


    std::cout << "dxt=" << dxt << "\t dyt=" << dyt << std::endl;

    int rumbtt = (int) (std::atan2(abs(dyt),abs(dxt)) * 954.92);


    std::cout << "rumbtt=" << rumbtt <<" \t std::atan(dyt/dxt) =" << std::atan2(dyt,dxt)  << std::endl;

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

    std::cout << "rtt=" << rtt << "\t atan=" << std::atan2(dyt , dxt) << std::endl;
    std::cout << "dtt=" << dtt << std::endl<< std::endl;
}

void solver::solve_degree()
{
    int xTarget = 0, yTarget = 0;
    int dx = 0, dy = 0;
    if (alphaTarget < 0)
        alphaTarget += 360;
    if ((alphaTarget >= 0) && (alphaTarget < 90)) {
        dx = (int) distCmdr * std::cos((alphaTarget) *3.1416 / 180);
        dy = (int) distCmdr * std::sin((alphaTarget) *3.1416 / 180);
    } else if ((alphaTarget >= 90) && (alphaTarget < 180)) {
        dx = (int) -distCmdr * std::cos((180 - alphaTarget) * 3.1416 / 180);
        dy = (int) distCmdr * std::sin((180 - alphaTarget) * 3.1416 / 180);
    } else if ((alphaTarget >= 180) && (alphaTarget < 270)) {
        dx = (int) -distCmdr * std::cos((alphaTarget - 180) * 3.1416 / 180);
        dy = (int) -distCmdr * std::sin((alphaTarget - 180) * 3.1416 / 180);
    } else if ((alphaTarget >= 270) && (alphaTarget < 360)) {
        dx = (int) distCmdr * std::cos((360 - alphaTarget) * 3.1416 / 180);
        dy = (int) -distCmdr * std::sin((360 - alphaTarget) * 3.1416 / 180);
    } else {
    }
    xTarget = xKNP + dx;
    yTarget = yKNP + dy;


    std::cout << "distCmdr=" << distCmdr << std::endl;
    std::cout << "dx=" << dx << "\t dy=" << dy << std::endl;
    std::cout << "xTarget=" << xTarget << "\t yTarget=" << yTarget << std::endl;
    //---------------------------------------------------------------------------//
    int dxt = xTarget - xOP;
    int dyt = yTarget - yOP;


    std::cout << "dxt=" << dxt << "\t dyt=" << dyt << std::endl;

    int rumbtt = (int) (std::atan2(dyt,dxt) * 180 / 3.1416);


    std::cout << "rumbtt=" << rumbtt <<" \t std::atan(dyt/dxt) =" << std::atan2(dyt,dxt)  << std::endl;

    if ((dxt >= 0) && (dyt >= 0))
        rtt = rumbtt;
    else if ((dxt <= 0) && (dyt >= 0))
        rtt = 180 - rumbtt;
    else if ((dxt <= 0) && (dyt <= 0))
        rtt = rumbtt + 180;
    else if ((dxt >= 0) && (dyt <= 0))
        rtt = 360 - rumbtt;
    else {   }

    dtt = std::sqrt(dxt*dxt + dyt*dyt);

    std::cout << "rtt=" << rtt << "\t atan=" << std::atan2(dyt , dxt) << std::endl;
    std::cout << "dtt=" << dtt << std::endl<< std::endl;

}
