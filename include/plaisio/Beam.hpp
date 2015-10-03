#ifndef __BEAM_H
#define __BEAM_H

#include <plaisio/Node.hpp>
#include <plaisio/Material.hpp>
#include <plaisio/Force.hpp>
#include <plaisio/Moment.hpp>
#include <plaisio/UniformForce.hpp>

#include <vector>

struct Beam {
    Material material;

    Node *start;
    Node *end;

    // Everything below uses local coordinates and angles
    // Every one has unique coords, forces in same coords are composed
    std::vector<Force> forces;
    std::vector<Moment> moments;
    std::vector<UniformForce> uniformForces;
};

#endif//__BEAM_H
