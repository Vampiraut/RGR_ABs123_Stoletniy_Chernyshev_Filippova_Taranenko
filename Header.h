#pragma once
#include <iostream>
#include <cstdlib>

#include <string>
#include <locale>
#include <windows.h>

#include <fstream>


#define Clear1
using namespace std;

void PASSWORD_CHEK();
int principle_of_operation();
int crypto_type_select(int);

void input_str_to_txt();

void funktypename(int);
void funkprinciple(int);

void start_encryption(int, int);
void encryption_chek(int, int);

void Caesar_DECODE(int);
void Caesar_CODE(int);
void Gronsfeld_DECODE();
void Gronsfeld_CODE();