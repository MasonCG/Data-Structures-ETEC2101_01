#pragma once
namespace ssuds
{
	template <class T>
	class OrderedSet
	{
	private:
		// Just like LinkedList, I don't want outside users to see this AT ALL!!!
		class Node
		{
		private:
			T mData;
			Node* mLeft;
			Node* mRight;
		public:
			Node(const T& data, Node* left, Node* right) : mData(data), mLeft(nullptr),
				mRight(nullptr)
			{
				// intentionally empty
			}

			// Other getters/setters

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


			bool contains_recursive(const T& val) const
			{
				// If I hold the value, return true.
				// If the value is less than my data it *WOULD* go to my left
				//     If I don't have a left child, return false
				//     If I do, ask the left child to compute the answer.
			}
		}; // end of Node class

		// Attributes for OrderedSet itself.
	private:
		unsigned int mSize;
		Node* mRoot;
	public:
		OrderedSet() : mSize(0), mRoot(nullptr)
		{
			// intentionally empty.
		}


		bool insert(const T& val)
		{
			if (mSize == 0)
			{
				// Nothing here -- make the new node the root
				mRoot = new Node(val);
				mSize = 1;
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

		bool contains(const T& val) const
		{
			if (!mRoot) {
				return false;
			}
			else {
				return mRoot->contains_recursive(val);
			}
		}

		unsigned int size() {
			return mSize;
		}

	};
}