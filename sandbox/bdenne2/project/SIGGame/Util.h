#ifndef UTIL_H
#define UTIL_H

class Util
{
public:
	Util() {}
	~Util() {}
	unsigned int sumUp(unsigned int integer);
private:
	int sumUp(int integer);
	float sumUp(float integer);
	double sumUp(double integer);
};

#endif // UTIL_H