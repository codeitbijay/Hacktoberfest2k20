// C++ implementation to design
// a queue data structure to get
// minimum element in O(1) time

#include <bits/stdc++.h>

using namespace std;

template <typename T>

class MinMaxQueue {
public:

	queue<T> Q;

	deque<T> D;

	void enque_element(T element)
	{
		if (Q.size() == 0) {
			Q.push(element);
			D.push_back(element);
		}
		else {
			Q.push(element);

			while (!D.empty() &&
			D.back() > element) {
				D.pop_back();
			}
			D.push_back(element);
		}
	}

	void deque_element()
	{

		if (Q.front() == D.front()) {
			Q.pop();
			D.pop_front();
		}
		else {
			Q.pop();
		}
	}
	T getMin()
	{
		return D.front();
	}
	T getMax()
	{
		return D.back();
	}
};

// Driver Code
int main()
{
	MinMaxQueue<int> k;
	int example[3] = { 1, 2, 4 };

	for (int i = 0; i < 3; i++) {
		k.enque_element(example[i]);
	}
	cout << k.getMin() << "\n";
	k.deque_element();
	cout << k.getMax() << "\n";
}

