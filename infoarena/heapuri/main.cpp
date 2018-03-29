#include <fstream>
#include <vector>
#include <set>

using namespace std;

ifstream fin("heapuri.in");
ofstream fout("heapuri.out");


vector <int> insertedElements;
set <int> heap;

int main()
{
	int numberOfQueries, operationType, number;
	fin >> numberOfQueries;
	while (numberOfQueries)
	{
		fin >> operationType;
		switch (operationType)
		{
			case 1:
				fin >> number;
				heap.insert(number);
				insertedElements.push_back(number);
				break;
			case 2:
				fin >> number;
				heap.erase(insertedElements[number - 1]);
				break;
			case 3:
				fout << *heap.begin() << '\n';
				break;
		}
		--numberOfQueries;
	}
	return 0;
}