#include <iostream>
#include <cmath>

#include "nonlinear/bisection.h"
#include "nonlinear/newton.h"
#include "nonlinear/iteration.h"
#include "utils/LU.h"
#include "utils/sd.h"
#include "nonlinear_system/snewton.h"



using namespace std;

double f(double x){
    return 4*(1 - x*x) - exp(x);
}

double f1(VecDoub x){
    return x[0]*x[0]*x[0] + x[1]*x[1]*x[1] - 8*x[0]*x[1];
}
double f2(VecDoub x){
   return x[0]*log(x[1])-x[1]*log(x[0]);
}


int main(int argc, char const *argv[]){

   
    
    vector<double(*)(VecDoub)> fs {f1, f2};
    VecDoub x0 {3.8, 2};

    Pair ans = snewton(fs, x0, 1e-6);
    cout<<ans.first[0]<<" | "<<ans.first[1]<<" | iter:"<<ans.second<<"\n";
   // cout<<ans.second<<"\n";
    

    // pair<double, int> data = iteration(f, 0, 1, 1e-4);

    // cout<<"Answer: "<<data.first<<" | "<<"Iteration: "<<data.second<<endl;
    // cout<<"f(x) = "<<f(data.first)<<"\n";
    // return 0;
}
