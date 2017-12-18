#pragma once
#include <iostream>
class Vector
{
public:
	enum Mode { RECT, POL };
private:
	double x_; // horizontal value
	double y_; // vertical value
	double mag_; // length of vector
	double ang_; // direction of vector in degrees
	Mode mode_; // RECT or POL
	// methods for setting values //
	void setMag();
	void setAng();
	void setX();
	void setY();
public:
	Vector();
	Vector(double n1, double n2, Mode form = RECT);
	void reset(double n1, double n2, Mode form = RECT);
	~Vector();
	// getters //
	double getX() const { return x_; }
	double getY() const { return y_; }
	double getMag() const { return mag_; }
	double getAng() const { return ang_; }
	// setters //
	void setPolar();
	void setRect();
	// operator overloading //
	Vector operator + (const Vector& b) const;
	Vector operator - (const Vector& b) const;
	Vector operator - () const;
	Vector operator * (double n) const;
	// friends //
	friend Vector operator * (double n, const Vector& a);
	friend std::ostream& operator << (std::ostream& os, const Vector& v);
};

