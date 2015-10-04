#include <plaisio/math/Angle.hpp>

#define _USE_MATH_DEFINES
#include <cmath>
#undef  _USE_MATH_DEFINES

namespace plaisio {
namespace math {
    Angle::Angle(double _value) : value(_value) {
        fixAngle();
    }

    Angle::Angle(double dz, double dx) {
        if(dx == 0) {
            value = dz > 0 ? M_PI/2 : -M_PI/2;
        } else {
            value = atan2(dz, dx);
        }
    }

    Angle Angle::operator - () const {
        return { -value };
    }

    Angle Angle::operator + (const Angle& other) const {
        return { value + other.value };
    }

    Angle Angle::operator - (const Angle& other) const {
        return *this + (-other);
    }

    double inline Angle::sin() const {
        return ::sin(value);
    }

    double inline Angle::cos() const {
        return ::cos(value);
    }

    double inline Angle::tan() const {
        return ::tan(value);
    }

    void Angle::fixAngle() {
        if(value > M_PI*2) {
            int times = (int) (value / (M_PI*2));
            value -= times * M_PI * 2;
        } else if(value < -M_PI*2) {
            int times = (int) (value / (M_PI*2));
            value += times * M_PI * 2;
        }
    }
}
}