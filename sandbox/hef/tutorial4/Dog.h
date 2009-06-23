#ifndef Dog_H
#define Dog_H
class Dog
{
private:
  float height;
  float weight;
  char* name;
public:
  Dog(char* name, const int height, const int weight);
  Dog( const Dog& oldDog);
  ~Dog();
  int getHeight() const;
  void setHeight(const int n);
  int getWeight() const;
  void setWeight(const int n);
  char* getName() const;
};
#endif /* Dog_H */
