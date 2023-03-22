#pragma once

#include<cmath>
#include<iostream>
#include<utility>

using std::cout;
using std::pair;

template<class T>
pair<double, int> iteration(T &func, double a, double b, double eps, double alpha = 0.1, bool flag = false){
    
    double xk = (a+b)/2;
    double x = 0;
    int i = 1;

    if(flag)
        cout<<"|"<<i<<"|: "<<xk<<"\n";

    while(fabs(xk - x) > eps){
        i++;
        x = xk;

        xk = x - alpha*func(xk);
    }

        return pair(xk, i);

}