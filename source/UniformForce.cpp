#include <plaisio/UniformForce.hpp>

#include <cassert>

namespace plaisio {
    UniformForce::UniformForce(double _x, double _z, double _length, double _angle, double _magnitude) : x(_x), z(_x), length(_length), angle(_angle), magnitude(_magnitude) {}

    UniformForce UniformForce::operator - () const {
        return { x, z, length, angle, -magnitude };
    }

    UniformForce UniformForce::operator + (const UniformForce& other) const {
        // Summing up uniform laods with different angles just doesn't make sense to me, fix that if needed
        assert(other.x == x && other.z == z && other.length == length && other.angle == angle);

        return { x, z, length, angle, magnitude + other.magnitude };
    }

    UniformForce UniformForce::operator - (const UniformForce& other) const {
        return *this + (-other);
    }

    std::pair<UniformForce, UniformForce> UniformForce::components(double xAngle, double zAngle) const {
        assert(abs(xAngle - zAngle) == M_PI/2);

        double xLength = length * cos(angle - xAngle);
        double zLength = length * sin(angle - xAngle);

        double xMag = magnitude * cos(angle - xAngle);
        double zMag = magnitude * sin(angle - xAngle);
        if (xAngle - zAngle > 0) {
            zMag = -zMag;
        }

        return { { x, z, xLength, xAngle, xMag}, { x, z, zLength, zAngle, zMag } };
    }

    Force UniformForce::equivalentForce() const {
        // Returns a Force vector that is applied in the middle point of the uniform load with a magnitude equal to the area of the uniform load
        // This vector can be used in external force and moment calculations but should not be used when calculating the internal state of beam sections

        // Let's find that middle point
        double dz = (length / 2) * sin(angle);
        double dx = (length / 2) * cos(angle);

        return { x + dx, z + dz, angle - M_PI/2, magnitude * length };
    }
}
