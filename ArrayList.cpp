#ifndef ARRAY_LIST_CPP_
#define ARRAY_LIST_CPP_

#include "ArrayList.h"
#include "Vehicle.h"

//ArrayList constructor initializes _size to 0 and underlying array _data to hold type Type and be of size _capacity
template<class Type>
ArrayList<Type>::ArrayList(){
	_data = new Type[_capacity]();
	_size = 0;
}

//ArrayList destructor deletes underlying array _data
template<class Type>
ArrayList<Type>::~ArrayList(){
	_data = NULL;
}

//Getter function returns number of elements in ArrayList
template<class Type>
int ArrayList<Type>::size() const{
	return _size;
}

//Function creates new array with double capacity of old one,
//transfers all elements to new array, and deletes old array
//assigns new array to ArrayList field
template<class Type>
void ArrayList<Type>::expand()
{
	_capacity *= 2;
    Type *temp = new Type[_capacity];

    for (int i = 0; i < _size; i++)
        temp[i] = _data[i];

    delete []_data;
    _data = temp;
}









//Function inserts parameter item into ArrayList. If ArrayList
//needs resizing, function calls expand()
template<class Type>
void ArrayList<Type>::insert(const Type &item){
	if(_size == _capacity)
		expand();
	_data[_size] = item;
	_size++;
}











//Function removes item at specified index, shifts remaining elements downwards
template<class Type>
bool ArrayList<Type>::removeAt(int index){

	if(index >= 0 && index <_size){
		for(int i = index; i <_size; i++){
			_data[i] = _data[i+1];
		}
		_size--;
		return true;
	}
	return false;
}








//Performs a bubble sort on the ArrayList
template<class Type>
void ArrayList<Type>::sort(){
	//cout << endl;
	//cout << endl;
	//this->print();

	int j = 0;
	for(int i = 0; i < this->size(); i++){
          int minTime = 100;
          int nextCar = 0;
          for(j = i; j < this->size(); j++){
               Type& current = this->get(j);
			int arrTime = current.get_arrival_time();
               if (current.get_arrival_time() < minTime){
                    nextCar = j;
                    minTime = current.get_arrival_time();
               }   
		}
		Type car = this->get(nextCar);
          this->removeAt(nextCar);
		//cout << endl;
		//cout << endl;
		//this->print();
		this->insert(car);
		//cout << endl;
		//cout << endl;
		//this->print();
     }
}

//Returns ArrayList element at requested index
//Throws logic_error if requested index is out of bounds
template<class Type>
Type& ArrayList<Type>::get(int index) {
	if(index < 0 || index >= _size){
		throw logic_error("the index is out of bound");
	}
	return _data[index];
}

//Prints ArrayList contents in formatted fashion to console
template<class Type>
void ArrayList<Type>::print(){
	for (int index = 0; index < _size; index++)
		cout << _data[index] << endl;
}




/*int main(){
	ArrayList<int> list;
	for(int i = 0; i < 40; i++){
		list.insert(i);
	}
	list.print();

	return 0;
}*/







#endif /* ARRAY_LIST_CPP_ */


