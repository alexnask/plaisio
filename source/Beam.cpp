#include <plaisio/Beam.hpp>
#include <plaisio/Node.hpp>

#include <cmath>
#include <algorithm>

static double computeAngle(double zDiff, double xDiff) {
    if (xDiff == 0) {
        return zDiff > 0 ? M_PI/2 : -M_PI/2;
    }

    return atan2(zDiff, xDiff);
}

namespace plaisio {
    Beam::Beam(Material _material, Node *_start, Node *_end) : material(_material), start(_start), end(_end)
                                                               , angle(computeAngle(dz(), dx())), forces(), moments(), uniformForces() {}

    double Beam::dx() const {
        return end->x - start->x;
    }

    double Beam::dz() const {
        return end->z - start->z;
    }

    void Beam::addForce(Force f) {
        // TODO: Magnitude may need to be inverted sometimes.
        auto localCoords = coordsFromGlobal(f.x, f.z);
        f.x = localCoords.first;
        f.z = localCoords.second;
        f.angle = angleFromGlobal(f.angle);

        // try to find a force applied on the same point
        auto existing = std::find_if(forces.begin(), forces.end(), [&f] (auto force) {
            return f.x == force.x && f.z == force.z;
        });

        if(existing != forces.end()) {
            *existing = *existing + f;
        } else {
            forces.push_back(f);
        }
    }

    void Beam::addMoment(Moment m) {
        // Magnitude stays the same because we still use clockwise as positive
        auto localCoords = coordsFromGlobal(m.x, m.z);
        m.x = localCoords.first;
        m.z = localCoords.second;

        auto existing = std::find_if(moments.begin(), moments.end(), [&m] (auto moment) {
            return moment.x == m.x && moment.z == m.z;
        });

        if(existing != moments.end()) {
            *existing = *existing + m;
        } else {
            moments.push_back(m);
        }
    }
}
