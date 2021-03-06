/*! 
 *  \mainpage Bubble Sort
 *  \section intro_sec Description
 *  There is example of using bubble sort based on templates.
 */

/*!
 *  \file main.cpp 
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/* IMPORTANT NOTE:
   Using atoi() instead of stoi()
   atoi() can convert words to 0 value unlike stoi()
   Simple protection from fools */

/*! 
 *  \brief String-splitting algorithm.
 *  \param string Reference to splitted string.
 *  \param delim Delimiter for splitting.
 *  \return items Vector of source string parts.
 */
std::vector <std::string> split(std::string &string, char delim) 
{
    std::vector <std::string> items;
    std::stringstream stringStream (string);
    std::string item;

    while (std::getline(stringStream, item, delim))
        if (item.size())
            items.push_back(item);

    return items;
}

/*! 
 *  \brief Bubble Sort function.
 *  \param v Reference to sorted vector.
 *  \return Function returns nothing.
 */
template <typename T > void bubbleSort(std::vector<T>& v)
{
    for (std::size_t i = 0; v.size() && i < v.size() - 1; i ++)
        for (std::size_t j = i; j + 1 > 0; j --)
            if(v[j] > v[j + 1])
                std::swap(v[j], v[j + 1]);
}


/*! 
 *  \brief Getting information about vector size.
 *  \return Function returns nothing.
 */
int getSize()
{
    int vSize;
    std::string str;

    do
    {
        std::cout << "Vector size: ";
        std::cin >> str;

        vSize = atoi(str.c_str());
        if (vSize < 1)
            std::cout << "Bad vector size." << std::endl;
    }
    while (vSize < 1);

    return vSize;
}

/*! 
 *  \brief Getting vector based on its size.
 *  \details Vector has integer type.
 *  \param vSize Vector size.
 *  \return Function returns nothing.
 */
std::vector<int> getVector(int vSize)
{
    std::vector<int> v;
    std::string str;
    std::vector<std::string> numbers;

    bool successCode;

    do
    {
        std::cout << std::endl << "Vector elements: ";

        successCode = true;

        fflush (stdin);
        getline (std::cin, str);
        numbers = split(str, ' ');

        if (numbers.size() != vSize)
        {
            std::cout << "Number count should be " << vSize << std::endl;
            successCode = false;
        }
    }
    while (!successCode);

    for (std::vector<std::string>::iterator i = numbers.begin(); i != numbers.end(); i ++)
        v.push_back(atoi((*i).c_str()));

    return v;
}


/*! 
 *  \brief Program entry point.
 *  \details User takes integer vector and sorts it using bubble sort.
 */
void main()
{
    std::vector<int> v = getVector(getSize());

    bubbleSort (v);

    std::cout << std::endl << "Bubble sorted array: ";
    for (std::vector<int>::iterator i = v.begin(); i != v.end(); i ++)
        std::cout << *i << " ";

    std::cout << std::endl << std::endl;
}
