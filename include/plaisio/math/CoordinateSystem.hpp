#ifndef __COORDINATE_SYSTEM_H
#define __COORDINATE_SYSTEM_H

#include <plaisio/math/Angle.hpp>

namespace plaisio {
namespace math {
    // A coordinate system is just the counter clockwise angles of the x and z axes from the global x axis.
    struct CoordinateSystem {
        Angle xAngle;
        Angle zAngle;

        static CoordinateSystem GlobalSystem;

        CoordinateSystem(Angle _xAngle, Angle _zAngle);
    };
}
}

#endif//__COORDINATE_SYSTEM_H
