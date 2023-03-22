#pragma once
#include "../utils/sd.h"
#include "../utils/norm.h"

template <class T>
pair<VecDoub, int> siteration(vector<T>& funcs, VecDoub x0, double eps, bool flag = false){
    int dim = funcs.size();
    int iter_count = 1;

    VecDoub x = x0;
    VecDoub xk = x0;

    VecDoub mF(dim, 0);
    VecDoub dX(dim, 0);

    while (norm2(x, xk)>eps || iter_count == 1){
        iter_count++;


        
 
        x = xk;
        for (int i = 0; i <dim; i++)
            xk[i] = xk[i] - 0.01*funcs[i](x);
    }

    return pair(xk, iter_count);
    

}