#include <plaisio/math/CoordinateSystem.hpp>

#define _USE_MATH_DEFINES
#include <cmath>
#undef  _USE_MATH_DEFINES

namespace plaisio {
namespace math {
    CoordinateSystem::CoordinateSystem(Angle _xAngle, Angle _zAngle) : xAngle(_xAngle), zAngle(_zAngle) {}

    CoordinateSystem CoordinateSystem::GlobalSystem = { 0, M_PI/2 };
}
}
