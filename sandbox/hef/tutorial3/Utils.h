#ifndef Utils_H
#define Utils_H
class Utils
{
private:
public:
  Utils(){}
  ~Utils(){}
  int sumUp( const unsigned int n );
  //causes sumUp to fail on non unsigned int parameters
  template <class T>
  int sumUp( T n );
};
#endif /* Utils_H */
