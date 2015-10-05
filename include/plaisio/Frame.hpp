#ifndef __FRAME_H
#define __FRAME_H

#include <plaisio/Node.hpp>
#include <plaisio/Beam.hpp>

#include <memory>

namespace plaisio {
    class Frame {
    private:
        // This will be sorted by x then z (if two elements have the same x, sort them by z)
        std::vector<std::shared_ptr<Node>> nodes;
        std::vector<std::shared_ptr<Beam>> beams;

    public:
        // Sort the nodes and beams
        void finalizeInput();

        Frame();
        void addNode(Node node);
        void addBeam(Beam beam);
    };
}

#endif//__FRAME_H
