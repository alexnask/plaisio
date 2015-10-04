#ifndef __VECTOR_H
#define __VECTOR_H

#include <plaisio/math/CoordinateSystem.hpp>

#include <utility>

namespace plaisio {
namespace math {
    struct Vector {
        double x;
        double z;

        CoordinateSystem coordSystem;

        Vector(double _x, double _z, CoordinateSystem _coordSystem = CoordinateSystem::Global);

        double magnitude() const;

        Vector inCoordSystem(const CoordinateSystem& newCS) const;
        std::pair<Vector, Vector> getComponents() const;

        Vector operator - () const;
        Vector operator + (const Vector& other) const;
        Vector operator - (const Vector& other) const;
        Vector operator * (double multi) const;
        Vector operator / (double divi) const;
    };
}
}

#endif//__VECTOR_H
