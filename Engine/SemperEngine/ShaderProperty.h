#ifndef SHADER_PROPERTY
#define SHADER_PROPERTY

#include <map>
#include <vector>
#include <string>

namespace SemperEngine {

	template<class T>
	class ShaderProperty
	{
	public:

		typedef std::pair<std::string, T> keyValue;

		std::map<std::string, T> values;

	public:

		ShaderProperty()
		{

		}

		ShaderProperty(std::string name, T value) {
			values[name] = value;
		}

		void Add(std::string name, T value)
		{
			values[name] = value;
		}

		int Size()
		{
			return values.size();
		}

		bool IsEqual(ShaderProperty<T> &property)
		{

			return property.values == this->values;
		}

		std::vector<keyValue> GetKeyValues()
		{
			std::vector<keyValue> result;
			for (auto i = values.begin(); i != values.end(); i++)
			{
				result.push_back(keyValue(i->first, i->second));
			}
			return result;
		}
	};
}
#endif // !SHADER_PROPERTY

