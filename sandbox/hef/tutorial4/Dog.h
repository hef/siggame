#ifndef Dog_H
#define Dog_H
class Dog
{
private:
  float height;
  float weight;
  string name;
public:
  Dog(){}
  Dog(string name);
  ~Dog(){}
  int getHeight() const;
  void setHeight(const int n) const;
  int getWeight() const;
  void setWeight(const int n) const;
  string getName() const;
};
#endif /* Dog_H */
