#ifndef Utils_H
#define Utils_H
class Utils
{
private:
public:
  Utils(){}
  ~Utils(){}
  int SumUp(int);
};
int Utils::SumUp(const int n)
{
	return ((n*(n+1))/2);
	/*if (n<=1)
	{
		return n;
	}
	return n+this->SumUp(n-1);
	*/
}
#endif /* Utils_H */
