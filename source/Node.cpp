#include <plaisio/Node.hpp>

#include <algorithm>

namespace plaisio {
    Node::Node(double _x, double _z) : x(_x), z(_z), beams(), hinges(), resistances(), force(x, z, 0, 0), moment(x, z, 0) {}

    int Node::freedom() const {
        int constraints = 0;
        for(auto const& res: resistances) {
            if(res.type != Resistance::Type::None) {
                constraints++;
            }
        }

        return 3 - constraints;
    }

    void Node::addForce(Force f) {
        force = force + f;
    }

    void Node::addMoment(Moment m) {
        moment = moment + m;
    }

    bool Node::validate() {
        // We assume we finished tinkering with stuff at this point, so let's sort our vectors
        std::sort(beams.begin(), beams.end());

        for(auto& hinge: hinges) {
            std::sort(hinge.beams.begin(), hinge.beams.end());
        }

        // Here is what we will validate:
        // All beams that appear in hinges also appear in the node's beams
        // No beam appears twice in hinges
        // A node with hinges (or a hinge) mustn't have its moment be constrained 

        if(!hinges.empty() && momentResistance.type != Resistance::Type::None) {
            return false;
        }

        for(auto const& beam: beams) {
            bool beamFound = false;

            for(auto const& hinge: hinges) {
                if(std::find(hinge.beams.begin(), hinge.beams.end(), beam) != hinge.beams.end()) {
                    if(!beamFound) {
                        beamFound = true;
                    } else {
                        return false;
                    }
                }
            }
        }

        for(auto const& hinge: hinges) {
            if(!std::includes(beams.begin(), beams.end(), hinge.beams.begin(), hinge.beams.end())) {
                return false;
            }
        }

        return true;
    }
}
