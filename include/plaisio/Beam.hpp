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

namespace plaisio {
    class Node;

    struct Beam {
        Material material;

        Node *start;
        Node *end;

        const math::Angle angle;
        const math::CoordinateSystem coordSystem;
    private:
        // Everything below uses local coordinates and angles
        // Every one has unique coords, forces in same coords are composed
        std::vector<Force> forces;
        std::vector<Moment> moments;
        std::vector<UniformForce> uniformForces;

    public:
        Beam(Material _material, Node* _start, Node* _end);

        double dx() const;
        double dz() const;

        // These funcitons tmake sure we have no duplicates (eg 2 forces with the same application point) as well as transform global to lcoal coordinates
        void addForce(Force f);
        void addMoment(Moment m);
        void addUniformForce(UniformForce uf);
    };
}

#endif//__BEAM_H
