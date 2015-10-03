#ifndef __FORCE_H
#define __FORCE_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <utility>

namespace plaisio {
    class Force {
    private:
        double x;
        double z;

        // Angle from x-axis
        double angle;
        double magnitude;

    public:
        Force(double _x, double _z, double _angle, double _magnitude);

        Force operator - () const;
        Force operator + (const Force& other) const;
        Force operator - (const Force& other) const;

        std::pair<Force, Force> components(double xAngle = 0, double zAngle = M_PI/2) const;
    };
}

#endif//__FORCE_H
