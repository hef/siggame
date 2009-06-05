#ifndef Utils_H
#define Utils_H
class Utils
{
private:
public:
  Utils(){}
  ~Utils(){}
  int sumUp(int);
};
int Utils::sumUp(const int n)
{
	return ((n*(n+1))/2);
}
#endif /* Utils_H */
