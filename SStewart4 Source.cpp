//Name: Stephen Jon Stewart  Student ID: 20669636

#include<iostream>		//Inlcudes input/output streams
#include<cstring>		//Includes fucntions to minipulate strings within the program
#include<fstream>		//Includes input/output classes to use on files
#include <string>		//Inlcludes operators for the string within the program
using namespace std;	//Ensures the cin/Couts are functional witin the program

						//----Constant Variables-----
						//Constant integer variables that were used throughout the whole program to ensure no magic numbers are present and better readability
const int search = 6;	//A constant variable to search through the whole of the 1d search file
const int text = 3;		//A constant variable to end at the amount of letters in the search 1 file
const int firstWord = 0;//A constant variable to iterate through the whole of the search variable of the search1 file
const int firstLetter = 0;//A constant variable to iterate through the whole of the text variable of the search1 file
const int wordCount = 6;//A constant variable to allow the display of all the search1 file

		//-----Voids to open the text files-----
//The fucntion to allow the search1.txt file to be opened into the program
//The function ensures that if the filename could not be opened, display the error messages such as "ERROR:"
void OpeningSearchFile(ifstream& searchFile)
{
	searchFile.open("search1.txt");
	if (!searchFile)
	{
		cout << "CRITICAL ERROR: ";
		cout << "The file cannot be opened, check the file is the correct location\n";
	}
}

//The fucntion to allow the text1.txt file to be opened into the program
//The function ensures that if the filename could not be opened, display the error messages such as "ERROR:"
void OpeningTextFile(ifstream& textFile)
{
	textFile.open("text1.txt");
	if (!textFile)
	{
		cout << "CRITICAL ERROR: ";
		cout << "The file cannot be opened, check the file is the correct location\n";
	}
}


		//-----The functions to read the letters in the text files into respective stirngs-----
//The fucntion to read in the search1.txt file into an array within the program
//Makes an overall while loop of if the filename does not equal the end of the file:
//Then the for loops will iterate the rows and columns of the search1.txt
//The nested for loops then declare a char variable which reads the filename and the for loops into the new decalred char variable
//This char varibale then is added to the string searcharray variable which will be called again later in the main program
void ReadSearchFile(ifstream &searchFile, string searchArray[])
{
	while (!searchFile.eof())
	{
		//The nested for loops to iterate through the search1.txt and add the letters out
		for (int i = firstWord; i < search; i++)
		{
			for (int j = firstLetter; j < text; j++)
			{
				//Char variable declaration to put the file into the charcters to read
				char charSearch;
				searchFile >> charSearch;
				if (!searchFile.eof())
				{
					//Char variable being added to the string array within another while loop to ensure the whole array and the 
					//text file can have their continunity sepeartley and ensure the files are not getting confused
					searchArray[i] += charSearch;
				}
			}
		}
	}
}

//The function to read the text1.txt into an array within the program
//Makes a while loop which reads if the filename does not equal the end of the file
//Declare another char variable and put the while of the text1.txt into that new char variable
//An if statement reads if the filename does not equal the end of the file
//add the char variable to the string array 
void ReadTextFile(ifstream &textFile, string& textArray)
{
	while (!textFile.eof())
	{
		//The new declared char variable and putting the filename into it
		char charText;
		textFile >> charText;
		//Another if statement is required to ensure the end of files loops do not get confused and add the variables together correctly
		if (!textFile.eof())
		{
			textArray += charText;
		}
	}
}


//-----The function to simply display how the text files are being read into the arrays and print the original format out to the user-----
//The function to display the contents of the searcharrays that were declared previously
//Make some cout sentences for the user to read then make a for loop which ensures the search1.txt is getting all the letters 
//from the spaces and line breaks that occur in the text file.
//The second array is simply displayed as no major loops had to occur for the text1.txt
void display(string textArray, string searchArray[])
{
	//search1.txt file is outputted to show it read correctly with a for loop to account for the amount of rows in the search1.txt file
	cout << "Programming assignment 45%: " << endl;
	cout << endl;
	cout << "Puzzle List of search 1.txt: " << endl;
	for (int i = firstWord; i < wordCount; i++)
	{
		cout << searchArray[i] << endl;
	}
	//Text1.txt file is outputted to show it read correctly
	cout << endl;
	cout << "Puzzle Wordsearch of text1.txt: " << endl;
	cout << textArray << endl;
}


//-----The function to ultimately compare the stirngs and utilise the .find function to 
//compare back and forth with the search and text textfiles (string::npos provides the ultimate comparison of same strings and words)-----.
//The function to find the positioning of words within the searcharrays that were declared previously
//Makes a for loop to make the compare variable that will be used later but ensures that the search1.txt contains all the letters ready for comparison
//The fucntion then defines a integer of find which performs the .find of the text1.txt with the search1.txt with the compare variable containned within
//The fucntion then makes a for loop which reads if the find integer does not equal "until the end of the string", then the search1.txt words would 
//be read with the compare and display the postions by the find integer.
//else if the if statement equals the end of the stirng and no words were found, simply display the location not found
void find(string textArray, string searchArray[])
{
	//The for loop which decalres the compare integer of 6 for the number of words in the search1.txt
	cout << "Finding all the words in the puzzle include: " << endl;
	for (int compare = firstWord; compare < wordCount; compare++)
	{
		//find integer established by making the text1.txt find the words of search1.txt with the .find function class
		int find = textArray.find(searchArray[compare]);
		//if the find integer does not reach the end of the file with finding a word, then display the words with 
		//the compare integer followed by the postions with the find integer.
		if (find != string::npos)
		{
			cout << searchArray[compare] << " Found, Location at: " << find << endl;
		}
		//if the statement reaches the end of the file and does not find a word, then display this message and the not found words
		else
		{
			cout << searchArray[compare] << " Location, Not Found" << endl;
		}
	}
}

//-----The integer main were the variables are declared furthermore, the ifstreams declared and the voids from above being called and used for the 45%-----
//The actual main method within the program as the top of the program contains all the functions and constants
int main()
{

	//-----The strings are declared here as well as the ifstreams to make the whole program functions with the files and stream classes-----
	//This string array is used for the search1.txt and is empty for the char variable to be carried into it as well as the search variable 
	//being counted over to make sure the whole of the words are counted for.
	//searchArray = search1
	string searchArray[search];

	//This string array is used for the text1.txt and is an empty string that then contains the whole of the puzzle of words for the comparison
	//textArray = text1
	string textArray = "";

	//All the ifstreams of the files are contained here and are called from the functions that open the files at the top of the program
	ifstream searchFile;
	ifstream textFile;


	//-----The actual voids being called in the main in order of how they function, opening files first, reading the files second, 
	//displaying origianl format third and doing the comparison last-----.
	OpeningSearchFile(searchFile);	//The function to open the search1.txt file is called here with the filename carried over
	OpeningTextFile(textFile);		//The function to open the text1.txt file is called here with the new filename carried over
	ReadSearchFile(searchFile, searchArray);	//The search1.txt file is read into an array here from the function, the search1.txt filename 
	//and searcharray are called here.
	ReadTextFile(textFile, textArray);		//The text1.txt file is read into an array here from the function, the file1.txt filename 
	//and the new searcharray is called here.
	display(textArray, searchArray);	//The function to display the original text files on screen is called here with the filenames being carried over
	cout << endl;	//A simple cout sepeartes the program for better readability
	find(textArray, searchArray);	//The actual find function for the 45% mark is called here and performs the features to compare and 
	//display the word locations, the searcharrays are carried over.
	system("pause");	//A simple system("pause") will simply pause the program to allow people to read the code and see 
	//what the output of functions and code does.
}