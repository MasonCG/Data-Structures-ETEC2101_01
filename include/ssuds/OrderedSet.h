#pragma once

#include <arrayLists.h>
namespace ssuds
{
	enum class OrderedSetTraversalOrder{ PRE, POST, INORDER};

	template <class T>
	/// <summary>
	/// arranges data in a tree from left to right according to the data given. 
	/// </summary>
	class OrderedSet
	{
	private:
		/// <summary>
		/// Subclass of Ordered Set the holds the values and pointers to other Nodes in the set.
		/// </summary>
		class Node
		{
		private:
			/// <summary>
			/// holds data given to the ordered set
			/// </summary>
			T mData;
			/// <summary>
			/// holds pointer to a child Node to the left. 
			/// </summary>
			Node* mLeft;
			/// <summary>
			/// holds pointer to a child Node to the right. 
			/// </summary>
			Node* mRight;

		public:
			/// <summary>
			/// default contstructor.
			/// </summary>
			/// <param name="data">const T&</param>
			/// <param name="left">Node* pointer</param>
			/// <param name="right">Node* pointer</param>
			Node(const T& data, Node* left = nullptr, Node* right = nullptr) : mData(data), mLeft(nullptr),
				mRight(nullptr)
			{
				// intentionally empty
			}

			friend class OrderedSet;

			/// <summary>
			///		recursive function used to insert a new value into the ordered set
			/// </summary>
			/// <param name="new_val">const T&</param>
			/// <returns>bool</returns>
			bool insert_recursive(const T& new_val)
			{
				if (new_val == mData)
					return false;			// It's a duplicate -- stop!
				else if (new_val < mData)
				{
					// This should go to my left
					if (mLeft == nullptr)
					{
						// I don't have a left-child -- make a new node that BECOMES the left child.
						mLeft = new Node(new_val);
						return true;
					}
					else
					{
						// I DO have a left child
						mLeft->insert_recursive(new_val);
					}
				}
				else
				{
					if (mRight == nullptr)
					{
						// I don't have a left-child -- make a new node that BECOMES the left child.
						mRight = new Node(new_val);
						return true;
					}
					else
					{
						// I DO have a left child
						mRight->insert_recursive(new_val);
					}
				}
			}

			/// <summary>
			///		recursive function that looks through the ordered set to see if it contains the given value.
			/// </summary>
			/// <param name="val">const T&</param>
			/// <returns>bool</returns>
			bool contains_recursive(const T& val) const
			{
				if (mData == val) {
					return true;
				}

				if (val < mData) {
					if (mLeft == nullptr) {
						return false;
					}
					mLeft->contains_recursive(val);
				}
				else if (val > mData) {
					if (mRight == nullptr) {
						return false;
					}
					mRight->contains_recursive(val);
				}

			}

			/// <summary>
			///		recursive function used to traverse the set and clear all of its nodes
			/// </summary>
			void clear_recursive() {

				if (mLeft != nullptr) {
					mLeft->clear_recursive();
				}

				if (mRight != nullptr) {
					mRight->clear_recursive();
				}

				delete[] this;
				return;
			}

			/// <summary>
			///		traverses the ordered set to find the height. 
			/// </summary>
			/// <returns>unsigned int</returns>
			unsigned int height_recursive(unsigned int h) {

				unsigned int height = h + 1;

				unsigned int leftHeight = 0;
				unsigned int rightHeight = 0;


				if (mLeft != nullptr) {
					leftHeight = mLeft->height_recursive(h);
				}

				if (mRight != nullptr) {
					rightHeight = mRight->height_recursive(h);
				}

				if (leftHeight == rightHeight) {
					return height;
				}

				if (leftHeight > rightHeight) {
					height += leftHeight;
				}
				else {
					height += rightHeight;
				}

				return height;
			}

			/// <summary>
			///		traverses through Ordered Set to find the parent of the given value.
			/// </summary>
			/// <param name="val">const T&</param>
			/// <returns>Node pointer</returns>
			Node* parent_recursive(const T& val) {

				Node* parent = this;

				if (mData == val) {
					return this;
				}

				//checking if LEFT nulltr and if parent
				if (mLeft != nullptr && mLeft->mData == val) {
					return parent;
				}

				//checking if RIGHT nullptr and if parent
				if (mRight != nullptr && mRight->mData == val) {
					return parent;
				}

				//checking 
				if (mLeft != nullptr && val < mData) {
					parent = mLeft->parent_recursive(val);
				}

				if (mRight != nullptr && val > mData) {
					parent = mRight->parent_recursive(val);
				}

				return parent;

		}

		/// <summary>
		///		traverses the Ordered Set adds it to a list in-order
		/// </summary>
		/// <param name="d">ArrayList pointer</param>
		void traverse_recursive(ssuds::ArrayList<T>* d, OrderedSetTraversalOrder order = OrderedSetTraversalOrder::INORDER) {

			if (order == OrderedSetTraversalOrder::PRE) {
				d->append(mData);
			}

			if (mLeft) {
				mLeft->traverse_recursive(d, order);
			}

			if (order == OrderedSetTraversalOrder::INORDER) {
				d->append(mData);
			}

			if (mRight) {
				mRight->traverse_recursive(d, order);
			}

			if (order == OrderedSetTraversalOrder::POST) {
				d->append(mData);
			}

		}



		/// <summary>
		///		returns a Node with the given data
		/// </summary>
		/// <param name="val">const T&</param>
		/// <returns>Node*</returns>
		bool erase_recursive(const T& val) {
			
			bool result;
			
			// looking to the Left
			if (val < mData && mLeft != nullptr) {
				result = mLeft->erase_recursive(val);
			}
			// looking to the right
			else if (val > mData && mRight != nullptr) {
				result = mRight->erase_recursive(val);
			}
			// mData matches val
			else if (mData == val) {
				// No Child
				if (mLeft == nullptr && mRight == nullptr) {
					delete[] this;
					return true;
				}
				// Left Child 
				else if (mLeft && mRight == nullptr) {
					mData = mLeft->mData;
					mLeft = mLeft->mLeft;
				}

				// Right Child
				else if (mRight && mLeft == nullptr) {
					mData = mRight->mData;
					mRight = mRight->mRight;
				}

				// Both Children
				else if (mLeft && mRight) {
					mData = mLeft->mData;
					mLeft = mLeft->mLeft;

				}
			}

			if (result) {
				return true;
			}
			else {
				return false;
			}
		}

		/// <summary>
		///		adds to a string that outputs a visual representation of the tree.
		/// </summary>
		/// <param name="s">std::string pointer</param>
		/// <param name="depth">unsigned int</param>
		void string_recursive(std::string* s, unsigned int depth = 0) {

			*s += std::to_string(mData);
			depth++;

			if (mLeft) {
				*s += "\n";
				for (int i = 0; i < depth; i++) {
					*s += "   ";
				}
				*s += "L: ";
				mLeft->string_recursive(s, depth);
			}

			if (mRight) {
				*s += "\n";
				for (int i = 0; i < depth; i++) {
					*s += "   ";
				}
				*s += "R: ";
				mRight->string_recursive(s, depth);
			}

		}

		}; // end of Node class

		// Attributes for OrderedSet itself.
	private:
		/// <summary>
		/// size of the Ordered Set
		/// </summary>
		unsigned int mSize;

	protected:
		/// <summary>
		///		The Root of the Ordered Set. It is the first Node that is seen when traversing the set.
		/// </summary>
		Node* mRoot;

	public:

		/// <summary>
		/// Default constructor 
		/// </summary>
		OrderedSet() : mSize(0), mRoot(nullptr)
		{
			// intentionally empty.
		}

		/// <summary>
		/// Initializer-list constructor
		/// </summary>
		/// <param name="ilist">std::initializer_list<T></param>
		OrderedSet(std::initializer_list<T> ilist)
		{
			
			for (T val : ilist) {
				this->insert(val);
			}
		}

		friend class Node;

		/// <summary>
		///		destroys the Ordered set before ending the script.
		/// </summary>
		~OrderedSet() {
			if (!mRoot) {
				return;
			}
			else {
				mRoot->clear_recursive();
			}
		}

		/// <summary>
		///		inserts a given value into its proper place within the Ordered Set
		/// </summary>
		/// <param name="val">const T&</param>
		/// <returns>bool</returns>
		bool insert(const T& val)
		{
			if (mSize == 0)
			{
				// Nothing here -- make the new node the root
				mRoot = new Node(val);
				mSize++;
				return true;
			}
			else
			{
				// We already have a root -- let it handle the rest
				bool result = mRoot->insert_recursive(val);
				if (result)
					mSize++;
				return result;
			}
		}

		/// <summary>
		///		checks to see if a value is already in the Ordered Set or not. 
		/// </summary>
		/// <param name="val">const T&</param>
		/// <returns>bool</returns>
		bool contains(const T& val) const
		{
			if (!mRoot) {
				return false;
			}
			else {
				return mRoot->contains_recursive(val);
			}
		}

		/// <summary>
		///		returns the number of values in the Ordered Set.
		/// </summary>
		/// <returns>unsigned int</returns>
		unsigned int size() {
			return mSize;
		}

		/// <summary>
		///		returns the height of the ordered set including the root
		/// </summary>
		/// <returns>unsigned int</returns>
		unsigned int get_height() {
			unsigned int height = 0;
			if (!mRoot) {
				return height;
			}
			else {
				height = mRoot->height_recursive(height);
				return height;
			}
		}

		/// <summary>
		///		Finds the parent Node of the given value.
		/// </summary>
		/// <param name="val">const T&</param>
		/// <returns>std::optional<T></returns>
		std::optional<T> get_parent(const T& val) {
			if (!mRoot) {
				return {};
			}
			else {
				Node* parent = mRoot->parent_recursive(val);
				if (parent->mData == val) {
					return{};
				}
				return parent->mData;
			}
		}

		/// <summary>
		///		returns an ArrayList of the Ordered Set in pre- post- and in-order. 
		/// </summary>
		/// <returns></returns>
		ssuds::ArrayList<T> traversal(OrderedSetTraversalOrder order = OrderedSetTraversalOrder::PRE) {

			ssuds::ArrayList<T>* d = new ssuds::ArrayList<T>;

			if (!mRoot) {
				return *d;
			}
			
			mRoot->traverse_recursive(d, order);

			
			return *d;
			
			
		}

		/// <summary>
		///		rebalances the Ordered Set so that the root is a median number
		/// </summary>
		void rebalance() {
			ssuds::ArrayList<T> d = this->traversal(OrderedSetTraversalOrder::INORDER);
			this->clear();

			//getting median value
			unsigned int median = d.size() / 2;

			// adding to ordered set 
			this->insert(d[median]);
			// removing from array
			d.remove(median);

			for (int i = median-1; i > -1; i--) {
				this->insert(d[i]);
			}

			for (int i = median; i < d.size(); i++) {
				this->insert(d[i]);
			}
		}

		std::string tree_string() {

			std::string string = "";

			if (!mRoot) {
				return string;
			}
			else {
				mRoot->string_recursive(&string);
			}

			return string;
		}

		/// <summary>
		///		returns a list of the ordered set
		/// </summary>
		/// <param name="os"></param>
		/// <param name="lList"></param>
		/// <returns></returns>
		friend std::ostream& operator <<(std::ostream& os, OrderedSet& O)
		{
			os << O.traversal(OrderedSetTraversalOrder::INORDER);
			return os;
		}

		/// <summary>
		///		erases given value from the ordered list
		/// </summary>
		/// <param name="val">const T&</param>
		/// <returns>bool</returns>
		bool erase(const T& val) {

			bool result;

			if (!mRoot) {
				return false;
			}
			else {
				result = mRoot->erase_recursive(val);
			}

			if (result){
				mSize--;
				return true;
			}
			else {
				return false;
			}

		}

		/// <summary>
		///		clears all values from Ordered Set
		/// </summary>
		void clear() {
			if (!mRoot) {
				return;
			}
			else {
				mRoot->clear_recursive();
				mSize = 0;
				mRoot = nullptr;
				return;
			}
		}



	};
}