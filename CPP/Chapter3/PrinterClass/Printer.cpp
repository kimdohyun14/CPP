#include <iostream>
#include <cstring>
#include "Printer.h"
using namespace std;

void Printer::SetString(const char * ptr) {
	strcpy(str, ptr);
}

void Printer::ShowString() {
	cout << str << endl;
}