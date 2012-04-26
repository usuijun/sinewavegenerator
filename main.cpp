//
//  main.cpp
//  sinewavegenerator
//
//  Created by usui on 12/04/27.
//

#include <iostream>
#include "sinewave.h"

using namespace std;
int main(int argc, const char * argv[])
{
    double freq = 1;
    double sec = 1;
    double fs = 10;
    double amplitude = 1;
    double* sine1 = udsp::SineWave<double>::GenerateInSec(freq, sec, fs, amplitude);
    
    cout << "sinewave1" << endl;
    int64_t outlen = udsp::sec2point(sec, fs);
    for (int64_t i = 0; i < outlen; ++i) {
        cout << sine1[i] << endl;
    }
    
    int cycle = 2;
    double* sine2 = udsp::SineWave<double>::GenerateInCycle(freq, cycle, fs, amplitude);
    
    cout << "sinewave2" << endl;
    outlen = cycle * fs;
    for (int64_t i = 0; i < outlen; ++i) {
        cout << sine2[i] << endl;
    }
    return 0;
}

