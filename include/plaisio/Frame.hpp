#ifndef __FRAME_H
#define __FRAME_H

#include <plaisio/Node.hpp>
#include <plaisio/Beam.hpp>

#include <memory>

namespace plaisio {
    struct Frame {
        // This will be sorted by x then z (if two elements have the same x, sort them by z)
        std::vector<std::shared_ptr<Node>> nodes;
        std::vector<std::shared_ptr<Beam>> beams;

        // Sort the nodes and beams
        void finalizeInput();

        Frame();
    };
}

#endif//__FRAME_H
