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

    std::pair<Force, Force> Force::components(const math::CoordinateSystem& coordSystem) const {
        auto vecComponents = vec.inCoordSystem(coordSystem).getComponents();
        return { { x, z, vecComponents.first }, { x, z, vecComponents.second } };
    }
}
