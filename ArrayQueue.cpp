#ifndef ARRAY_QUEUE_CPP_
#define ARRAY_QUEUE_CPP_

#include "ArrayQueue.h"


//ArrayQueue constructor initializes _size to parameter size and underlying array _data to hold Type and have _size size
template<class Type>
ArrayQueue<Type>::ArrayQueue(int size){
    _data = new Type[size];
    _size = 0;
}

//ArrayQueue destructor deletes underlying array _data
template<class Type>
ArrayQueue<Type>::~ArrayQueue(){
	_data = NULL;
}

//Returns if ArrayQueue is full
template<class Type>
bool ArrayQueue<Type>::is_full() const{
	return _size == _capacity;
}

//Returns if ArrayQueue is empty
template<class Type>
bool ArrayQueue<Type>::is_empty() const{
	return _size == 0;
}

//Returns element in front of queue. Throws logic_error if queue is empty.
template<class Type>
Type &ArrayQueue<Type>::peek() const{
	if(is_empty())
		throw new logic_error("Queue is empty");
	return _data[0];
}

//Adds item to back of queue
template<class Type>
bool ArrayQueue<Type>::enqueue(const Type &item){
	if (is_full())
		return false;
	_data[_size] = item;
	_size++;
	return true;
}

//Removes item from front of queue
template<class Type>
bool ArrayQueue<Type>::dequeue(){
	if (is_empty())
		return false;

	for (int i = 0; i < _size - 1; i++)
		_data[i] = _data[i+1];
    
	_size--;
	return true;
}

//Prints ArrayQueue contents in formatted fashion to console
template<class Type>
void ArrayQueue<Type>::print(){
	for (int index = 0; index < _size; index++)
		cout << _data[index] << endl;
}

#endif /* ARRAY_QUEUE_CPP_ */