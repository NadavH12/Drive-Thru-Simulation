#ifndef VEHICLE_CPP_
#define VEHICLE_CPP_
#include "Vehicle.h"

//Constructor for Vehicle object. Includes default parameters. Default parameters are empty string for string and 0 for int. Throws invalid_argument for any int input < 0
Vehicle::Vehicle(string name, int arrival_time, int processing_time, int start_time){
	if (arrival_time < 0 || processing_time < 0 || start_time < 0)
		throw new invalid_argument("Negative value assigned for time value");
	_name = name;
     _arrival_time = arrival_time;
     _processing_time = processing_time;
     _start_time = start_time;
}

//Getter method for _name field
string Vehicle::get_name(){
	return _name;
}

//Getter method for _arrival_time field
int Vehicle::get_arrival_time(){
	return _arrival_time;
}

//Getter method for _processing_time field
int Vehicle::get_processing_time(){
	return _processing_time;
}

//Getter method for _start_time field
int Vehicle::get_start_time(){
	return _start_time;
}

//Setter method for _start_time field
void Vehicle::set_start_time(int start_time){
	_start_time = start_time;
}

//Operator overloading for < operator. Implementation compares _arrival_time field. Used to prioritize customers.
bool Vehicle::operator< (const Vehicle& rhs){
	return this->_arrival_time < rhs._arrival_time;
}

//Operater overloading for << extraction operator.
ostream &operator<<(ostream &out, const Vehicle &that){
	out << "vehicle: { ";
	out << "name: " << that._name << ", ";
	out << "arrival_time: " << that._arrival_time << ", ";
	out << "processing_time: " << that._processing_time << ", ";
	out << "start_time: " << that._start_time << " }";

	return out;
}



#endif /* VEHICLE_CPP_ */