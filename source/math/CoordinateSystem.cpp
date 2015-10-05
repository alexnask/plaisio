#include <plaisio/math/CoordinateSystem.hpp>

#define _USE_MATH_DEFINES
#include <cmath>
#undef  _USE_MATH_DEFINES

#include <cassert>

#include <plaisio/Math/Vector.hpp>

namespace plaisio {
namespace math {
    CoordinateSystem::CoordinateSystem(Angle _xAngle, Angle _zAngle, double _originX, double _originZ) : xAngle(_xAngle), zAngle(_zAngle)
                                                                                                       , originX(_originX), originZ(_originZ) {
        assert(abs(xAngle - zAngle) == M_PI/2);
    }

    CoordinateSystem CoordinateSystem::Global = { 0, M_PI/2, 0, 0 };

    std::pair<double, double> CoordinateSystem::localCoordinates(double oX, double oZ, const CoordinateSystem& other) const {
        double dx = originX - other.originX;
        double dz = originZ - other.originZ;

        // First cause: different origins
        double newX = oX - dx;
        double newZ = oZ - dz;

        // Second cause: axes rotation
        // Let's use vectors to do that
        // Also takes care of flipping the z value if need be
        Vector newOrigin = { newX, newZ, other };
        newOrigin = newOrigin.inCoordSystem(*this);

        return { newOrigin.x, newOrigin.z };
    }

    bool CoordinateSystem::operator == (const CoordinateSystem& other) const {
        return xAngle == other.xAngle && zAngle == other.zAngle && originX == other.originX && originZ == originZ;
    }

    bool CoordinateSystem::operator != (const CoordinateSystem& other) const {
        return !(*this == other);
    }
}
}
