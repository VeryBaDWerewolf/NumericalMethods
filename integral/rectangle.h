#pragma once

#include "../utils/sd.h"
#include <cmath>

template<class T>
pair<double, int> rectangle_rule(T &func, double a, double b, double eps, char type = 'm'){
    int n = 1;
    double dx = 0;
    double d2x = 0;

    double dltX = 0;
    double start = 0;


    double ans = 0;
    double new_ans = 0;

    while (dltX > eps || n == 1){
        dx  = (b-a)/n;
        d2x = (b-a)/(2*n);

        ans = 0;
        new_ans = 0;
        switch (type){
            case 'l':
                start = a + 0*dx;
                break;
            case 'r':
                start = a + 1*dx;
                break;
            default:
                start = a + 0.5*dx;
                break;
            }

        for(int i = 0; i<n; i++)
            ans+= func(start + i*dx);

        for(int i = 0; i<(2*n); i++)
            new_ans+= func(start + i*d2x);

        n*=2;
        dltX = fabs(d2x*new_ans-dx*ans);
    }
        return pair(dx*ans, n);
    

}