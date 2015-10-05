#include <plaisio/Beam.hpp>
#include <plaisio/Node.hpp>

#include <cmath>
#include <algorithm>

namespace plaisio {
    Beam::Beam(Material _material, std::shared_ptr<Node> _start, std::shared_ptr<Node> _end) : material(_material), start(_start), end(_end)
                                                               , angle(dz(), dx()), coordSystem(angle, angle +  math::Angle { M_PI/2 }, start->x, start->z)
                                                               , forces(), moments(), uniformForces() {}

    double Beam::dx() const {
        return end->x - start->x;
    }

    double Beam::dz() const {
        return end->z - start->z;
    }

    void Beam::addForce(const Force& f) {
        auto localF = f.inCoordSystem(coordSystem);

        for(auto& force: forces) {
            if(force.x == localF.x && force.z == localF.z) {
                force = force + localF;
            } else {
                forces.push_back(localF);
            }
        }
    }

    void Beam::addMoment(const Moment& m) {
        auto localM = m.inCoordSystem(coordSystem);

        for(auto& moment: moments) {
            if(moment.x == localM.x && moment.z == localM.z) {
                moment = moment + localM;
            } else {
                moments.push_back(localM);
            }
        }
    }

    void Beam::addUniformForce(const UniformForce& uf) {
        // Don't try anything too tricky here
        // We could try to find the parts where we have two uniform forces and add them into one + split if we have different lengths
        // But I don't think it's worth the trouble
        uniformForces.push_back(uf);
    }

    Beam Beam::reverse() const {
        Beam b = { material, end, start };

        for(const auto& force: forces) {
            b.addForce(force);
        }

        for(const auto& moment: moments) {
            b.addMoment(moment);
        }

        for(const auto& uf: uniformForces) {
            b.addUniformForce(uf);
        }

        return b;
    }

    bool Beam::operator == (const Beam& other) const {
        return start == other.start && end == other.end && angle == other.angle && coordSystem == other.coordSystem
            && forces == other.forces && moments == other.moments && uniformForces == other.uniformForces;
    }
}
