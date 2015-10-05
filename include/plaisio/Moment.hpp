#ifndef __MOMENT_H
#define __MOMENT_H

#include <plaisio/math/CoordinateSystem.hpp>

namespace plaisio {
    struct Moment {
        double x;
        double z;

        double magnitude;

        math::CoordinateSystem coordSystem;

        Moment(double _x, double _z, double _magnitude, math::CoordinateSystem _coordSystem = math::CoordinateSystem::Global);

        Moment operator - () const;
        Moment operator + (const Moment& other) const;
        Moment operator - (const Moment& other) const;

        bool operator == (const Moment& other) const;

        Moment inCoordSystem(const math::CoordinateSystem& coordSystem) const;
    };
}

#endif//__MOMENT_H
