#pragma once

#include "../utils/sd.h"
#include "rectangle.h"
#include "cmath"

template<class T>
pair<double, int> trapezoid_rule(T &func, double a, double b, double eps){
    int n = 1;
    double dx = 1.0 * (b-a)*n;
    double ans = 0.5*(func(a)+func(b));

    
    for(int i = 1; i<n; i++)
        ans+= func(a + i*dx);
    ans*=dx;

    double dltX = 0;
    double start = 0;
    double new_ans = 0;

    while (dltX > eps || n == 1){
        new_ans = ans;
        ans = 0.5*(ans + rectangle_rule(func, a, b, eps).first);

        n *= 2;
        dltX = fabs(ans-new_ans);
    }
    return pair(ans, n);
    





}