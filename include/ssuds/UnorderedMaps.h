#pragma once


namespace ssuds {


	template <class K, class V>
	/// <summary>
	///		an Unordered map that uses hashes to store its data. 
	/// </summary>
	class UnorderedMap
	{
		// K and V are usable anywhere in here, just like T has been
		// K = key type, V = value type

	private:
		unsigned int mCapacity;
		ssuds::LinkedList<std::pair<K, V>>* mArray;

	public:

		/// <summary>
		///		default constructor
		/// </summary>
		UnorderedMap() : mCapacity(10) {
			mArray = new ssuds::LinkedList<std::pair<K, V>>;
			std::pair<K, V> p;
			for (int i = 0; i < mCapacity; i++) {
				mArray->append(p);
			}
		}

		V& operator[](const K& key) {

			// 0. Check for growth
			// 1. Generate new Hash Value
			std::hash<K> hasher;
			unsigned long long hash = hasher(key);
			// 2. mod with table size
			unsigned int index = hash % mCapacity;

			std::pair<V, K> p;
			p.first = key;

			mArray->insert(p, index);
			// 4. return reference to existing or new_value 

			return mArray->at(index).second;
		}
	};
};