#ifndef __NODE_H
#define __NODE_H

#include <plaisio/Beam.hpp>
#include <plaisio/Hinge.hpp>
#include <plaisio/Force.hpp>
#include <plaisio/Moment.hpp>

#include <vector>

namespace plaisio {
    struct Node {
        double x;
        double z;

        std::vector<Beam*> beams;
        std::vector<Hinge> hinges;

        Force force;
        Moment moment;
    };
}

#endif//__NODE_H
