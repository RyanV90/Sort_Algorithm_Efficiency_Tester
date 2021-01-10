
class SelectionSort 
{
public:
	
	SelectionSort(vector<int>& vector) {

		for (int i = 0; i < vector.size() - 1; i++)
		{
			int minIndex = i;
			for (int j = i + 1; j < vector.size(); j++)
				if (vector[minIndex] > vector[j])
					minIndex = j;
			//swap elements in locations i and minIndex
			int temp = vector[i];
			vector[i] = vector[minIndex];
			vector[minIndex] = temp;
		}
	}
};