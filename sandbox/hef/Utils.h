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
}
#endif /* Utils_H */
