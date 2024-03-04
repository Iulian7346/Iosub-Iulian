class student
{
private:
	char nume[20];
	float nm, ne, nh;

public:
	void setname(char s[20]);
	char* getname();

	void math(float x);
	float getmath();

	void eng(float x);
	float geteng();

	void hist(float x);
	float gethist();

	float media();

	static int compare_media(student s1, student s2);
	static int compare_math(student s1, student s2);
	static int compare_eng(student s1, student s2);
	static int compare_hist(student s1, student s2);
	static int compare_nume(student s1, student s2);

};