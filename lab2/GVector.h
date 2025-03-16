#pragma once
class GVector
{
	private: int _x, _y;

	public: 
		GVector(int sx, int sy) : _x(sx), _y(sy) {}
		GVector operator+(GVector b);
		GVector operator*(int scalar);

		int x() { return _x; }
		int y() { return _y; }
};

