#ifndef VEC3_H
#define VEC3_H

#include<cmath>
#include<iostream>

using std::sqrt;

class vec3 {
    public:
        double e[3];
        
        // constructors
        vec3();
        vec3(double x, double y, double z);

        // getters
        // const functions cannot modify fields
        double getX() const { return e[0]; }
        double getY() const { return e[1]; }
        double getZ() const { return e[2]; }

        // self operations utils

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

        // returns value of e[i]
        double operator[](int i) const { return e[i]; }

        // returns reference to e[i]
        double& operator[](int i) { return e[i]; }

        // takes reference for other vector & adds to current vector.
        // const reference implies that other cannot be changed.
        vec3& operator+=(const vec3& other);

        vec3& operator*=(double n);
    
        vec3& operator/=(double n);

        // length utils

        double length_squared() const;

        double length() const;

};

// aliasing to use vec3 as a point.
using point3 = vec3;

// vector utility functions

// inline to reduce overhead from shifting between stack frames
// inline in header: 

// streams vector content out.
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
};

// arithmetic operations utils

inline vec3 operator+(const vec3& a, const vec3& b) {
    return vec3(a.e[0] + b.e[0], a.e[1] + b.e[1], a.e[2] + b.e[2]);
}

inline vec3 operator-(const vec3& a, const vec3& b) {
    return vec3(a.e[0] - b.e[0], a.e[1] - b.e[1], a.e[2] - b.e[2]);
}

inline vec3 operator*(const vec3& a, const vec3& b) {
    return vec3(a.e[0] * b.e[0], a.e[1] * b.e[1], a.e[2] * b.e[2]);
}

inline vec3 operator*(double n, const vec3& a) {
    return vec3(a.e[0] * n, a.e[1] * n, a.e[2] * n);
}

inline vec3 operator*(const vec3& a, double n) {
    return n * a;
}

inline vec3 operator/(const vec3&a, double n) {
    return (1/n) * a;
}

// matrix operations util

inline double dot(const vec3& a, const vec3& b) {
    return 
        a.e[0] * b.e[0] +
        a.e[1] * b.e[1] +
        a.e[2] * b.e[2];
}

inline vec3 cross(const vec3& a, const vec3& b) {
    return vec3(
        a.e[1] * b.e[2] - a.e[2] * b.e[1],
        a.e[2] * b.e[0] - a.e[0] * b.e[2],
        a.e[0] * b.e[1] - a.e[1] * b.e[0]
    );
}

inline vec3 unit_vector(const vec3& a) {
    return a / a.length();
}

#endif