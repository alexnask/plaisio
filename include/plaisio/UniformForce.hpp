#ifndef __UNIFORM_FORCE_H
#define __UNIFORM_FORCE_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <utility>

#include <plaisio/Force.hpp>

namespace plaisio {
    struct UniformForce {
        // We use the vector for the magnitude and direction of the load
        double startX;
        double startZ;

        double endX;
        double endZ;

        math::Vector vec;

        UniformForce(double _startX, double _startZ, double _endX, double _endZ, math::Vector _vec);

        UniformForce operator - () const;
        UniformForce operator + (const UniformForce& other) const;
        UniformForce operator - (const UniformForce& other) const;

        bool operator == (const UniformForce& other) const;

        // Convenience function
        std::pair<UniformForce, UniformForce> components(const math::CoordinateSystem& coordSystem) const;

        // Note: Don't use this to find internal moments, please
        Force equivalentForce() const;

        double length() const;
    };
}

#endif//__UNIFORM_FORCE_H
