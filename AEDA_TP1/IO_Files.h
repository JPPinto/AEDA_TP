#ifndef IO_FILES_H
#define IO_FILES_H

#include "Escola.h"

using namespace std;

class IO {

public:
	IO(){}
	Escola * LoadData(const string file);
	void SaveData(const string file);
};
#endif // !1

