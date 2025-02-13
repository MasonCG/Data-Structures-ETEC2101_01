#pragma once

#include <iostream>
#include <ostream>

/// <summary>
/// namespace for all examples in Data Structures
/// </summary>
namespace ssuds {


	template <class T>
	/// <summary>
	/// Makes an array of any given type
	/// </summary>
	class ArrayList {
	private:
		/// <summary>
		/// pointer to beginning of the array
		/// </summary>
		T* myArray;
		/// <summary>
		/// number of instances in the array
		/// </summary>
		unsigned int myArraySize;
		/// <summary>
		/// capacity of the array - how many instances could fit
		/// </summary>
		unsigned int myArrayCapacity;
		


	public:
		/// <summary>
		/// creates array of given type
		/// </summary>
		/// <param name="type">class or data type of array</param>
		ArrayList() {
			myArray = nullptr;
			myArraySize = 0;
			myArrayCapacity = 2;
		}
		/// <summary>
		/// create and array list with an assigned capacity
		/// </summary>
		/// <param name="capacity">number of items that can fit inside the array.</param>
		ArrayList(unsigned int capacity) {
			myArray = nullptr;
			myArraySize = 0;
			myArrayCapacity = capacity;

		}

		/// <summary>
		/// add new instance to end of the array
		/// </summary>
		/// <param name="item">object instance being added to array</param>
		void append(const T& item) {

			if (!myArray) {
				myArray = new T[myArrayCapacity];
				myArray[0] = item;
				myArraySize++;
			}

			else {
				// doubling capacity of array
				if (myArraySize == myArrayCapacity) {
					myArrayCapacity *= 2;

					// creating temporary array
					T* tempArray = new T[myArrayCapacity];

					// copying myArray to tempArray
					for (unsigned int i = 0; i < myArraySize; i++) {
						tempArray[i] = myArray[i];
					}

					// adding item to end of array
					tempArray[myArraySize] = item;
					

					// freeing old array from memory
					delete[] myArray;
					// copying tempArray to MyArray
					myArray = tempArray;
				}

				else {
					myArray[myArraySize] = item;
				}

				// increasing size of array
				myArraySize++;
				
			}
		}
		/// <summary>
		/// adds a new instance to the beginning of the array
		/// </summary>
		/// <param name="item">object anstance being added to array</param>
		void prepend(const T& item) {
			if (!myArray) {
				myArray = new T[myArrayCapacity];
				myArray[0] = item;
				myArraySize++;
			}

			else {
				// doubling capacity of array
				if (myArraySize == myArrayCapacity) {
					myArrayCapacity *= 2;

					// creating temporary array
					T* tempArray = new T[myArrayCapacity];

					// copying myArray to tempArray in reverse
					for (unsigned int i = myArraySize; i > 0; i--) {
						tempArray[i] = myArray[i - 1];
					}

					// add item to beginning of the array
					tempArray[0] = item;

					delete[] myArray;
					myArray = tempArray;
				}

				else {
					for (unsigned int i = myArraySize; i > 0; i--) {
						myArray[i] = myArray[i - 1];
					}
					
					myArray[0] = item;
				}
			
			
				myArraySize++;

			
			}



		}
		/// <summary>
		/// inserts given item at given index of the array
		/// </summary>
		/// <param name="item">item being added to array</param>
		/// <param name="index">index of the array item is being added to</param>
		void insert(const T& item, int index) {			
			
			if (index < 0 || index > myArraySize - 1) {
				throw std::out_of_range("index is not in range");
			}

			if (index == 0) {
				prepend(item);
				return;
			}

			if (index == myArraySize) {
				append(item);
				return;
			}
			

			if (myArraySize == myArrayCapacity) {
				myArrayCapacity *= 2;
			
				T* temp_array = new T[myArrayCapacity];

				unsigned int currentIndex = 0;
				for (unsigned int i = 0; i < myArraySize; i++) {
					if (i == index) {
						temp_array[i] = item;
						continue;
					}

					temp_array[i] = myArray[currentIndex];
					currentIndex++;
				}
			
				
			}

			else {
				for (unsigned int i = myArraySize; i > index; i--) {
					myArray[i] = myArray[i - 1];
				}

				myArray[index] = item;
			}

			myArraySize++;

		}
		/// <summary>
		/// removes item from array at given index
		/// </summary>
		/// <param name="index">index of item being removed</param>
		void remove(int index) {

			if (index < 0 || index > myArraySize - 1) {
				throw std::out_of_range("index is not in range");
			}
			
			if (myArraySize * 4 < myArrayCapacity) {
				myArrayCapacity /= 2;


				T* tempArray = new T[myArrayCapacity];
				unsigned int currentIndex = 0;
				for (unsigned int i = 0; i < myArraySize; i++) {
					if (i == index) {
						continue;
					}
					tempArray[currentIndex] = myArray[i];
					currentIndex++;
				}

				delete[] myArray;
				myArray = tempArray;

			}

			else {
				for (unsigned int i = index; i < myArraySize; i++) {

					myArray[i] = myArray[i+1];
				}
			}

			myArraySize--;
			
		}

		/// <summary>
		/// remove all occurrences of the same value
		/// </summary>
		/// <param name="item">value of items being removed</param>
		/// <returns>number of occurrences that were removed</returns>
		int remove_all(const T& item) {

			int removed = 0;
			for (unsigned int i = 0; i < myArraySize; i++) {

				if (myArray[i] == item) {
					remove(i);
					removed++;
					i--;
				}

				

			}
			return removed;

		}


		/// <summary>
		/// looks for an item at given index and returns a reference to the item.
		/// </summary>
		/// <param name="index">index of desired item</param>
		/// <returns>reference to desired item</returns>
		T& at(int index) {

			if (index < 0 || index > myArraySize - 1) {
				throw std::out_of_range("index is not in range");
			}

			return myArray[index];
			
		}
		/// <summary>
		/// finds the index of the given reference value
		/// </summary>
		/// <param name="valueRef">reference to a value</param>
		/// <returns>index of value in the array</returns>
		int find(const T& valueRef) {

			for (unsigned int i = 0; i < myArraySize; i++) {
				if (myArray[i] == valueRef) {
					return i;
				}
			}

			return -1;


		}
		/// <summary>
		/// gets number of instances in array
		/// </summary>
		/// <returns>number of instances in array</returns>
		int size() {
			return myArraySize;
		}
		/// <summary>
		/// gets the capacity of the array
		/// </summary>
		/// <returns>size of array</returns>
		int capacity() {
			return myArrayCapacity;
		}
		/// <summary>
		///		resises array to a desired capactiy.
		/// </summary>
		/// <param name="newCapacity">new desired size of array</param>
		void reserve(int newCapacity) {

			if (newCapacity < myArraySize) {
				throw std::exception("you are attempting to make your array smaller than the amount of items it contains");
			}

			myArrayCapacity = newCapacity;

			T* tempArray = new T[myArrayCapacity];
			for (unsigned int i = 0; i < myArraySize; i++) {
				tempArray[i] = myArray[i];
			}

			delete[] myArray;
			myArray = tempArray;

		}
		/// <summary>
		/// creates output to an ostream
		/// </summary>
		/// <param name="os">std::ostream to write to</param>
		void output(std::ostream& os) {
			os << "[";
			


			for (unsigned int i = 0; i < myArraySize; i++) {
				os << myArray[i];

				if (i < myArraySize - 1) {
					os << ", ";
				}
			}

			os << "]";
		}
		/// <summary>
		/// freeing all the memory and destroying array
		/// </summary>
		~ArrayList() {
			delete[] myArray;
		}




	};


}

