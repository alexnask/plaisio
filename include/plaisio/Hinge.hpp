#ifndef __HINGE_H
#define __HINGE_H

#include <vector>
#include <memory>

namespace plaisio {
    struct Hinge {
        std::vector<std::shared_ptr<Beam>> beams;
    };
}

#endif//__HINGE_H
