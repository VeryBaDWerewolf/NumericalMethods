#pragma once

#include "sd.h"


pair<DoubMatrix, DoubMatrix> LU(DoubMatrix A){
    DoubMatrix L, U; 

    int dim = A.size();

    U = A; 
    L = DoubMatrix(dim, vector<double>(dim, 0));
    


	for(int i = 0; i < dim; i++)
		for(int j = i; j < dim; j++)
			L[j][i]=U[j][i]/U[i][i];
	
	for(int k = 1; k < dim; k++){
		for(int i = k-1; i < dim; i++)
			for(int j = i; j < dim; j++)
				L[j][i]=U[j][i]/U[i][i];

		for(int i = k; i < dim; i++)
			for(int j = k-1; j < dim; j++)
				U[i][j]=U[i][j]-L[i][k-1]*U[k-1][j];
	}

    return pair(L, U);

}

vector<double> solveLU(DoubMatrix A, vector<double> b){
    int dim = A.size();

    pair<DoubMatrix, DoubMatrix> decomp = LU(A);
    DoubMatrix L = decomp.first; DoubMatrix U = decomp.second;
    double s = 0;
    vector<double> y(dim, 0);

    for(int i = 0; i<dim; i++){
        s = 0;
        for(int k = 0; k<i; k++)
            s += L[i][k]*y[k];
        y[i] = b[i] - s;
    }
    

    vector<double> x(dim, 0);
    for(int j = dim - 1; j >= 0; j--){
        double s = 0;
        for(int i = j+1; i<dim; i++)
            s += U[j][i]*x[i];
        x[j] = (y[j] - s)/U[j][j];
    } 
    return x;
}