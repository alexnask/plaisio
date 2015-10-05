#ifndef __NODE_H
#define __NODE_H

#include <plaisio/Beam.hpp>
#include <plaisio/Hinge.hpp>

#include <vector>
#include <array>
#include <memory>

namespace plaisio {
    struct Node {
        struct Resistance {
            enum class Type {
                None,
                Spring,
                Solid
            };

            Type type;
            double springStiffness;
        };

        double x;
        double z;

        std::vector<std::shared_ptr<Beam>> beams;
        // TODO: Make sure all beams in hinges are in the beams vector
        // Also, make sure no beam appears twice in hinges
        std::vector<Hinge> hinges;

        union {
            struct {
                Resistance xResistance;
                Resistance zResistance;
                Resistance momentResistance;
            };

            std::array<Resistance, 3> resistances;
        };

    private:
        Force force;
        Moment moment;


    public:
        Node(double _x, double _z);

        int freedom() const;
        bool validate();

        void addForce(Force f);
        void addMoment(Moment m);

        void replaceBeam(std::shared_ptr<Beam> beam, std::shared_ptr<Beam> newBeam);
    };
}

#endif//__NODE_H
