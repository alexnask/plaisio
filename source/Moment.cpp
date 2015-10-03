#include <plaisio/Moment.hpp>

#include <cassert>

namespace plaisio {
    Moment::Moment(double _x, double _z, double _magnitude) : x(_x), z(_z), magnitude(_magnitude) {}

    Moment Moment::operator - () const {
        return { x, z, -magnitude };
    }

    Moment Moment::operator + (const Moment& other) const {
        assert(x == other.x && z == other.z);

        return { x, z, magnitude + other.magnitude };
    }

    Moment Moment::operator - (const Moment& other) const {
        return *this + (-other);
    }
}
