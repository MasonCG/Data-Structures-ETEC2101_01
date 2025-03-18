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
			
			if (index < 0 || index > myArraySize) {
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
				unsigned int current_index = 0;
				for (unsigned int i = 0; i < myArraySize + 1; i++) {
					if (i == index) {
						temp_array[i] = item;
						continue;
					}

					temp_array[i] = myArray[current_index];
					current_index++;
				}
			
				delete[] myArray;
				myArray = temp_array;
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
		unsigned int size() {
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
		/// overload the << operator for easy printing.
		/// </summary>
		/// <param name="os">ostream reference</param>
		/// <param name="A">ArrayList reference</param>
		/// <returns>ostream</returns>
		friend std::ostream& operator << (std::ostream& os, const ArrayList& A) {
			os << "[";

			for (unsigned int i = 0; i < A.myArraySize; i++) {
				os << A.myArray[i];

				if (i < A.myArraySize - 1) {
					os << ", ";
				}
			}

			os << "]";


			return os;
		}



		/// <summary>
		/// freeing all the memory and destroying array
		/// </summary>
		~ArrayList() {
			delete[] myArray;
		}

		/// <summary>
		/// An iterator that keeps track of its position or index within a the parent class ArrayList and a pointer to the specific ArrayList it is traversing.
		/// </summary>
		class ArrayListIterator {

		private:
			ArrayList* list;
			int pos;

		public:

			/// <summary>
			/// default constructor. Assigns list = nullptr and pos = 0
			/// </summary>
			ArrayListIterator() {
				list = nullptr;
				pos = 0;
			}

			/// <summary>
			/// specific constructor for ArrayListIterator. list = ArrayListPtr and pos = starting_index
			/// </summary>
			/// <param name="arrayList">pointer to given ArrayList</param>
			/// <param name="starting_index">integer of start index</param>
			ArrayListIterator(ArrayList* arrayListPtr, int starting_index) {
				list = arrayListPtr;
				pos = starting_index;
			}

			/// <summary>
			/// A copy constructor. Creates a copy by transferring other's attributes to a new ArrayListIterator.
			/// </summary>
			/// <param name="other">ArrayListIterator reference</param>
			ArrayListIterator(const ArrayListIterator& other) {
				list = other.list;
				pos = other.pos;
			}

			/// <summary>
			/// overload dereference * operator. Returns the object in the ArrayList at the index held by pos attribute. 
			/// Like ArrayList[pos]
			/// </summary>
			/// <returns>object or value in ArrayList</returns>
			T& operator*() {
				return list->at(pos);
			}


			ArrayListIterator operator++(int not_used) {
				int tempPos = pos + not_used;
				if (tempPos == list->size() || tempPos == -1) {
					tempPos = -1;
				}

				ArrayListIterator temp(list, tempPos);

				return temp;
			}


			/// <summary>
			/// overload ++ operator. Increments the pos attribute.
			/// </summary>
			/// <returns>ArrayListIterator</returns>
			ArrayListIterator operator++() {
				
				pos++;
				if (pos == list->size() || pos == -1) {
					pos = -1;
				}

				return *this;

			}
			
			


			/// <summary>
			/// overload == operator. It compares the pos attributes of the give ArrayListIterators.
			/// </summary>
			/// <param name="other">ArrayListIterator reference</param>
			/// <returns>Boolean</returns>
			bool operator==(const ArrayListIterator& other) {

				if (pos == other.pos) {
					return true;
				}

				return false;

			}

			/// <summary>
			/// overload NOT True != operator. It compares the pos attributes of the given ArrayListIterators.
			/// </summary>
			/// <param name="other">ArrayListIterator Reference</param>
			/// <returns>Boolean</returns>
			bool operator!=(const ArrayListIterator& other) {
				if (pos != other.pos) {
					return true;
				}
				return false;
			}

			/// <summary>
			/// over load the addition + operator to add to the pos attribute within the ArrayListIterator
			/// </summary>
			/// <param name="other">integer</param>
			/// <returns>ArrayListIterator</returns>
			ArrayListIterator operator+ (int other) {

				pos += other;

				if (pos >= list->size()) {
					pos = list->size() - 1;
				}

				if (pos < 0) {
					pos = 0;
				}

				return *this;

			}

			/// <summary>
			/// overload the = operator to copy or assign a new iterator
			/// </summary>
			/// <param name="other">reference to an ArrayListIterator</param>
			/// <returns>ArrayListIterator with other's attributes</returns>
			ArrayListIterator operator= (const ArrayListIterator& other) {
				ArrayListIterator temp(other.list, other.pos);
				return temp;
			}

			/// <summary>
			/// no special destructor
			/// </summary>
			~ArrayListIterator() {

			}
		
		
		};

		/// <summary>
		/// change the [] operator to return the value by index
		/// </summary>
		/// <param name="index">index of the desired object within an ArrayList object</param>
		/// <returns></returns>
		T& operator[](int index) {
			int tempIndex = index;
			
			if (tempIndex >= myArraySize) {
				tempIndex = myArraySize - 1;
			}

			if (tempIndex < 0) {
				tempIndex = 0;
			}

			return this->at(tempIndex);







		}

		/// <summary>
		/// gets the beginning iterator
		/// </summary>
		/// <returns>ArrayListIterator with a pos of 0</returns>
		ArrayListIterator begin() {
			ArrayListIterator temp(this, 0);
			return temp;
		}
		/// <summary>
		/// gets the ending iterator
		/// </summary>
		/// <returns>ArrayListIterator with a pos of -1. This signifies it as the null or end of the ArrayList</returns>
		ArrayListIterator end() {
			ArrayListIterator temp(this, -1);
			return temp;
		}
		
	};


}

