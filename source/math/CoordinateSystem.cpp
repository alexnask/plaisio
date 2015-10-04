#include <plaisio/math/CoordinateSystem.hpp>

#define _USE_MATH_DEFINES
#include <cmath>
#undef  _USE_MATH_DEFINES

namespace plaisio {
namespace math {
    CoordinateSystem::CoordinateSystem(Angle _xAngle, Angle _zAngle, double _originX, double _originZ) : xAngle(_xAngle), zAngle(_zAngle)
                                                                                                       , originX(_originX), originZ(_originZ) {}

    CoordinateSystem CoordinateSystem::GlobalSystem = { 0, M_PI/2, 0, 0 };
}
}
