// Lab 3c, const And Constructors, Part 3
// Programmer: Minos Park 
// Editor(s) used: Sublime Text 2 
// Compiler(s) used: G++
#ifndef Rectangle_h
#define Rectangle_h

template <class DataType>
class Rectangle 
{
  DataType length;
  DataType width;
public:
  Rectangle();
  Rectangle(const DataType&, const DataType&);
  void setLength(const DataType&);
  void setWidth(const DataType&);
  bool length_greater_than_width() const;
  DataType getPerimeter() const;
  DataType getArea() const;
};


template <class DataType>
Rectangle<DataType>::Rectangle()
{

}

template <class DataType>
Rectangle<DataType>::Rectangle(const DataType& w, const DataType& l)
{
  length = l; width = w;
}

template <class DataType>
void Rectangle<DataType>::setLength(const DataType& l)
{
  length = l;
}

template <class DataType>
void Rectangle<DataType>::setWidth(const DataType& w)
{
  width = w;
}

template <class DataType>
bool Rectangle<DataType>::length_greater_than_width() const
{
  if(length > width) return true;
  else return false;
}

template <class DataType>
DataType Rectangle<DataType>::getPerimeter() const
{

  return ( length + width ) * 2; 
}

template <class DataType>
DataType Rectangle<DataType>::getArea() const
{

  return length * width;
}


#endif