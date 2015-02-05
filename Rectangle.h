// Lab 2b, Writing Templated Classes
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
  void setLength(DataType);
  void setWidth(DataType);
  bool length_greater_than_width();
  DataType getPerimeter();
  DataType getArea();
};

template <class DataType>
void Rectangle<DataType>::setLength(DataType l)
{
  length = l;
}

template <class DataType>
void Rectangle<DataType>::setWidth(DataType w)
{
  width = w;
}

template <class DataType>
bool Rectangle<DataType>::length_greater_than_width()
{
  if(length > width) return true;
  else return false;
}

template <class DataType>
DataType Rectangle<DataType>::getPerimeter()
{
  DataType t;

  t = ( length + width ) * 2;

  return t; 
}

template <class DataType>
DataType Rectangle<DataType>::getArea()
{
  DataType t;

  t = ( length * width );

  return t;
}


#endif