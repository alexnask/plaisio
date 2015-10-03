#ifndef __MOMENT_H
#define __MOMENT_H

namespace plaisio {
    class Moment {
    private:
        double x;
        double z;

        double magnitude;

    public:
        Moment(double _x, double _z, double _magnitude);

        Moment operator - () const;
        Moment operator + (const Moment& other) const;
        Moment operator - (const Moment& other) const;
    };
}

#endif//__MOMENT_H
