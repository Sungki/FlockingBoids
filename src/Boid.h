#pragma once
#include <iostream>
#include <vector>


class Vector
{
public:
	float x;
	float y;

	Vector() : x(0), y(0) {}
	Vector(float _x, float _y) : x(_x), y(_y) {}
	void addVector(Vector v)
	{
		x += v.x;
		y += v.y;
	}
	void mulScalar(float s)
	{
		x *= s;
		y *= s;
	}
	void set(float i, float o)
	{
		x = i;
		y = o;
	}
	float magnitude()
	{
		return sqrt(x * x + y * y);
	}
	void normalize()
	{
		float m = magnitude();

		if (m > 0) {
			set(x / m, y / m);
		}
		else {
			set(x, y);
		}
	}
	void setMagnitude(float x)
	{
		normalize();
		mulScalar(x);
	}
	void limit(double max)
	{
		double size = magnitude();

		if (size > max) {
			set(x / size, y / size);
		}
	}
	void divScalar(float s)
	{
		if (s == 0) return;

		x /= s;
		y /= s;
	}
	float distance(Vector v)
	{
		float dx = x - v.x;
		float dy = y - v.y;
		float dist = sqrt(dx * dx + dy * dy);

		if (dist < 0) dist = -dist;

		return dist;
	}
	void subVector(Vector v)
	{
		x -= v.x;
		y -= v.y;
	}
	Vector subTwoVector(Vector v, Vector v2)
	{
		Vector tmp;
		v.x -= v2.x;
		v.y -= v2.y;
		tmp.set(v.x, v.y);
		return tmp;
	}
};

class Boid
{
public:
	Vector position;
	Vector velocity;
	Vector acceleration;

	void Update();

	Boid(float x, float y);
};

