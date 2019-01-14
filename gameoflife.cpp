/* 

Game of Life Simulation
COMPLETED 1/14/2019
L. Rajan

*/ 



#include <iostream>
#include <cstring>

using namespace std;

const int SIZE = 10; 


int main()
{
	char grid[SIZE][SIZE] = {
							{'X','X','X','X','X','X','X','X','X','X'}, //1
							{'X','X','X','X','X','X','X','X','X','X'}, //2
							{'.','.','.','X','X','X','.','.','.','.'}, //3
							{'X','.','.','X','.','.','.','.','X','.'}, //4
							{'.','.','.','.','.','X','.','.','.','.'}, //5 
							{'X','X','X','X','X','.','.','.','.','.'}, //6
							{'X','.','.','.','X','.','.','.','.','.'}, //7
							{'X','.','.','.','.','.','.','.','.','.'}, //8
							{'.','.','.','.','.','.','.','.','.','.'}, //9
							{'X','X','X','X','.','.','.','.','.','.'}, //10
																	}; 


													

	int row = 0;
	int col = 0;
	int liveNeighbors = 0; 
	bool alive; 
	int userChoice; 

	int generationCount = 0; 


	cout << "Welcome to Conway's Game of Life." << endl; 

	cout << "Initial grid state:" << endl;
	cout << endl;

	for (row = 0; row < SIZE; row++)
	{
	        for (col = 0; col < SIZE; col++)
	        {
	            cout<<grid[row][col]<<"  ";
	        }

 		cout<<endl;
	}

	cout << endl;
	cout << endl;

	cout << "Press 1 to view next generation,";
	cout << "or press 0 to exit." << endl; 
	cout << endl;
	cin >> userChoice;

	while (userChoice == 1)
	{
		generationCount++;

		//alive state is X, dead state is . 

		for(row = 0; row < SIZE; row++)           //iterate through the grid 
			for(col = 0; col < SIZE; col++)
			{

				// reset counter/bool 

				liveNeighbors = 0;
				alive = false; 

				//all the 8 neighbor conditions 

				if (grid[row-1][col-1] == 'X')
					liveNeighbors++; 

				if (grid[row-1][col] == 'X')
					liveNeighbors++;

				if (grid[row-1][col+1] == 'X')
					liveNeighbors++;

				if (grid[row][col-1] == 'X')
					liveNeighbors++;

				if (grid[row][col+1] == 'X')
					liveNeighbors++;

				if (grid[row+1][col-1] == 'X')
					liveNeighbors++;

				if (grid[row+1][col] == 'X')
					liveNeighbors++;

				if (grid[row+1][col+1] == 'X')
					liveNeighbors++;

				//determine local state before this generation

				if (grid[row][col] == 'X')
					alive = true; 
				else
					alive = false; 

				//determine local state after this generation 

				if (alive)
				{
					if (liveNeighbors < 2)
						alive = false;
					if ( (liveNeighbors == 2) || (liveNeighbors == 3))
						alive = true;
					if (liveNeighbors > 3)
						alive = false; 
				}
				else //dead
				{
					if (liveNeighbors > 3)
						alive = true; 
				}

				//set outcome in grid 

				if(alive)
					grid[row][col] = 'X';
				else
					grid[row][col] = '.';


			} // end of iterative for loop 


			//print grid 
				
			cout << "Generation count: " << generationCount << endl;
			cout << endl; 

			for (row = 0; row < SIZE; row++)
			{
		        for (col = 0; col < SIZE; col++)
		        {
		            cout<<grid[row][col]<<"  ";
		        }

	 		cout<<endl;
			}

			cout << endl;
			cout << endl;


			cout << "1 or 0?" << endl;
			cin >> userChoice; 



		} // end of while userChoice loop




return 0;

} // end int main 