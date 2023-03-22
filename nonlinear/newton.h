#pragma once 

#include <cmath>
#include <iostream>
#include <utility>

using std::cout;
using std::pair;

template<class T>
pair<double, int> newton(T &func, double a, double b, double eps, bool flag = false){
    const double dlt = 1e-9;

    double xk = (a+b)/2;
    double x = 0;
    int i = 1;

    if(flag)
        cout<<"|"<<i<<"|: "<<xk<<"\n";

    while(fabs(xk - x) > eps){
        i++;
        x = xk; 

        double df = (func(xk + dlt) - func(xk))/dlt;

        xk = x - func(xk)/df;

        if(flag)
            cout<<"|"<<i<<"|: "<<xk<<"\n";
    }

    return pair(xk, i);

}