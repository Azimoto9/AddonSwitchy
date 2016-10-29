#include "stdafx.h"
#include "classes.h"
#include <iostream>
#include <string>
#include <fstream>


std::string getFileContents(std::ifstream&);
using namespace std;


std::string getFileContents(std::ifstream& File)
{
	std::string Lines = "";        //All lines

	if (File)                      //Check if everything is good
	{
		while (File.good())
		{
			std::string TempLine;                  //Temp line
			std::getline(File, TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}


int main() {


	//placeholder gui


	string commandLine;
	int exit = 0;
	ifstream Reader("ascii.txt");
	string Art = getFileContents(Reader);
	cout << Art << "\n" << "Enter a Command: ";
	cin >> commandLine;

	string commands[4] = { "mkbak", "exit", "", "" };
	while (exit != 1) {

		if (commandLine == commands[0]) {
			mkbak("C:\\users\\austin\\Downloads");
		cout << "\nEnter a Command: ";
		cin >> commandLine;
	}
		else if (commandLine == commands[1]) {
			exit = 1;
		}
		else {
			cout << "\nInvalid Command";
			cout << "\nEnter a Command: ";
			cin >> commandLine;
		};
		}
		


}


