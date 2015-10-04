#ifndef __UNIFORM_FORCE_H
#define __UNIFORM_FORCE_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <utility>

#include <plaisio/Force.hpp>

namespace plaisio {
    struct UniformForce {
        double x;
        double z;

        double length;
        double angle;

        double magnitude;

        UniformForce(double _x, double _z, double _length, double _angle, double _magnitude);

        UniformForce operator - () const;
        UniformForce operator + (const UniformForce& other) const;
        UniformForce operator - (const UniformForce& other) const;

        std::pair<UniformForce, UniformForce> components(double xAngle = 0, double zAngle = M_PI/2) const;

        // Note: Don't use this to find internal moments, please
        Force equivalentForce() const;
    };
}

#endif//__UNIFORM_FORCE_H
