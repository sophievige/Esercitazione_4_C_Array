#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "Utils.hpp"
using namespace std;
int main()
{
    string fileName= "data.csv";
    ifstream ifstr(fileName);
    if(ifstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }
    ofstream ofstr("result.txt");
    if(ofstr.fail())
    {
        cerr << "File does not exist" << endl;
        return 1;
    }

    //salvo le condizioni iniziali per la stampa
    ios init(NULL);
    init.copyfmt(cout);

    string SStr;
    getline(ifstr, SStr);
    istringstream convertS(SStr);
    double S;
    char SChar; //da ignorare
    char pvChar;
    convertS >> SChar >> pvChar >> S;

    string nStr;
    getline(ifstr, nStr);
    istringstream convertn(nStr);
    int n;
    //sovrascrivo i caratteri da ignorare
    convertn >> SChar >> pvChar >> n;
    ofstr << "S = " << fixed << setprecision(2) << S << ", ";
    ofstr << "n = " << n << endl;

    string ignore;
    getline(ifstr, ignore);

    double *pw = new double[n];
    double *pr = new double[n];

    string line;
    double wi;
    double ri;
    ofstr << "w = [ ";
    //ripristino le condizioni iniziali per la stampa
    ofstr.copyfmt(init);

    //stampo già il primo vettore (così non devo fare un ciclo in più apposta)
    for (int i=0; i<n; i++){
        getline(ifstr, line);
        istringstream convertLine(line);
        convertLine >> wi >> pvChar >> ri;
        *(pw+i)=wi;
        ofstr << wi << " ";
        *(pr+i)=(ri+1); //per fare il prodotto scalare poi mi serve r+1
    }

    ofstr << "]" << endl;

    //stampo r (devo sottrarre 1 perché avevo salvato r+1)
    ofstr << "r = [ ";
    for (int j=0; j<n; j++){
        ofstr << *(pr+j)-1 << " ";
    }
    ofstr << "]" << endl;

    double V = prodottoScalare(pw, pr, n);
    V = V*S;
    double R = (V-S)/S;

    ofstr << "Rate of return of the portfolio: " << fixed << setprecision(4) << R <<endl;
    ofstr << "V: " << fixed << setprecision(2) << V << endl;


    ifstr.close();
    ofstr.close();
    delete [] pw;
    delete [] pr;

  return 0;
}

