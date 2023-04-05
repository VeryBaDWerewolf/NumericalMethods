#pragma once

#include <cmath>
#include <map>

#include "../utils/sd.h"
#include "../utils/LU.h"


using std::map;

DoubMatrix cubic_spline(VecDoub x, VecDoub y, int n, double a, double b){

    // f = a_i + b_i(x - x_i-1)^ + c_i(x - x_i-1)^2 + d_i(x - x_i-1)^3
    DoubMatrix polynoms(n, VecDoub(4, 0)); 
    VecDoub h(n);

    for (int i = 0; i < n; i++)
        h[i] = x[i+1]-x[i];

    // a_i
    for (int i = 0; i < n; i++)
        polynoms[i][0] = y[i];
    
    // c_i
    DoubMatrix C((n+1), VecDoub(n+1));
    VecDoub T(n+1);

    C[0][0] = 1;
    C[n][n] = 1;

    for(int i = 1; i<n; i++)
        C[i][i] = 2*(h[i]+h[i-1]);
    for(int i = 0; i<(n-1); i++)
        C[i+1][i] = h[i];
    for(int i = 1; i<n; i++) 
        C[i][i+1] = h[i];

    T[0] = 0;
    T[n] = 0; 

    for(int i = 1; i<n; i++)
        T[i] = 3 * (((y[i+1]-y[i])/h[i]) - ((y[i]-y[i-1])/h[i-1]));

    VecDoub C1 = solveLU(C, T);

    for (int i = 1; i < n; i++)
        polynoms[i][2] = C1[i];
    

    // d_i
    for(int i = 0; i<n; i++)
        polynoms[i][3] = (C1[i+1] - C1[i])/(3*h[i]);

    // b_i

    for(int i = 0; i<n; i++)
        polynoms[i][1] = ((y[i+1]-y[i])/h[i]) - (h[i]/3)*(C1[i+1] +  2*C1[i]);
   

    return polynoms;
}