#include"Vector.h"
#include<iostream>

// test class Vector3
class Vector3
{
public:
	Vector3() {}
	Vector3(float scalar) 
		:x(scalar), y(scalar), z(scalar) {}

	Vector3(float x, float y, float z) 
		:x(x), y(y), z(z) {}

	// copy constructor
	Vector3(const Vector3& other) :
		x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copy\n";
	}

	// move constructor
	Vector3(Vector3&& other) noexcept:
		x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Move\n";
	}

	// destructor
	~Vector3()
	{
		std::cout << "Destroyed\n";
	}

	// copy assignment operator
	Vector3& operator=(const Vector3& other) 
	{
		std::cout << "Copy\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	// move assignment operator
	Vector3& operator=(Vector3&& other)noexcept
	{
		std::cout << "Move\n";
		x = other.x;
		y = other.y; 
		z = other.z;
		return *this;
	}
	friend void printVector(const Vector<Vector3>& vec);
private:
    float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

template<class T>
void printVector(const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << std::endl;
	std::cout << "------------------";
}

void printVector(const Vector<Vector3>& vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i].x << "," << vec[i].y << "," << vec[i].z << std::endl;
	std::cout << "------------------";
}

int main()
{
	Vector<std::string>data;
	data.push_back("yzh");
	data.push_back("cpp");
	printVector(data);

	std::cout << "---------------------" << std::endl;

	Vector<Vector3>vector;
	// push_back temporary rvalues
	vector.push_back(Vector3(1.0f));
	vector.push_back(Vector3(2,3,4));
	vector.push_back(Vector3());
	printVector(vector);

	/*Vector<Vector3>vec;
	vec.emplace_back(1.0f);
	vec.emplace_back(2, 3, 4);
	vec.emplace_back();
	printVector(vec);*/
}