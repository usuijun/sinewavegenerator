//
//  sinewave.h
//  sinewavegenerator
//
//  Created by usui on 12/04/27.
//  Distributed under the Boost Software License, Version 1.0.
//

#ifndef udsp_sinewave_h
#define udsp_sinewave_h

#include <cmath>
#include <stdint.h>
#include "unitconv.h"

using namespace std;

namespace udsp {
    /**
     *  Responsibility: Generate sine wave in specific condition.
     */
    template <class FLOAT>
    class SineWave {
    public:
        static FLOAT* GenerateInSec(double freq, double sec, double fs, double amplitude) {
            int64_t nsample = sec2point(sec, fs);
            FLOAT *out_data = new FLOAT[nsample];
            for (int64_t i = 0; i < nsample; ++i) {
                double sec = point2sec(i, fs);
                out_data[i] = sin(2 * M_PI * freq * sec) * amplitude;
            }
            return out_data;
        }
        
        static FLOAT* GenerateInCycle(double freq, int cycle, double fs, double amplitude) {
            int64_t nsample = cycle * fs;
            FLOAT *out_data = new FLOAT[nsample];
            for (int64_t i = 0; i < nsample; ++i) {
                double sec = point2sec(i, fs);
                out_data[i] = sin(2 * M_PI * freq * sec) * amplitude;
            }
            return out_data;
        }
    };
}

#endif
