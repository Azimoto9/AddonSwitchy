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
using namespace std;

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

class backer{

public:
	backer(string path) {

	};
private:
	string found;
	bool ifFound;
public:
	backer() {
		
	};
	inline bool exists(std::string& name) {
		struct stat buffer;
		return (stat(name.c_str(), &buffer) == 0);
	}
	void finder() {
		
	};
	void zipper(){

	};
	void unzipper(){

	};
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
		cout << "\nit works\n" << fileChecker << " exists\n";
	}
	else if (backed.exists(fileChecker) == false){
		cout << "\nit still works\n" << fileChecker << " does not exist\n";
	}
}



void mkbak(string path) {
	struct stat info;
	dateFolder timeget(path);
	if (stat(path.c_str(), &info) != 0)
		printf("cannot access %s\n", timeget.dated.c_str());
	else if (info.st_mode & S_IFDIR) {
		printf("Creating directory %s\n", timeget.dated.c_str());
		timeget.createBackupDir();
		doBak(timeget.dated);
	};
};
