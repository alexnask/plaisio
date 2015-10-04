#include <plaisio/Force.hpp>

#include <cassert>

namespace plaisio {
    Force::Force(double _x, double _z, double _angle, double _magnitude) : x(_x), z(_z), angle(_angle), magnitude(_magnitude) {}

    Force Force::operator - () const {
        return { x, z, angle, -magnitude };
    }

    Force Force::operator + (const Force& other) const {
        assert(x == other.x && z == other.z);

        auto pair1 = components();
        auto pair2 = other.components();

        double xMagn = pair1.first.magnitude + pair2.first.magnitude;
        double yMagn = pair2.second.magnitude + pair2.second.magnitude;

        double nAngle = xMagn == 0 ? M_PI / 2 : atan2(yMagn, xMagn);

        return { x, z, nAngle,  sqrt(xMagn * xMagn + yMagn * yMagn)};
    }

    Force Force::operator - (const Force& other) const {
        return *this + (-other);
    }

    std::pair<Force, Force> Force::components(double xAngle, double zAngle) const {
        assert(abs(xAngle - zAngle) == M_PI/2);

        double newX = magnitude * cos(angle - xAngle);
        double newZ = magnitude * sin(angle - xAngle);
        if (xAngle - zAngle > 0) {
            newZ = -newZ;
        }

        return { { x, z, xAngle, newX}, { x, z, zAngle, newZ } };
    }
}
