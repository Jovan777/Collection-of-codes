// C++ program to demonstrate all operations of
// k-ary Heap
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int> const& ints, int k) {
	if (ints.size()<k)
	{
		return -1;
	}

	priority_queue<int, vector<int>, greater<int>> pq(ints.begin(), ints.begin() + k);
	

	for (int i = k; i < ints.size(); i++)
	{
		if (ints[i]>pq.top())
		{
			pq.pop(); pq.push(ints[i]);
		}

	}



	return pq.top();
}


int main()
{
	vector<int> ints = { 7, 4, 6, 3, 9, 1 };
	int k = 3;

	cout << "k'th largest array element is " << findKthLargest(ints, k);




	return 0;
}
