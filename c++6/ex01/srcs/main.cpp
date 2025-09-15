#include "../includes/Serializer.hpp"

int main()
{
    Data	originalData;
	Data	*originalPtr = &originalData;
    
	originalData.name = "Samatsum";
	originalData.age = 22;
	originalData.studentOf42 = true;

	std::cout << "=== Original Data ===" << std::endl;
	std::cout << "Name       :" << originalData.name << std::endl;
	std::cout << "Age        :" << originalData.age << std::endl;
	std::cout << "StudentOf42:" << originalData.studentOf42 << std::endl;

	std::cout << "=== Serialization ===" << std::endl;
	uintptr_t serializedValue = Serializer::serialize(&originalData);
	std::cout << "Serialized value: " << serializedValue << std::endl;

	std::cout << "=== Deserialization ===" << std::endl;
    Data* deserializedPtr = Serializer::deserialize(serializedValue);
    std::cout << "Deserialized address: " << deserializedPtr << std::endl;

	std::cout << "=== TEST ===" << std::endl;
    if (originalPtr == deserializedPtr)
	{
        std::cout << "SUCCESS: \"DataAddress\" Restoration OKKKKK" << std::endl;
		std::cout << "=== Deserialized Data ===" << std::endl;
		std::cout << "Name       :" << deserializedPtr->name << std::endl;
		std::cout << "Age        :" << deserializedPtr->age << std::endl;
		std::cout << "StudentOf42:" << deserializedPtr->studentOf42 << std::endl;
	}
	else
	{
		std::cout << "FAIL: \"DataAddress\" Restoration NOOOOOO" << std::endl;
		std::cout << "originalPtr ==" << originalPtr << std::endl;
		std::cout << "deserializedPtr ==" << deserializedPtr << std::endl;
	}
	// // これは不可能（インスタンス化が禁止されているため）
	// Serializer s;  // コンパイルエラー（privateコンストラクタ）
	return (0);
}