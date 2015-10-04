#ifndef __ANGLE_H
#define __ANGLE_H

namespace plaisio {
namespace math {
    // Wrapper over a double that does stuff like rollover M_PI*2, correct equality etc.
    class Angle {
    private:
        double value;

    public:
        Angle(double _value);
        Angle(double dz, double dx);

        Angle operator - () const;
        Angle operator + (const Angle& other) const;
        Angle operator - (const Angle& other) const;

        bool operator == (const Angle& other) const;

        operator double () const;

        // Utility function
        double sin() const;
        double cos() const;
        double tan() const;

    private:
        void fixAngle();
    };
}
}

#endif//__ANGLE_H
