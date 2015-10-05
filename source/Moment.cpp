#include <plaisio/Moment.hpp>

#include <cassert>

namespace plaisio {
    Moment::Moment(double _x, double _z, double _magnitude, math::CoordinateSystem _coordSystem) : x(_x), z(_z), magnitude(_magnitude), coordSystem(_coordSystem) {}

    Moment Moment::operator - () const {
        return { x, z, -magnitude, coordSystem };
    }

    Moment Moment::operator + (const Moment& other) const {
        Moment localOther = other;

        if(localOther.coordSystem != coordSystem) {
            localOther = localOther.inCoordSystem(coordSystem);
        }
        assert(x == localOther.x && z == localOther.z);

        return { x, z, magnitude + localOther.magnitude, coordSystem };
    }

    Moment Moment::operator - (const Moment& other) const {
        return *this + (-other);
    }

    bool Moment::operator == (const Moment& other) const {
        return x == other.x && z == other.z && coordSystem == other.coordSystem;
    }

    Moment Moment::inCoordSystem(const math::CoordinateSystem& newCoordSystem) const {
        auto newCoords = newCoordSystem.localCoordinates(x, z, coordSystem);

        return { newCoords.first, newCoords.second, magnitude, coordSystem };
    }
}
