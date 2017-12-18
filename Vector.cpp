#include "Vector.h"



const double PI = 3.14159265358979323846264338327950288419;
const double RADTODEG = 180 / PI;

//// private methods ////
// calculates magnitude from x_ and y_
void Vector::setMag()
{
	mag_ = std::sqrt(x_ * x_ + y_ * y_);
}

// set angle
void Vector::setAng()
{
	if (x_ == 0.0 && y_ == 0.0)
		ang_ = 0.0;
	else
		ang_ = atan2(y_, x_);
}

// set x from polar coords
void Vector::setX()
{
	x_ = mag_ * cos(ang_);
}

// set y from polar coords
void Vector::setY()
{
	y_ = mag_ * sin(ang_);
}


//// public methods ////

// default constructor
Vector::Vector()
{
	x_ = y_ = mag_ = ang_ = 0.0;
	mode_ = RECT;
}

// vector from rect coords if form is rect, else from polar coords
Vector::Vector(double n1, double n2, Mode form)
{
	mode_ = form;
	if (form == RECT)
	{
		x_ = n1;
		y_ = n2;
		setMag();
		setAng();
	}
	else if (form == POL)
	{
		mag_ = n1;
		ang_ = n1 / RADTODEG;
		setX();
		setY();
	}
	else
	{
		std::cout << "Incorrect 3rd argument on Vector() -- Vector set to 0\n";
		x_ = y_ = mag_ = ang_ = 0.0;
		mode_ = RECT;
	}
}

// reset vector from coords based on Mode
void Vector::reset(double n1, double n2, Mode form)
{
	mode_ = form;
	if (form == RECT)
	{
		x_ = n1;
		y_ = n2;
		setMag();
		setAng();
	}
	else if (form == POL)
	{
		mag_ = n1;
		ang_ = n1 / RADTODEG;
		setX();
		setY();
	}
	else
	{
		std::cout << "Incorrect 3rd argument on Vector() -- Vector set to 0\n";
		x_ = y_ = mag_ = ang_ = 0.0;
		mode_ = RECT;
	}
}

// destructor
Vector::~Vector()
{

}

// set to polar mode
void Vector::setPolar()
{
	mode_ = POL;
}

// set to rect mode
void Vector::setRect()
{
	mode_ = RECT;
}

//// operator overloading ////
// add two vectors
Vector Vector::operator + (const Vector& b) const
{
	return Vector(x_ + b.x_, y_ + b.y_);
}

// subtract two vectors
Vector Vector::operator - (const Vector& b) const
{
	return Vector(x_ - b.x_, y_ - b.y_);
}

// reverse positivity
Vector Vector::operator - () const
{
	return Vector(-x_, -y_);
}

// multiply vector by double
Vector Vector::operator * (double n) const
{
	return Vector(x_ * n, y_ * n);
}

//// friend functions ////
// multiply double by vector
Vector operator * (double n, const Vector& a)
{
	return a * n;
}

// output rectangular or polar coords based on Mode
std::ostream& operator << (std::ostream& os, const Vector& v)
{
	if (v.mode_ == Vector::RECT)
		os << "(x, y) = (" << v.x_ << ", " << v.y_ << ")";
	else if (v.mode_ == Vector::POL)
		os << "(m, a) = (" << v.mag_ << ", " << v.ang_ * RADTODEG << ")";
	else
		os << "Vector object is invalid";
	return os;
}
