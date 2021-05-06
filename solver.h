#ifndef SOLVER_H
#define SOLVER_H

#include <QMainWindow>

class solver
{
    int xKNP = 0, xOP = 0, yKNP = 0, yOP = 0, hKNP = 0, hOP = 0, alphaOH = 1;
    int alphaTarget = 0, distCmdr = 0;
    int epsTarget=0;

    int dtt=0, rtt=0, lvl=3000;
    float shy=0, ky=0, ps=0;
public:
    solver();
    void setxKNP(int xKNP);
    void setxOP(int xOP);
    void setyKNP(int yKNP);
    void setyOP(int yOP);
    void sethKNP(int hKNP);
    void sethOP(int hOP);
    void setalphaOH(int alphaOH);
    void setaalphaTarget(int alphaTarget);
    void setdistCmdr(int distCmdr);
    void setepsTarget(int epsTarget);




    int getDTT();
    int getRTT();
    int getLVL();

    float getShy();
    float getKy();
    float getPS();

    void solve();

private:
  //  void solve();


};

#endif // SOLVER_H
