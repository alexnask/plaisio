#include <plaisio/UniformForce.hpp>

#include <cassert>

namespace plaisio {
    UniformForce::UniformForce(double _startX, double _startZ, double _endX, double _endZ, math::Vector _vec) : startX(_startX), startZ(_startZ), endX(_endX)
                                                                                                              , endZ(_endZ), vec(_vec) {}

    UniformForce UniformForce::operator - () const {
        return { startX, startZ, endX, endZ, -vec };
    }

    UniformForce UniformForce::operator + (const UniformForce& other) const {
        // Summing up uniform loads with different angles just doesn't make sense to me, add the capability to do so if needed
        assert(other.startX == startX && other.startZ == startZ && other.endX == endX && other.endZ == endZ);

        return { startX, startZ, endX, endZ, vec + other.vec };
    }

    UniformForce UniformForce::operator - (const UniformForce& other) const {
        return *this + (-other);
    }

    std::pair<UniformForce, UniformForce> UniformForce::components(const math::CoordinateSystem& coordSystem) const {
        auto vecComponents = vec.inCoordSystem(coordSystem).getComponents();
        return { { startX, startZ, endX, endZ, vecComponents.first }, { startX, startZ, endX, endZ, vecComponents.second } };
    }

    Force UniformForce::equivalentForce() const {
        // Returns a Force vector that is applied in the middle point of the uniform load with a magnitude equal to the area of the uniform load
        // This vector can be used in external force and moment calculations but should not be used when calculating the internal state of beam sections
        return { (startX + endX) / 2 , (startZ + endZ) / 2, vec * length() };
    }

    double UniformForce::length() const {
        double dx = endX - startX;
        double dz = endZ - startZ;
        return sqrt(dx * dx + dz * dz);
    }
}
