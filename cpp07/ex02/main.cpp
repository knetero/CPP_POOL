#include "Array.hpp"
#include <exception>


int main()
{
    Array<int> emptyArray;
    std::cout << "intArray size: " << emptyArray.size() << std::endl;

    Array<int> intArray(5);
    Array<std::string> stringArray(3);


    std::cout << "intArray size: " << intArray.size() << std::endl;
    std::cout << "stringArray size: " << stringArray.size() << std::endl;

    try{
        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i;

        for (unsigned int i = 0; i < stringArray.size(); i++)
            stringArray[i] = "string";

        for (unsigned int i = 0; i < intArray.size(); i++)
        {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        for (unsigned int i = 0; i < stringArray.size(); i++) {
            std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
        }
        // stringArray[5165] = "string";
        
    }
    catch(std::exception &e){
        std::cout << "index out of range !!" << std::endl;
    }
}