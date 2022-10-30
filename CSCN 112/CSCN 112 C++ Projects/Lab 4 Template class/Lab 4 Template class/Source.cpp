//Andres Choque Lab 4 Template class
#include <iostream>

using namespace std;
template <class T>
class Rectangle
{
public:
	Rectangle()
	{
		setLength(0);
		setWidth(0);
	}
	void setLength(T l) { length = l; }
	void setWidth(T w) { width = w; }
	T getLength() { return length; }
	T getWidth() { return width; }
	~Rectangle() { cout << "Rectangles are deallocated. \n"; }
private:
	T length = 0;
	T width = 0;
};

int main()
{
	Rectangle<float> r1, r2, r3;
	r1.setLength(1.1);
	r1.setWidth(1.1);
	r2.setLength(2);
	r2.setWidth(2);
	r3.setLength(3);
	r3.setWidth(3);
	cout << "Here are the dimensions of these rectangles...\n";
	cout << "Rectangle 1: Length = " << r1.getLength() << " Width = " << r1.getWidth() << endl;
	cout << "Rectangle 2: Length = " << r2.getLength() << " Width = " << r2.getWidth() << endl;
	cout << "Rectangle 3: Length = " << r3.getLength() << " Width = " << r3.getWidth() << endl;
	return 0;

}
