#include <plaisio/math/Vector.hpp>

#include <cmath>

namespace plaisio {
namespace math {

    Vector::Vector(double _x, double _z, CoordinateSystem _coordSystem) : x(_x), z(_z), coordSystem(_coordSystem) {}

    double Vector::magnitude() const {
        return sqrt(x * x + z * z);
    }

    Vector Vector::inCoordSystem(const CoordinateSystem& newCS) const {
        // We don't use == directly on the coordinate systems because we don't care about their origins here
        if(newCS.xAngle == coordSystem.xAngle && newCS.zAngle == coordSystem.zAngle) {
            return *this;
        }

        auto theta = newCS.xAngle - coordSystem.xAngle;

        double sinTheta = theta.sin();
        double cosTheta = theta.cos();

        double newX =  cosTheta * x + sinTheta * z;
        double newZ = -sinTheta * x + cosTheta * z;

        // If the relative places of the x and z angle are not the same in the two coordinate systems, we need to invert the z component
        if(coordSystem.xAngle - coordSystem.zAngle != newCS.xAngle - newCS.zAngle) {
            newZ = -newZ;
        }

        return { newX, newZ, newCS };

    }

    // Convenience function
    std::pair<Vector, Vector> Vector::getComponents() const {
        return { { x, 0, coordSystem }, { 0, z, coordSystem } };
    }

    Vector Vector::operator - () const {
        return { -x, -z, coordSystem };
    }

    Vector Vector::operator + (const Vector& other) const {
        auto coordSystemOther = other.inCoordSystem(coordSystem);

        return { x + coordSystemOther.x, z + coordSystemOther.z, coordSystem };
    }

    Vector Vector::operator - (const Vector& other) const {
        return *this + (-other);
    }
}
}
