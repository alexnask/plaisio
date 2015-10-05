#ifndef __BEAM_H
#define __BEAM_H

#include <plaisio/Material.hpp>
#include <plaisio/Force.hpp>
#include <plaisio/Moment.hpp>
#include <plaisio/UniformForce.hpp>

#include <plaisio/math/CoordinateSystem.hpp>
#include <plaisio/math/Angle.hpp>

#include <vector>
#include <utility>
#include <memory>

namespace plaisio {
    class Node;

    struct Beam {
        Material material;

        std::shared_ptr<Node> start;
        std::shared_ptr<Node> end;

        const math::Angle angle;
        const math::CoordinateSystem coordSystem;
    private:
        // Everything below uses local coordinates and angles
        // Every one has unique coords, forces in same coords are composed
        std::vector<Force> forces;
        std::vector<Moment> moments;
        std::vector<UniformForce> uniformForces;

    public:
        Beam(Material _material, std::shared_ptr<Node> _start, std::shared_ptr<Node> _end);

        double dx() const;
        double dz() const;

        // These funcitons tmake sure we have no duplicates (eg 2 forces with the same application point) as well as transform global to lcoal coordinates
        void addForce(const Force& f);
        void addMoment(const Moment& m);
        void addUniformForce(const UniformForce& uf);

        // Returns a beam with inverted start and end nodes and the same loads.
        Beam reverse() const;

        bool operator == (const Beam& other) const;
    };
}

#endif//__BEAM_H
