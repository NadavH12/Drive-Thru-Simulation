//#ifndef SIMULATION_CPP_
//#define SIMULATION_CPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Vehicle.h"
#include "ArrayList.h"
#include "ArrayQueue.h"
#include "Simulation.h"
using namespace std;

Simulation::Simulation(string file_name){
     vehicles_queue = new ArrayQueue<Vehicle>(); 
     vehicles_list = new ArrayList<Vehicle>();
     current_time = 0;
     fstream myFile (file_name);
     string fileLine;
     if(myFile.is_open()){
          while(getline(myFile,fileLine)){
               string s = fileLine;
               istringstream iss(s);
               string name = "";
               string arrTime = "";
               string procTime = "";
               iss >> name;
               iss >> arrTime;
               iss >> procTime;
               int arrTimeInt = stoi(arrTime);
               int procTimeInt = stoi(procTime);
               Vehicle car = Vehicle(name, arrTimeInt, procTimeInt, current_time);
               vehicles_list->insert(car);
               
          }
          
          vehicles_list->sort();//////////////////////////
          current_time = -1;


          //cout << endl;
          //cout << "Vehicles list: " << endl;
          //vehicles_list->print();
          cout << endl;
     }
}

Simulation::~Simulation(){
	vehicles_queue = NULL;
     vehicles_list = NULL;
}

bool Simulation::done(){
     return current_time == 19;
}

void Simulation::step(){
     if(current_transaction.get_name() == "" && vehicles_queue->is_empty()){
          current_transaction = vehicles_list->get(vehicles_list->size()-1);
          vehicles_list->removeAt(vehicles_list->size()-1);
     }
     
     int nextCarArrivalTime = 0;
     
     if(vehicles_list->size() > 0){
          Vehicle nextCar = vehicles_list->get(vehicles_list->size()-1);
          nextCarArrivalTime = nextCar.get_arrival_time();
     }

     if(current_transaction.get_name() != "" && nextCarArrivalTime == current_time + 1 && vehicles_list->size() > 0){
          vehicles_queue->enqueue(vehicles_list->get(vehicles_list->size()-1));
          vehicles_list->removeAt(vehicles_list->size()-1);
     }
     
     if (vehicles_list->size() == 0){
          if((current_transaction.get_start_time() + current_transaction.get_processing_time()) == (current_time + 1)){
               if(!vehicles_queue->is_empty()){
                    current_transaction = vehicles_queue->peek();/////////////////
                    current_transaction.set_start_time(current_time + 1);
                    vehicles_queue->dequeue();
               } else {
                    current_transaction = Vehicle ("");
               }
          }

     }else{

          if((current_transaction.get_arrival_time() + current_transaction.get_processing_time()) == (current_time + 1)){
               current_transaction = vehicles_queue->peek();
               current_transaction.set_start_time(current_time + 1);
               vehicles_queue->dequeue();
          }
     }

     current_time++;
}

void Simulation::print()
{
	cout << "Time: " << current_time << endl;

	cout << "Queue:" << endl;
	if (!vehicles_queue->is_empty())
		vehicles_queue->print();
	else cout << "EMPTY" << endl;

	cout << "Transaction:" << endl;
	if (current_transaction.get_name() != "")
		cout << current_transaction << endl;
	else cout << "EMPTY" << endl;
}

//#endif /* SIMULATION_CPP_ */