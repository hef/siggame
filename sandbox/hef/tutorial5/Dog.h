#ifndef Dog_H
#define Dog_H
#include <string.h>
class Dog
{
protected:
  float height;
  float weight;
  char* name;
public:
  Dog():name( new char[17] ){}//why is this neccesary
  Dog(char const * const name, const int height, const int weight);
  Dog( const Dog& oldDog);
  virtual ~Dog();
  int getHeight() const;
  void setHeight(const int n);
  int getWeight() const;
  void setWeight(const int n);
  char const * const getName() const;
//  Dog operator=(const Dog&);
  virtual void bark() = 0;
};
#endif /* Dog_H */
