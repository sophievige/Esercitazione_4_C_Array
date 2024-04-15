#include "Utils.hpp"

double prodottoScalare (const double* const& pv1, const double* const& pv2, const int& n){
    double ris=0;
    for (int i=0; i<n; i++){
        double val1= *(pv1+i);
        double val2 = *(pv2+i);
        ris = ris+(val1*val2);
    }
    return ris;
}
