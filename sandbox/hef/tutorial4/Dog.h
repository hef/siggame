#ifndef Dog_H
#define Dog_H
#include <string>
class Dog
{
private:
  float height;
  float weight;
  std::string name;
public:
  Dog(std::string name, const int height, const int weight);
  Dog( const Dog& oldDog);
  ~Dog(){}
  int getHeight() const;
  void setHeight(const int n);
  int getWeight() const;
  void setWeight(const int n);
  std::string getName() const;
};
#endif /* Dog_H */
