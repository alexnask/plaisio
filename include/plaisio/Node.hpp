#ifndef __NODE_H
#define __NODE_H

#include <plaisio/Beam.hpp>
#include <plaisio/Hinge.hpp>

#include <vector>

struct Node {
    double x;
    double z;

    std::vector<Beam*> beams;
    std::vector<Hinge> hinges;
};

#endif//__NODE_H
