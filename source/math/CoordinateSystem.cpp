#include <plaisio/math/CoordinateSystem.hpp>

#define _USE_MATH_DEFINES
#include <cmath>
#undef  _USE_MATH_DEFINES

#include <cassert>

namespace plaisio {
namespace math {
    CoordinateSystem::CoordinateSystem(Angle _xAngle, Angle _zAngle, double _originX, double _originZ) : xAngle(_xAngle), zAngle(_zAngle)
                                                                                                       , originX(_originX), originZ(_originZ) {
        assert(abs(xAngle - zAngle) == M_PI/2);
    }

    CoordinateSystem CoordinateSystem::Global = { 0, M_PI/2, 0, 0 };

    bool CoordinateSystem::operator == (const CoordinateSystem& other) const {
        return xAngle == other.xAngle && zAngle == other.zAngle && originX == other.originX && originZ == originZ;
    }
}
}
