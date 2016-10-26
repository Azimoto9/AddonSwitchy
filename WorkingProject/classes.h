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

void doBak(string path) {
	backer backed;
	path = path.append(".zip");
	if (backed.exists(path) == true) {
		cout << "\nit works\n" << path << "\n";
	}
	else if (backed.exists(path) == false){
		cout << "\nit still works\n" << path << "\n";
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
