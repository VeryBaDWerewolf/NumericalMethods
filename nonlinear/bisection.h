#pragma once

#include<iostream>
#include<cmath>
#include<utility>


using std::pair;
using std::cout;


template <typename T>
pair<double, int> bisection(T &func, const double a, const double b, double eps ,bool flag = false){
    //Returns a root of equation with the initial approximation (a+b)/2 .
    //The criteria of stopping is х_k-1 - x_k < eps

    double ak = a; double bk = b; 
    double xk = (a + b) / 2;
    double x = 0;

    int i = 1;

    if(flag)
        cout<<"|"<<i<<"|: "<<xk<<"\n";


    if(func(a) == 0 || func(b) == 0)
        xk = func(a) == 0 ? a : b;

    while(fabs(xk - x)> eps){
        auto f = func(xk);

        if (func(ak) * f <= 0)
            bk = xk;
        if (func(bk) * f < 0)
            ak = xk;

        x = xk; 
        i++; 
        xk = (ak+bk)/2;

        if(flag)
           cout<<"|"<<i<<"|: "<<xk<<"\n";
    }

    return pair(xk, i);

}