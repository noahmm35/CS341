// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include <iostream>
#include <string>

class Car
{
	public:
		Car();
		Car(std::string name, int speed, int control, int lap);
		
		~Car();
		
		std::string getName();
		void setName(std::string name);
		int getSpeed();
		void setSpeed(int speed);
		int getControl();
		void setControl(int control);
		void printInfo();
		int getLap();
		void setLap(int lap);
		
	private:
		std::string name_;
		int speed_;
		int control_;
		int lap_;
};
