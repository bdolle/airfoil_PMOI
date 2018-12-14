#include <iostream>
#include <math.h>
using namespace std;

double topfunc(double);
double botfunc(double);

int main() {

    double dx;
    double c;
    double steps;
    double znew=0.0;
    double zold=0.0;
    double xnew=0.0;
    double xold=0.0;
    double delta=0.0;
    double area=0.0;
    double zbar;
    double I;


// Asking user to input conditions
    cout << "Please input the chord";
    cin >> c;
    cout << "Please how many steps";
    cin >> steps;
    dx=c/steps;


    // first round of integration, calculating area.
    for(int i=0; i<steps; i++){
        xnew=xold+dx;
        delta=(topfunc(xnew)-botfunc(xnew))*dx;
        xold=xnew;
        zold=znew;
        znew=zold+delta;
    }
    area = znew;
    cout << "The area is " << area << endl;

    // resetting the values for second round of integration
    xnew=0.0;
    xold=0.0;
    znew=0.0;
    zold=0.0;
    delta=0.0;
    // second round of integration, calculating zbar.
    for(int i=0; i<steps; i++){
        xnew=xold+dx;
        delta=(pow(topfunc(xnew),2)-pow(botfunc(xnew),2))*dx;
        xold=xnew;
        zold=znew;
        znew=zold+delta;
    }
    zbar=(1.0/(2.0*area))*znew;
    cout << "Z-bar is " << zbar << endl;


    // resetting the values for third round of integration
    xnew=0.0;
    xold=0.0;
    znew=0.0;
    zold=0.0;
    delta=0.0;
    // third round of integration calculating I.
    for(int i=0; i<steps; i++){
        xnew=xold+dx;
        delta=(pow(topfunc(xnew)-zbar,3)-pow(botfunc(xnew)-zbar,3))*dx;
        xold=xnew;
        zold=znew;
        znew=zold+delta;
    }
    I=(1.0/3.0)*znew;
    cout << "The polar moment of inertia of the airfoil is" << I << endl;

    return 0;
}

double topfunc(double x){
    return pow((x/5),2)-pow((x/3),5);
};

double botfunc(double x){
    return pow((x/2),2)-1;
};