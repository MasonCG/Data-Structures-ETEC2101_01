#pragma once

#include <iostream>

// linked_list.h

namespace ssuds
{
	/// <summary>
	/// Choosing to iterate through the list either forward or backwards
	/// </summary>
	enum class LinkedListIteratorDirection { FORWARD, BACKWARD };


	template <class T>
	/// <summary>
	/// list that uses pointers to connect nodes in order.
	/// </summary>
	class LinkedList
	{
		// IMPORTANT DESIGN CONSIDERATION: User shouldn't be able to see any Nodes!!
	private:
		/// <summary>
		///		Private Node class that is hidden and used to pass data in the linked list.
		/// </summary>
		class Node			// Each instance corresponds to an orange "box" in the slides
		{
		public:
			/// <summary>
			/// templated type that holds actual list data.
			/// </summary>
			T mData;
			/// <summary>
			/// Pointer to the next node in the list
			/// </summary>
			Node* mNext;
			/// <summary>
			/// pointer to the previous not in the list
			/// </summary>
			Node* mPrevious;
		};



		/// <summary>
		/// Pointer to the beginning node in the list
		/// </summary>
		Node* mStart;			// Sometimes called the "head"
		/// <summary>
		/// Pointer to the last node in the list
		/// </summary>
		Node* mEnd;				// Sometimes called the "tail"
		/// <summary>
		/// size of the list
		/// </summary>
		unsigned int mSize;

	public:

		/// <summary>
		///		Iterator for linkedLists
		/// </summary>
		class LinkedListIterator
		{
		private:
			/// <summary>
			/// pointer to the current node the list is seeking
			/// </summary>
			Node* mCurrentNode;
			/// <summary>
			/// Direction the list is going to be iterated
			/// </summary>
			LinkedListIteratorDirection mType;


		public:
			/// <summary>
			/// List Iterator Constructor:=========================================TODO
			/// </summary>
			LinkedListIterator(Node* cur, LinkedListIteratorDirection dir = LinkedListIteratorDirection::FORWARD)
			{
				mCurrentNode = cur;
				mType = dir;
			}

			/// <summary>
			/// allowing the parent and subclasses the ability to access private attributes and methods
			/// </summary>
			friend class LinkedList;


			/// <summary>
			///		overrides != operator compares self to given LinkedListIterator
			/// </summary>
			/// <param name="other">LinkedListIterator</param>
			/// <returns>boolean</returns>
			bool operator!=(const LinkedListIterator& other)
			{

				if (this->mCurrentNode->mNext == other.mCurrentNode->mNext) {
					if (this->mCurrentNode->mPrevious == other.mCurrentNode->mPrevious) {
						return false;
					}
				}

				return true;
			}

			/// <summary>
			///		gives back data at this "index" of the list
			/// </summary>
			/// <returns>List Data</returns>
			T& operator*()
			{
				return this->mCurrentNode->mData;
			}

			/// <summary>
			/// goes to the next node in the list or the previous node depending on mType
			/// </summary>
			/// <returns></returns>
			LinkedListIterator operator++()
			{
				if (mType == LinkedListIteratorDirection::FORWARD) {

					if (mCurrentNode->mNext == nullptr) {
						Node* e = new Node;
						e->mNext = nullptr;
						e->mPrevious = nullptr;
						e->mData = mCurrentNode->mData;
						mCurrentNode->mNext = e;
					}
					mCurrentNode = mCurrentNode->mNext;
				}
				else
					mCurrentNode = mCurrentNode->mPrevious;

				LinkedListIterator temp(mCurrentNode);
				return temp;

			}

			/// <summary>
			///		decremets the iterator as postfix x-- version
			/// </summary>
			/// <param name="not_used">int</param>
			/// <returns>LinkedListIterator</returns>
			LinkedListIterator operator--(int not_used)
			{
				LinkedListIterator temp(mCurrentNode);
				if (mType == LinkedListIteratorDirection::FORWARD) {

					if (mCurrentNode->mPrevious == nullptr) {
						Node* e = new Node;
						e->mNext = nullptr;
						e->mPrevious = nullptr;
						e->mData = mCurrentNode->mData;
						mCurrentNode->mPrevious = e;
					}
					mCurrentNode = mCurrentNode->mPrevious;
				}
				else
					mCurrentNode = mCurrentNode->mNext;

				return temp;

			}

			LinkedListIterator operator--()
			{
				if (mType == LinkedListIteratorDirection::FORWARD) {

					if (mCurrentNode->mPrevious == nullptr) {
						Node* e = new Node;
						e->mNext = nullptr;
						e->mPrevious = nullptr;
						e->mData = mCurrentNode->mData;
						mCurrentNode->mNext = e;
					}
					mCurrentNode = mCurrentNode->mPrevious;
				}
				else
					mCurrentNode = mCurrentNode->mNext;

				LinkedListIterator temp(mCurrentNode);
				return temp;

			}

			/// <summary>
			///		decrements the iterator as postfix x++ version
			/// </summary>
			/// <param name="not_used">int</param>
			/// <returns>LinkedListIterator</returns>
			LinkedListIterator operator++(int not_used)
			{
				LinkedListIterator temp(mCurrentNode);
				if (mType == LinkedListIteratorDirection::FORWARD) {

					if (mCurrentNode->mNext == nullptr) {
						Node* e = new Node;
						e->mNext = nullptr;
						e->mPrevious = nullptr;
						e->mData = mCurrentNode->mData;
						mCurrentNode->mNext = e;
					}
					mCurrentNode = mCurrentNode->mNext;
				}
				else
					mCurrentNode = mCurrentNode->mPrevious;

				return temp;

			}

			/// <summary>
			///		adds a given number and iterates to that many futher into the list
			/// </summary>
			/// <param name="num">unsigned int</param>
			/// <returns>LinkedListIterator</returns>
			LinkedListIterator operator+(unsigned int num)
			{
				if (mType == LinkedListIteratorDirection::FORWARD) {
					while (num--) {
						if (mCurrentNode->mNext == nullptr) {
							Node* e = new Node;
							e->mNext = nullptr;
							e->mPrevious = nullptr;
							e->mData = mCurrentNode->mData;
							mCurrentNode->mNext = e;
							break;
						}
						mCurrentNode = mCurrentNode->mNext;

					}
				}
				else
					while (num--) {
						if (mCurrentNode->mPrevious == nullptr)
							break;
						mCurrentNode = mCurrentNode->mPrevious;
					}

				LinkedListIterator temp(mCurrentNode);
				return temp;

			}

			/// <summary>
			///		subtracts a given number of spots into the Linked List
			/// </summary>
			/// <param name="num">unsigned int</param>
			/// <returns>LinkedListIterator</returns>
			LinkedListIterator operator-(unsigned int num)
			{
				if (mType == LinkedListIteratorDirection::FORWARD) {
					while (num--) {
						if (mCurrentNode->mPrevious == nullptr) {
							Node* e = new Node;
							e->mNext = nullptr;
							e->mPrevious = nullptr;
							e->mData = mCurrentNode->mData;
							mCurrentNode->mPrevious = e;
							break;
						}
						mCurrentNode = mCurrentNode->mPrevious;
					}
				}
				else
					while (num--) {
						if (mCurrentNode->mNext == nullptr)
							break;
						mCurrentNode = mCurrentNode->mPrevious;
					}

				LinkedListIterator temp(mCurrentNode);
				return temp;

			}

			/// <summary>
			/// compares iterator to another
			/// </summary>
			/// <param name="num"></param>
			/// <returns></returns>
			bool operator==(LinkedListIterator& other)
			{
				if (this->mCurrentNode->mNext == other.mCurrentNode->mNext) {
					if (this->mCurrentNode->mPrevious == other.mCurrentNode->mPrevious) {
						return true;
					}
				}

				return false;


			}

		};

		


		/// <summary>
		///		LinkkedList default Constructor
		///		sets all attributes to nullptr or 0
		/// </summary>
		LinkedList()
		{
			mStart = nullptr;
			mEnd = nullptr;
			mSize = 0;
		}

		/// <summary>
		///		copy-constructor used to copy another Linked list to a new one.
		/// </summary>
		/// <param name="other">LinkedList</param>
		LinkedList(LinkedList& other)
		{
			for (T val : other) {
				this->append(val);
			}
		}

		/// <summary>
		///		move-constructor creates a shallow copy to be passed when a function returns a LinkedList instance. 
		/// </summary>
		/// <param name="other">LinkedList&&</param>
		LinkedList(LinkedList&& other): mStart(other.mStart), mEnd(other.mEnd), mSize(other.mSize)
		{
			other.mSize = 0;
			other.mStart = nullptr;
			other.mEnd = nullptr;
		}

		/// <summary>
		/// Initializer-list constructor
		/// </summary>
		/// <param name="ilist">std::initializer_list<T></param>
		LinkedList(std::initializer_list<T> ilist)
		{
			for (T val : ilist) {
				this->append(val);
			}
		}

		/// <summary>
		/// adds a new node to the end of the list
		/// </summary>
		/// <param name="val">T value</param>
		void append(const T& val)
		{

			if (mSize == 0)
			{
				// Case1: list is empty
				// a. Make a new Node
				// b. Make mStart and mEnd point to it.
				Node* new_node = new Node;
				mStart = mEnd = new_node;			// Maybe add a constructor to Node??
				new_node->mData = val;	            // Initializing the new node (could've
				new_node->mNext = nullptr;          //    referred to mEnd -- it's the same node!)
				new_node->mPrevious = nullptr;
			}
			else
			{
				// Case2: list has data in it
				Node* new_node = new Node;
				new_node->mData = val;	            // Initializing the new node (could've
				new_node->mNext = nullptr;          //    referred to mEnd -- it's the same node!)
				new_node->mPrevious = nullptr;
				// Make the current last node point to this new one
				mEnd->mNext = new_node;
				// Make the new node point to the *CURRENT* end node
				new_node->mPrevious = mEnd;
				// Make the new node THE last node
				mEnd = new_node;
			}
			// Increase size
			mSize++;
		}

		void prepend(const T& val)
		{

			if (mSize == 0)
			{
				// Case1: list is empty
				// a. Make a new Node
				// b. Make mStart and mEnd point to it.
				Node* new_node = new Node;
				mStart = mEnd = new_node;			// Maybe add a constructor to Node??
				new_node->mData = val;	            // Initializing the new node (could've
				new_node->mNext = nullptr;          //    referred to mEnd -- it's the same node!)
				new_node->mPrevious = nullptr;
			}
			else
			{
				// Case2: list has data in it
				Node* new_node = new Node;
				new_node->mData = val;	            // Initializing the new node (could've
				new_node->mNext = mStart;
				mStart->mPrevious = new_node;
				//    referred to mEnd -- it's the same node!)
				// Make the current last node point to this new one
				// Make the new node point to the *CURRENT* end node
				new_node->mPrevious = nullptr;
				// Make the new node THE last node
				mStart = new_node;
			}
			// Increase size
			mSize++;
		}

		/// <summary>
		///		gives current size of the list
		/// </summary>
		/// <returns>integer</returns>
		unsigned int size() const
		{
			return mSize;
		}

		/// <summary>
		///		creates an ostream for the list so that it can be printed, saved, and tested
		/// </summary>
		/// <param name="os">ostream</param>
		void output(std::ostream& os)
		{
			// Output in python-list style output: [A, B, C, D, E].  This pattern
			// is called ITERATING (not iterator) through all the nodes -- very
			// common pattern in the linked list.
			os << "[";
			Node* cur_node = mStart;		// Might be nullptr!!
			for (unsigned int i = 0; i < mSize; i++)
			{
				//os << mData[i];		// Not a thing here!!!
				os << cur_node->mData;
				cur_node = cur_node->mNext;
				if (i < mSize - 1)
					os << ", ";
			}
			os << "]";
		}

		/// <summary>
		/// allows list to be printed by simply passing the name
		/// </summary>
		/// <param name="os">ostream</param>
		/// <param name="aList">LinkedList</param>
		/// <returns>ostrem</returns>
		friend std::ostream& operator <<(std::ostream& os, LinkedList& lList)
		{
			lList.output(os);
			return os;
		}

		LinkedList& operator =(LinkedList& other) {
			for (T val : other) {
				this->append(val);
			}

			return *this;
		}

		/// <summary>
		/// overrides bracket [] operator
		/// </summary>
		/// <param name="index">unsigned int</param>
		/// <returns>T value/data</returns>
		T& operator[](unsigned int index)
		{
			// 1. Check index to see if it's valid -- if not raise std::out_of_range exception
			if (index > mSize - 1 || index < 0) {
				throw std::out_of_range(index + "is out of range");
			}
			// 2. Loop to the proper spot (using the iteration pattern on slide 8)
			// 3. Return the data of that current node.
			// (maybe a few bonus points if you pick the "smart" side of the linked list to
			//   

			Node* cur = mStart;
			unsigned int indexxing = 0;

			while (cur) {
				if (indexxing == index) {
					return cur->mData;
				}

				indexxing++;
				cur = cur->mNext;
			}

		}

		/// <summary>
		///		adds a node the list at the given index
		/// </summary>
		/// <param name="new_val">T value/data</param>
		/// <param name="index">unsigned int</param>
		/// 
		
		void insert(const T& new_val, unsigned int index)
		{
			// 1. Check index to see if it's valid -- if not raise std::out_of_range exception
			if (index > mSize || index < 0) {
				throw std::out_of_range(index + "is out of range");
			}
			//      I allowed index == mSize here and just did an append (and return)
			if (index == mSize) {
				this->append(new_val);
				return;
			}
			//      if index == 0, just call prepend (and return)
			if (index == 0) {
				this->prepend(new_val);
				return;
			}
			// 2. Navigate to the current node at the given index (called cur_node)
			Node* cur_node = mStart;

			for (int i = 0; i < index; i++) {
				cur_node = cur_node->mNext;
			}

			// 3. Create a new node and make changes.
			Node* new_node = new Node;
			new_node->mData = new_val;
			new_node->mNext = cur_node;
			new_node->mPrevious = cur_node->mPrevious;
			new_node->mPrevious->mNext = new_node;
			cur_node->mPrevious = new_node;
			
			// 5. Increase size
			mSize++;

		}

		

		/// <summary>
		///		gives an LinkedListIterator that points to the beginning of the list
		/// </summary>
		/// <returns>LinkedListIterator</returns>
		LinkedListIterator begin()
		{
			return LinkedListIterator(mStart);
		}

		/// <summary>
		///		gives a special LinkedListIterator that signals you have reached the end of the list
		/// </summary>
		/// <returns></returns>
		LinkedListIterator end()
		{			
			Node* e = new Node;
			e->mNext = nullptr;
			e->mPrevious = nullptr;
			e->mData = mEnd->mData;
			LinkedListIterator temp(e);
			return temp;
		}

		/// <summary>
		/// finds value at the given index
		/// </summary>
		/// <param name="value">T&</param>
		unsigned int find(const T& val, unsigned int starting_index = 0) {

			Node* cur = mStart;

			for (int i = starting_index; i < mSize; i++) {
				if (cur->mData == val) {
					return i;
				}
				cur = cur->mNext;
			}

			return -1;

		}

		/// <summary>
		/// finds value based on given LinkedList iteration0
		/// </summary>
		/// <param name="it">LinkedListIterator&</param>
		LinkedListIterator find(const T& val, LinkedListIterator starting_it) {

			Node* cur = starting_it.mCurrentNode;
			while (cur) {
				if (cur->mData == val) {
					LinkedListIterator temp(cur);
					return temp;
				}
				cur = cur->mNext;
			}

			return this->end();

		}

		/// <summary>
		///		finds node at given index
		/// </summary>
		/// <returns></returns>
		T& at(unsigned int index) {
			return (*this)[index];
		}

		/// <summary>
		/// removes Node at given index
		/// </summary>
		/// <param name="index">unsigned integer</param>
		void remove(unsigned int index) {
			// 1. raise exception is out of index range
			if (index < 0 || index > mSize - 1) {
				throw std::out_of_range(index + "is out range");
			}

			
			Node* cur = mStart;

			// special exceptions
			if (index == 0) {
				cur->mNext->mPrevious = nullptr;
				mStart = cur->mNext;
				delete[] cur;
				mSize--;
				return;
			}

			if (index == mSize - 1) {
				cur = mEnd;
				cur->mPrevious->mNext = nullptr;
				mEnd = cur->mPrevious;
				delete[] cur;
				mSize--;
				return;
			}
			// 2. find Node at the given index
			

			while (cur) {
				if (index == 0)
					break;
				index--;
				cur = cur->mNext;
			}

			// 3. delete Node and fix mNext & mPrevious links
			cur->mNext->mPrevious = cur->mPrevious;
			cur->mPrevious->mNext = cur->mNext;

			mSize--;
			delete[] cur;

		
		}

		/// <summary>
		/// removes Node at given Iteration
		/// </summary>
		/// <param name="it"></param>
		void remove(LinkedListIterator& it) {
			
			
			Node* cur = it.mCurrentNode;

			if (cur == mStart) {
				cur->mNext->mPrevious = nullptr;
				mStart = cur->mNext;
				it.mCurrentNode = mStart;


			} else if (cur == mEnd) {
				cur->mPrevious->mNext = nullptr;
				mEnd = cur->mPrevious;
				it.mCurrentNode->mNext;
			}
			else {
				it.mCurrentNode = cur->mNext;
				cur->mNext->mPrevious = cur->mPrevious;
				cur->mPrevious->mNext = cur->mNext;
			}

			mSize--;
			delete[] cur;
			return;

		}

		/// <summary>
		/// removes all instances of given value
		/// </summary>
		/// <param name="val">T&</param>
		/// <returns>unsigned intege -> of instances removed</returns>
		unsigned int remove_all(const T& val) {

			Node* cur = mStart;
			unsigned int removed = 0;
			while (cur) {
				if (cur->mData == val) {
					if (cur->mNext == nullptr) {
						cur->mPrevious->mNext = nullptr;
						mEnd = cur->mPrevious;
					}
					else if (cur->mPrevious == nullptr) {

						cur->mNext->mPrevious = nullptr;
						mStart = cur->mNext;
					}
					else {
						cur->mNext->mPrevious = cur->mPrevious;
						cur->mPrevious->mNext = cur->mNext;
					}
					mSize--;
					removed++;
				}
				cur = cur->mNext;
			}
			delete[] cur;
			return removed;


		}


		~LinkedList() {

			Node* cur = mStart;

			while (cur != nullptr) {
				if (cur->mNext == nullptr) {
					cur = cur->mNext;
					continue;
				}
				cur = cur->mNext;

				delete[] cur->mPrevious;
			}

		}

	};

	

}
