#include "student.h"
#include <cstring>

void student::setname(char s[20])
{
	strcpy_s(this->nume, s);
}
char* student::getname()
{
	return this->nume;
}

void student::math(float x)
{
	this->notam = x;
}
float student::getmath()
{
	return this->notam;
}

void student::eng(float x)
{
	this->notae = x;
}
float student::geteng()
{
	return this->notae;
}

void student::hist(float x)
{
	this->notah = x;
}
float student::gethist()
{
	return this->notah;
}

float student::media()
{
	return (this->notam + this->notae + this->notah) / 3;
}

int student::compare_media(student s1, student s2)
{
	if (s1.media() > s2.media())
		return 1;
	else if (s1.media() == s2.media())
		return 0;
	else
		return -1;
}

int student::compare_math(student s1, student s2)
{
	if (s1.getmath() > s2.getmath())
		return 1;
	else if (s1.getmath() == s2.getmath())
		return 0;
	else
		return -1;
}
int student::compare_eng(student s1, student s2)
{
	if (s1.geteng() > s2.geteng())
		return 1;
	else if (s1.geteng() == s2.geteng())
		return 0;
	else
		return -1;
}
int student::compare_hist(student s1, student s2)
{
	if (s1.gethist() > s2.gethist())
		return 1;
	else if (s1.gethist() == s2.gethist())
		return 0;
	else
		return -1;
}
int student::compare_nume(student s1, student s2)
{
	for (int i = 0; i<strlen(s1.getname()); i++)
	{
		if (s1.getname()[i] > s2.getname()[i])
			return -1;
		else if (s1.getname()[i] == s2.getname()[i])
		{
			continue;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}