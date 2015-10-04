#ifndef __FORCE_H
#define __FORCE_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <utility>

#include <plaisio/math/Vector.hpp>

namespace plaisio {
    struct Force {
        // Application point of the vector
        double x;
        double z;

        // Force vector
        math::Vector vec;

        Force(double _x, double _z, math::Vector _vec);

        Force operator - () const;
        Force operator + (const Force& other) const;
        Force operator - (const Force& other) const;

        // Convenience function
        std::pair<Force, Force> components(const math::CoordinateSystem&  coordSystem) const;
    };
}

#endif//__FORCE_H
