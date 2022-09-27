// Honor Pledge:

//

// I pledge that I have neither given nor

// received any help on this assignment.

//

// nmmonroe

#include <iostream>
#include <fstream>
#include <sstream>
#include "Car.h"

void simulateRace(Car lineup[]); //Function decleration
int main()
{
	int count(1), i(0), sint(0), cint(0);
	std::string n(""),sstr(""),cstr("");
	Car car[33]; //Declaring Car array of cars
	std::ifstream input("indy500.txt");
	
	if(input.is_open())
	{
		while(!input.eof() )
		{
			if(count%3==1) //Count used to keep order is always name, speed, control
			{
				getline(input, n, ' '); //Space delimiter to get to speed
				car[i].setName(n);
			}
			else if(count%3==2)
			{
				std::stringstream ss;
				getline(input, sstr, ' '); //Space delimiter to get to control
				
				ss<<sstr; //Stringstream to convert control from string to int
				ss>>sint;
				
				car[i].setSpeed(sint);
			}
			else if(count%3==0)
			{
				std::stringstream ss;
				getline(input, cstr); //No delimiter to go to next line
				
				ss<<cstr; //Stringstream to convert control from string to int
				ss>>cint;
				
				car[i].setControl(cint);
				car[i].setLap(0);
				
				i++; //Moves forward to the next car after inputting 3 attributes
			}
			else
			{
				std::cout<<"oops";
			}
			
			count++;
		}
		input.close();
		
		simulateRace(car); 
		
	}
	else //Contingency
	{
		std::cout<<"Unable to open file... oops..."<<std::endl;
	}
}

void simulateRace(Car lineup[])
{	
	std::cout << "*** Welcome to the simulated Indy 500!! (Woooohooo) ***" << std::endl;
	std::cout << "Ladies and gentlemen... START YOUR ENGINES!"<<std::endl<<std::endl;
	
	
	int x(0), r, win(0), lead(0), dif(0); 
	double adv(0), cl(0);
	
	srand((unsigned) time(0));
	
	while(win<=200)
	{
		for(int i=0; i<33; i++) // Loop to advance the racers
		{
			if(lineup[i].getControl()>5) //Adds control bonus
			{
				r=(rand() % 10)+1;
				adv=lineup[i].getControl()/r;
				adv+=lineup[i].getSpeed();
			}
			else
			{
				adv=lineup[i].getSpeed();
			}
	
			cl=lineup[i].getLap();
			lineup[i].setLap(cl+adv);
		}
		
		for(int j=0;j<33;j++) //Finds the current leader after each iteration of advancement loop
		{
			if(lineup[j].getLap()>win)
			{
				win=lineup[j].getLap(); //Win checks laps
				lead=j; //Lead stores current leader until they finish
			}
		}
	}
	
	if(lineup[lead].getLap()>200) //In case race winner finishes with more than 200
	{
		dif=lineup[lead].getLap()-200;
		
		for(int k=0; k<33; k++)
		{
			int n(0);
			
			n=lineup[k].getLap();
			lineup[k].setLap(n-dif);
		}
	}
	else
	{
		//blank
	}
	
	std::cout<< std::endl << lineup[lead].getName() << " WINS the 2022 INDY 500!! " << std::endl << std::endl;
	
	std::cout<< "Driver Name: Lap Number" << std::endl << "***********************" << std::endl;
	
	for(int i=0;i<33;i++) //Outputs list of racers and the lap they finished on
	{
		std::cout << lineup[i].getName() << ": " << lineup[i].getLap() << std::endl;
	}
	
	std::cout<< std::endl << "Thank you for simulating the Indy 500 with me! Until next time!" << std::endl;
}
