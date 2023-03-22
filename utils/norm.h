#pragma once

#include <cmath>
#include "sd.h"

double norm2(VecDoub v){
    int dim = v.size();
    double norm = 0;

    for(int i = 0; i< dim; i++)
        norm += v[i]*v[i];

    return sqrtl(norm);
}

double norm2(VecDoub u, VecDoub v){
    int dim = v.size();
    double norm = 0;

    for(int i = 0; i< dim; i++)
        norm += (u[i]-v[i])*(u[i]-v[i]);

    return sqrtl(norm);
}