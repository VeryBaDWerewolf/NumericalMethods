#pragma once


#include "../utils/sd.h"
#include "../utils/LU.h"
#include "../utils/norm.h"


void mPrint(DoubMatrix A){
    int dim = A.size();
    for(int i = 0; i<dim; i++){
        for (int j = 0; j < dim; j++)
            cout<<A[i][j]<<" ";
        cout<<"\n";
        
    }
}

template <class T>
DoubMatrix jacobi(vector<T>& funcs, VecDoub point){  
    const double dlt = 1e-9;
    int dim = funcs.size();
    VecDoub dpoint;

    DoubMatrix Jacobi(dim, VecDoub(dim, 0));
    
    for(int i = 0; i<dim; i++){
        for(int j = 0; j<dim; j++){
            dpoint = point;
            dpoint[j] += dlt;
            Jacobi[i][j] = (funcs[i](dpoint)-funcs[i](point))/dlt;
        }
    }

    return Jacobi;
}

template <class T>
pair<VecDoub, int> snewton(vector<T>& funcs, VecDoub x0, double eps, bool flag = false){
    int dim = funcs.size();
    int iter_count = 1;

    VecDoub x = x0;
    VecDoub xk = x0;

    VecDoub mF(dim, 0);
    VecDoub dX(dim, 0);

    while (norm2(x, xk)>eps || iter_count == 1){
        iter_count++;

        DoubMatrix J = jacobi(funcs, xk);

        for (int i = 0; i <dim; i++)
            mF[i] = -funcs[i](xk);
        
        dX = solveLU(J, mF);
        x = xk;
        for (int i = 0; i <dim; i++)
            xk[i] = xk[i] + dX[i];
    }

    return pair(xk, iter_count);
    

}
