// C++ program to check if a given instance of N*N-1
// puzzle is solvable or not
#include <iostream>
#define N 4
using namespace std;

// A utility function to count inversions in given
// array 'arr[]'. Note that this function can be
// optimized to work in O(n Log n) time. The idea
// here is to keep code small and simple.
int getInvCount(int arr[])
{
	int inv_count = 0;
	for (int i = 0; i < N * N - 1; i++)
	{
		for (int j = i + 1; j < N * N; j++)
		{
			// count pairs(i, j) such that i appears
			// before j, but i > j.
			if (arr[j] && arr[i] && arr[i] > arr[j])
				inv_count++;
		}
	}
	return inv_count;
}

// find Position of blank from bottom
int findXPosition(int puzzle[N][N])
{
	// start from bottom-right corner of matrix
	for (int i = N - 1; i >= 0; i--)
		for (int j = N - 1; j >= 0; j--)
			if (puzzle[i][j] == 0)
				return N - i;
}

// This function returns true if given
// instance of N*N - 1 puzzle is solvable
bool isSolvable(int puzzle[N][N])
{
	// Count inversions in given puzzle
	int invCount = getInvCount((int*)puzzle);

	// If grid is odd, return true if inversion
	// count is even.
	if (N & 1)
		return !(invCount & 1);

	else	 // grid is even
	{
		int pos = findXPosition(puzzle);
		if (pos & 1)
			return !(invCount & 1);
		else
			return invCount & 1;
	}
}

/* Driver program to test above functions */
int main()
{

	int puzzle[N][N] =
	{
		{2,5,3,4},
		{1,6,7,8},
		{9,10,11,12}, // Value 0 is used for empty space
		{13,14,15,0},
	};

	isSolvable(puzzle)? cout << "Solvable":
						cout << "Not Solvable";
	return 0;
}


// find full article on this :- https://www.geeksforgeeks.org/check-instance-15-puzzle-solvable/
// very good observation