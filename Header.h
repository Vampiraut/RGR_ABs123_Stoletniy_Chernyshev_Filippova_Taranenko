#pragma once
#include <iostream>
#include <cstdlib>

#include <string>
#include <locale>
#include <windows.h>

#include <fstream>


#define Clear
using namespace std;

void PASSWORD_CHEK();
int principle_of_operation();
int crypto_type_select(int);

void funktypename(int);
void funkprinciple(int);

void start_encryption(int, int);

void Caesar_DECODE(int);
void Caesar_CODE(int);
void Gronsfeld_DECODE();
void Gronsfeld_CODE();