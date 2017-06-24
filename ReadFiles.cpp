/* Liza Morrison, CMCS240 
* This program opens and reads in a text file consisting of student names, their student IDs, and their year on different lines for each person. 
* The names, IDs, and years are stored in three separate arrays. The program then opens an output file and writes the stored information to that file. 
* The format of the output file consists of the names on the first lines, the IDs on the second line, and the years on the last line.
*/
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	const int ARRAY_SIZE = 128;
	string names[ARRAY_SIZE];
	int ids[ARRAY_SIZE];
	int year[ARRAY_SIZE];
	
	int counter = 0;

	ifstream inFile;
	ofstream outFile;

	//Check to make sure the input and output file names are entered as command line arguments
	if (argc != 3) 
	{
		cerr << "Usage: " << argv[1] << " <inFile> " << argv[2] << " <outFile> " << endl;
		return(0);
	}
	else
	{
		inFile.open(argv[1]); //Assume argv[1] is the input file to open
		
		if (!inFile.is_open()) //If the input file cannot be opened, then an error message appears
		{
			cerr << "Could not open the file." << endl;
			exit(1);
		}
		else //If the input file can be opened 
		{
			outFile.open(argv[2]); //Open the output file as the second command line argument

			if (!outFile.is_open()) //If the output file cannot be opened, then an error message appears
			{
				cerr << "Could not open the output file." << endl;
				exit(1);
			}
			
			//Check to see if the input file is empty
			//I used the peek() method from www.cplusplus.com and is the only way I could figure out how to check for an empty file. Ashley and I worked together on this part.
			if (inFile.peek() == std::ifstream::traits_type::eof()) 
			{
				cerr << "The input file is empty." << endl;
			}


			while (inFile.good()) //While the input file has information to be read
			{
				if (counter >= ARRAY_SIZE) //Check to make sure that the entries in the file do not exceed the maximum number of entries (128)
				{
					cerr << "Reached max of " << ARRAY_SIZE << endl;
					break;
				}
				else
				{
					inFile >> names[counter] >> ids[counter] >> year[counter]; //Read in the names, IDs, and years from the input file and store them into three different arrays
					if (inFile.fail()) //If the input file surpasses the maximum number of entries
					{
						break;
					} 
					counter++;
				}
			}
				
			//Write out the names to the output file on the first line
			for (int i = 0; i < counter; i++)
			{
				outFile << names[i] << "\t";
			}	
			outFile << endl;

			//Write out the IDs to the output file on the second line
			for (int i = 0; i < counter; i++)
			{
				outFile << ids[i] << "\t";
			}
			outFile << endl;

			//Write out the years to the output file on the third line
			for (int i = 0; i < counter; i++)
			{
				outFile << year[i] << "\t";
			}
			outFile << endl;
		}
		inFile.close(); 
		outFile.close();
	}
}
