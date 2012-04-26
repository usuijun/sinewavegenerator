//
//  unitconv.h
//  sinewavegenerator
//
//  Created by usui on 12/04/27.
//  Distributed under the Boost Software License, Version 1.0.
//

#ifndef udsp_unitconv_h
#define udsp_unitconv_h

namespace udsp {
    inline int sec2point(const double sec, const double fs, const int stepsize = 1) {
        return (int)(1.0 * sec * fs / stepsize + 0.5);
    }
    template <class INTEGER>
    inline double point2sec(const INTEGER point, const double fs, const int stepsize = 1) {
        return point * stepsize / fs;
    }
}

#endif
