// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include "Car.h"

Car::Car()
{
	
}

Car::Car(std::string name, int speed, int control, int lap) : name_(""), speed_(0), control_(0), lap_(0)
{
	name_=name;
	speed_=speed;
	control_=control;
	lap_=lap;
}

Car::~Car()
{

}

void Car::setName(std::string name)
{
	name_=name;
}

std::string Car::getName()
{
	return name_;
}

void Car::setSpeed(int speed)
{
	speed_=speed;
}

int Car::getSpeed()
{
	return speed_;
}

void Car::setControl(int control)
{
	control_=control;
}

int Car::getControl()
{
	return control_;
}

void Car::printInfo()
{
	std::cout << name_ << " " << speed_ << " " << control_ << std::endl;
}

int Car::getLap()
{
	return lap_;
}

void Car::setLap(int lap)
{
	lap_=lap;
}