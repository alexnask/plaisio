#ifndef __ANGLE_H
#define __ANGLE_H

namespace plaisio {
namespace math {
    // Wrapper over a double that does stuff like rollover M_PI*2, correct equality etc.
    struct Angle {
        double value;

        Angle(double _value);
        Angle(double dz, double dx);

        Angle operator - () const;
        Angle operator + (const Angle& other) const;
        Angle operator - (const Angle& other) const;

        bool operator == (const Angle& other) const;

        // Utility function
        double inline sin() const;
        double inline cos() const;
        double inline tan() const;

    private:
        void fixAngle();
    };
}
}

#endif//__ANGLE_H
