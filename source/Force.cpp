#include <plaisio/Force.hpp>

#include <cassert>

namespace plaisio {
    Force::Force(double _x, double _z, math::Vector _vec) : x(_x), z(_z), vec(_vec) {}

    Force Force::operator - () const {
        return { x, z, -vec };
    }

    Force Force::operator + (const Force& other) const {
        assert(x == other.x && z == other.z);

        return { x, z, vec + other.vec };
    }

    Force Force::operator - (const Force& other) const {
        return *this + (-other);
    }

    // TODO: change into same coord system before doing this?
    bool Force::operator == (const Force& other) const {
        return x == other.x && z == other.z && vec == other.vec;
    }

    std::pair<Force, Force> Force::components(const math::CoordinateSystem& coordSystem) const {
        auto vecComponents = vec.inCoordSystem(coordSystem).getComponents();
        return { { x, z, vecComponents.first }, { x, z, vecComponents.second } };
    }

    Force Force::inCoordSystem(const math::CoordinateSystem& coordSystem) const {
        auto newCoords = coordSystem.localCoordinates(x, z, vec.coordSystem);

        return { newCoords.first, newCoords.second, vec.inCoordSystem(coordSystem) };
    }
}
