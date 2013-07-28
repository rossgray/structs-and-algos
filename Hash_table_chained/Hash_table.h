
#include <string>
#include <cmath>
#include <iostream>


template <class T>
class element
{
	public:
        element(const T& iData): data(iData){};
    
		void setData(const T& iData) {data = iData;}
		T getData() const {return data;}

		void setNext(element * iElem) {next = iElem;}
		element * getNext() const {return next;}

	private:
		element * next;
		T data;
};



template <class T>
class hashTable
{
public:
	hashTable(const int iSize):size(iSize) {table = new element<T>*[iSize];}
	~hashTable();
	bool insertElem(const T& iData);
	bool deleteElem(const T& iData);
	bool findElem(const T& iData);
    void displayTable();

private:
	int hash(const T& iData);

	element<T> ** table; //pointer to hash table
	int size;
};



// implementations
template<class T>
hashTable<T>::~hashTable()
{
    element<T> * currElem;
    element<T> * nextElem;
    for (int i=0; i < size; ++i)
    {
        currElem = table[i];
        while (currElem)
        {
            nextElem = currElem->getNext();
            delete currElem;
            currElem = nextElem;
        }
    }
}



template <> int hashTable<std::string>::hash(const std::string& iData)
{
    // hash key using simple linear hashing

	// convert string to int using radix-128
	unsigned int strInt = 0;
	int charInt;
	for (unsigned int i=0; i < iData.size(); ++i)
	{
		charInt = iData[iData.size()-1-i];
		if (charInt > 128 || charInt < 0)
		{
			std::cout << "ERROR: charInt > 128" << std::endl;
		}
		strInt += pow(128, i)*charInt;
	}
	/*std::cout << "strInt = " << strInt << std::endl;
	std::cout << "hashing to " << strInt % size << std::endl;*/
	return strInt % size;
    
}



template <class T>
bool hashTable<T>::insertElem(const T& iData)
{
    bool success = true;
    // first check if element has already been added or not
    if (findElem(iData))
    {
        std::cout << "Data already present in table!" << std::endl;
        return false;
    }
    
	// find slot to hash to
    int slot = hash(iData);
    
    // insert element at front of list
    element<T> * newData = new element<T>(iData);
    if (newData)
    {
        newData->setNext(table[slot]);
        table[slot] = newData;
        std::cout << "Insert successful" << std::endl;
    }
    else
        success = false;
    
    return success;
}


template <class T>
bool hashTable<T>::findElem(const T& iData)
{
    
    // find slot
    int slot = hash(iData);
    element<T> * currElem = table[slot];
    // search linked list
    while (currElem)
    {
        if (currElem->getData() == iData)
        {
            return true;
        }
        currElem = currElem->getNext();
    }
    return false;
}


template <class T>
bool hashTable<T>::deleteElem(const T& iData)
{
    
    // find slot
    int slot = hash(iData);
    element<T> * currElem = table[slot];
    element<T> * prevElem;
    
    while (currElem)
    {
        if (currElem->getData() == iData)
        {
            // check special case of element at head of list
            if (currElem == table[slot])
            {
                table[slot] = currElem->getNext();
                delete currElem;
                return true;
            }
            
            prevElem->setNext(currElem->getNext());
            delete currElem;
            return true;
        }
        prevElem = currElem;
        currElem = currElem->getNext();
    }
    return false;
}

template <class T>
void hashTable<T>::displayTable()
{
    std::cout << std::endl << "Displaying table" << std::endl;
    element<T> * currElem;
    for (int i=0; i < size; ++i)
    {
        std::cout << "SLOT: " << i << std::endl;
        currElem = table[i];
        while (currElem)
        {
            std::cout << "    Item: " << currElem->getData() << std::endl;
            currElem = currElem->getNext();
        }
    }
}
