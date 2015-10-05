#include <plaisio/Frame.hpp>

#include <algorithm>
#include <utility>

static bool node_less_than(std::shared_ptr<plaisio::Node> one, std::shared_ptr<plaisio::Node> two) {
    if(one->x == two->x) {
        return one->z < two->z;
    }

    return one->x < two->x;
}

namespace plaisio {
    Frame::Frame() : nodes(), beams() {}

    void Frame::finalizeInput() {
        std::sort(nodes.begin(), nodes.end(), node_less_than);

        // Rearrange the start and end of the beams to match the order they are in in the vector
        for(auto& beam: beams) {
            if(!node_less_than(beam->start, beam->end)) {
                // Let's reverse this beam
                auto newBeam = std::make_shared<Beam>(beam->reverse());
                beam->start->replaceBeam(beam, newBeam);
                beam->end->replaceBeam(beam, newBeam);
                beam = newBeam;
            }
        }
    }

    void Frame::addNode(Node node) {
        nodes.emplace_back(std::make_shared<Node>(std::move(node)));
    }

    void Frame::addBeam(Beam beam) {
        beams.emplace_back(std::make_shared<Beam>(std::move(beam)));
    }
}
