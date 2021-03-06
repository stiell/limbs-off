/*
 * Copyright (C) 2011 Stian Ellingsen <stian@plaimi.net>
 *
 * This file is part of Limbs Off.
 *
 * Limbs Off is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Limbs Off is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Limbs Off.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GEOMETRY_INL_HXX_
#define GEOMETRY_INL_HXX_

#include "geometry.hxx"

template<typename T>
inline vector2<T> vector2<T>::fromAngle(T angle) {
    vector2 v;
    sincos<T> (angle, v.y, v.x);
    return v;
}

template<typename T>
inline T& vector2<T>::operator[](unsigned int i) {
    return *(&x + i);
}

template<typename T>
inline const T& vector2<T>::operator[](unsigned int i) const {
    return *(&x + i);
}

template<typename T>
inline const vector2<T> vector2<T>::operator()(const T x0, const T y0) {
    x = x0;
    y = y0;
    return *this;
}

template<typename T>
inline const vector2<T> vector2<T>::operator-() const {
    return vector2<T> ()(-x, -y);
}

template<typename T>
inline const vector2<T> vector2<T>::operator~() const {
    return vector2<T> ()(-y, x);
}

template<typename T>
inline const vector2<T> vector2<T>::operator+(const vector2<T>& v) const {
    return vector2<T> ()(x + v.x, y + v.y);
}

template<typename T>
inline const vector2<T> vector2<T>::operator-(const vector2<T>& v) const {
    return vector2<T> ()(x - v.x, y - v.y);
}

template<typename T>
inline const vector2<T> vector2<T>::operator*(const T f) const {
    return vector2<T> ()(x * f, y * f);
}

template<typename T>
inline const vector2<T> vector2<T>::operator/(const T d) const {
    return vector2<T> ()(x / d, y / d);
}

template<typename T>
inline const vector2<T>& vector2<T>::operator+=(const vector2<T>& v) {
    (*this)(x + v.x, y + v.y);
    return *this;
}

template<typename T>
inline const vector2<T>& vector2<T>::operator-=(const vector2<T>& v) {
    (*this)(x - v.x, y - v.y);
    return *this;
}

template<typename T>
inline const vector2<T>& vector2<T>::operator*=(const T f) {
    (*this)(x * f, y * f);
    return *this;
}

template<typename T>
inline const vector2<T>& vector2<T>::operator/=(const T d) {
    (*this)(x / d, y / d);
    return *this;
}

template<typename T>
inline T vector2<T>::operator/(const vector2<T>& v) const {
    return ~(*this) * v;
}

template<typename T>
inline T vector2<T>::operator*(const vector2<T>& v) const {
    return x * v.x + y * v.y;
}

template<typename T>
inline T vector2<T>::squared() const {
    return x * x + y * y;
}

template<typename T>
inline T vector2<T>::length() const {
    return sqrt<T> (squared());
}

template<typename T>
inline T vector2<T>::angle() const {
    return atan2<T> (y, x);
}

template<typename T>
inline const vector2<T> vector2<T>::unit() const {
    T l = length();
    return l > 0 ? vector2<T> (*this) / l : *this;
}

template<typename T>
inline const vector2<T>& vector2<T>::norm() {
    return operator=(unit());
}

template<typename T>
inline const vector2<T> vector2<T>::rotated(vector2<T> u) const {
    return vector2<T> (*this).rotate(u);
}

template<typename T>
inline const vector2<T>& vector2<T>::rotate(vector2<T> u) {
    (*this)(x * u.x - y * u.y, x * u.y + y * u.x);
    return *this;
}

template<typename T>
bool intersectLineCircle(vector2<T> a, vector2<T> b, T rr, T& t1, T& t2) {
    vector2<T> d = b - a;
    T dd = d.squared(), h = a / b;
    T delta = rr * dd - h * h;
    if (delta <= 0)
        return false;
    T srd = sqrt<T> (delta);
    T tm = -a * d;
    t1 = (tm - srd) / dd;
    t2 = (tm + srd) / dd;
    return true;
}

#endif /* GEOMETRY_INL_HXX_ */
