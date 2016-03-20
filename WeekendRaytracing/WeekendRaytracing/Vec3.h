#pragma once
#include "math.h"
class vec3
{
public:
	vec3(){}
	vec3(float e1, float e2, float e3)
	{
		e[0] = e1;
		e[1] = e2;
		e[2] = e3;
	}
	inline float x() const { return e[0]; }
	inline float y() const { return e[1]; }
	inline float z() const { return e[2]; }
	
	inline float r() const { return e[0]; }
	inline float g() const { return e[1]; }
	inline float b() const { return e[2]; }

	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	inline float operator[](int i) const { return e[i]; }
	inline float& operator[](int i) { return e[i]; }

	inline vec3& operator+=(const vec3& v2);
	inline vec3& operator-=(const vec3& v2);
	inline vec3& operator*=(const vec3& v2);
	inline vec3& operator/=(const vec3& v2);

	inline vec3& operator*=(const float t);
	inline vec3& operator/=(const float t);

	inline vec3& operator*(const float t) const;
	inline vec3 operator/(const float t) const;

	friend inline vec3 operator*(const float t, const vec3& v) 
	{
		return v * t;
	}

	inline float length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
	inline float squared_length() const { return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
	inline void make_unit_vector();

private:
	float e[3];
};

inline vec3& vec3::operator+=(const vec3& v2)
{
	e[0] += v2[0];
	e[1] += v2[1];
	e[2] += v2[2];
	return *this;
}

inline vec3& vec3::operator-=(const vec3& v2)
{
	e[0] -= v2[0];
	e[1] -= v2[1];
	e[2] -= v2[2];
	return *this;

}

inline vec3& vec3::operator*=(const vec3& v2)
{
	e[0] *= v2[0];
	e[1] *= v2[1];
	e[2] *= v2[2];
	return *this;

}

inline vec3& vec3::operator/=(const vec3& v2)
{
	e[0] /= v2[0];
	e[1] /= v2[1];
	e[2] /= v2[2];
	return *this;

}

inline vec3& vec3::operator*=(const float t)
{
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;

}

inline vec3& vec3::operator/=(const float t)
{
	e[0] /= t;
	e[1] /= t;
	e[2] /= t;
	return *this;

}

inline vec3& vec3::operator*(const float t) const
{
	return vec3(e[0] * t, e[1] * t, e[2] * t);
}

inline vec3 vec3::operator/(const float t) const
{
	return vec3(e[0] / t, e[1] / t, e[2] / t);
}

inline void vec3::make_unit_vector()
{
	float d = 1 / length();
	e[0] *= d;
	e[1] *= d;
	e[2] *= d;
}

inline vec3 operator+(const vec3& v1, const vec3& v2)
{
	return vec3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}


inline vec3 operator-(const vec3& v1, const vec3& v2)
{
	return vec3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}


inline vec3 operator*(const vec3& v1, const vec3& v2)
{
	return vec3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}


inline vec3 operator/(const vec3& v1, const vec3& v2)
{
	return vec3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

inline float dot(const vec3& v1, const vec3& v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2)
{
	return vec3(v1[1] * v2[2] - v1[2] * v2[1],
			  -(v1[0] * v2[2]) - v1[2] * v2[0],
				v1[0] * v2[2] - v1[2] * v2[0]);
}

inline vec3 unit_vector(vec3 v1)
{
	float d = v1.length();
	return v1 / d;
}

