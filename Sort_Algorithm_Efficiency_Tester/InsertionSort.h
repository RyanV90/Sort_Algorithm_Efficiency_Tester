
#include <iostream>
#include <vector>

using namespace std;

class InsertionSort
{
public:

	template<typename T> InsertionSort(vector<T>& vector) {

		for (int i = 1; i < vector.size(); i++)
		{
			int j = i;
			while (j > 0 && (vector[j] < vector[j - 1])) //insert the ith element into sorted list 
			{
				T temp = vector[j];
				vector[j] = vector[j - 1];
				vector[j - 1] = temp;
				j--; // move index j back
			}
		}
	}

};