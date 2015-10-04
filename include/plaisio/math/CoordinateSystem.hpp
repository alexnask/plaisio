#ifndef __COORDINATE_SYSTEM_H
#define __COORDINATE_SYSTEM_H

#include <plaisio/math/Angle.hpp>

namespace plaisio {
namespace math {
    // A coordinate system holds information on the position and angles of the axes in relatio nto the global system.
    struct CoordinateSystem {
        Angle xAngle;
        Angle zAngle;

        double originX;
        double originZ;

        static CoordinateSystem Global;

        CoordinateSystem(Angle _xAngle, Angle _zAngle, double _originX, double _originZ);

        bool operator == (const CoordinateSystem& other) const;
    };
}
}

#endif//__COORDINATE_SYSTEM_H
