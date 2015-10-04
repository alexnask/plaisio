#include <plaisio/Beam.hpp>
#include <plaisio/Node.hpp>

#include <cmath>
#include <algorithm>

namespace plaisio {
    Beam::Beam(Material _material, Node *_start, Node *_end) : material(_material), start(_start), end(_end)
                                                               , angle(dz(), dx()), coordSystem(angle, angle +  math::Angle { M_PI/2 }, start->x, start->z)
                                                               , forces(), moments(), uniformForces() {}

    double Beam::dx() const {
        return end->x - start->x;
    }

    double Beam::dz() const {
        return end->z - start->z;
    }
}
