#pragma once

template <typename E>  // E is the element type.
class Queue {
public:

	int f2 = 0;

	Queue() {

	}
	void add(int num) {
		f2 += num;
	}
};