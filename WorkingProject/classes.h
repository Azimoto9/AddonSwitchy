#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include <direct.h>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <array>
using namespace std;


string localFolder = "";
bool found = false;


class dateFolder {

public:
	char date[9];
	string dater;
	string dated;
	string test = "\\";
	dateFolder(string cst ="C:\\defaultPath\\") {
		_strdate_s(date);
	
		if (cst.back() != test.back()) {
			cst = cst.append(test);
			//checks if / is at the end so as to not create a folder named /pathfolder
			//instead of path/folder or a file called /folderfile
		}
		dated = string(cst) + date;
		replace(dated.begin(), dated.end(), '/', '-');

	};
	~dateFolder() {
	};

	void createBackupDir() {
		_mkdir(dated.c_str());
	};

	void coutter() {
		cout << dated << " \n";
	};

};

class backer {

public:
	backer(string path) {

	};
private:
	bool ifFound; //unused for now
	string wlocations[4] = {"C:\\World of Warcraft\\" , "D:\\World of Warcraft\\","C:\\Program Files (x86)\\World of Warcraft\\","C:\\Program Files\\World of Warcraft\\"};
public:
	backer() {

	};
	inline bool exists(std::string& name) {
		struct stat buffer;
		return (stat(name.c_str(), &buffer) == 0);
	};
	void zipper(string backupName) {
		//method to make a zip file containing interface and WTF folders go here
	};
	void unzipper(string backupName) {
		//method to delete current wtf and interface folders and unzip a backup goes here
	};
	void wowFinder() {
		string workingFile;
		for (int i = 0; i <= 3; ++i) {
			workingFile = wlocations[i];
			workingFile.append("Wow.exe");
			if (exists(workingFile) == true) {
				cout << "Wow folder found at: " << wlocations[i] << "\n";
				localFolder = wlocations[i];
				found = true;
				break;
			}
		}


	}
};

	void doBak(string paths) {
		backer backed;
		char time[9];
		string timed;
		string zipp = ".zip";
		_strtime_s(time);
		timed = time;
		replace(timed.begin(), timed.end(), ':', '.');
		string fileChecker = paths + timed + zipp;

		if (backed.exists(fileChecker) == true) {
			cout << "\nFile Already exists!";
		}
		else if (backed.exists(fileChecker) == false) {
			//time to pull the files i need and create a zip file
			backed.wowFinder();
			if (found == false) {
				//ask user for input
				cout << "\nWoW Folder not found!";
				cout << "\nPlease input WoW directory: ";
				cin >> localFolder;
				//initiate transfer and zip
			}
			else {
				//initiate transfer and zip
			};


		};



	}


	void mkbak(string path) {
		struct stat info;
		dateFolder timeget(path);
		if (stat(path.c_str(), &info) != 0) {
			printf("cannot access %s\n", timeget.dated.c_str());
		}
		else if (info.st_mode & S_IFDIR) {
			printf("Creating directory %s\n", timeget.dated.c_str());
			timeget.createBackupDir();
			doBak(timeget.dated);
		};
	};