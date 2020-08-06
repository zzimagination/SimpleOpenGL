#ifndef SHADER_PROPERTY
#define SHADER_PROPERTY

#include <vector>

using namespace std;

template<class T>
class ShaderProperty
{
public:

	string name;

	T value;

public:

	ShaderProperty(string name, T value) {
		this->name = name;
		this->value = value;
	}

	T GetValue() {
		return value;
	}

	void SetValue(T value) {
		this->value = value;
	}

	bool IsEqual(ShaderProperty<T> property)
	{
		return property.name == this->name &&property.value == this->value;
	}
};

#endif // !SHADER_PROPERTY

