#pragma once

#include "../utils/sd.h"
#include "rectangle.h"

#include <cmath>

template<class T>
pair<double, int> simpson_rule(T &f, double a, double b, double eps){
    int n = 1;
   double dx = 0;
    double ans = 0;
    double new_ans = 0;
    double dltX = 0;
    double d2x = 0;

    while (dltX > eps || n == 1){
        ans = new_ans = 0;
        dx = (b-a)/n;
        d2x = (b-a)/(2*n);
    for(int i = 0; i < n; i++) {
        double x1 = a + i*dx;
        double x2 = a + (i+1)*dx;
        ans += (x2-x1)/6.0*(f(x1) + 4.0*f(0.5*(x1+x2)) + f(x2));
    }
    for(int i = 0; i < 2*n; i++) {
        double x1 = a + i*d2x;
        double x2 = a + (i+1)*d2x;
        new_ans += (x2-x1)/6.0*(f(x1) + 4.0*f(0.5*(x1+x2)) + f(x2));
    }
        n++;
        dltX = fabs(new_ans - ans);
       
    }

    return pair(ans, n);
    
}