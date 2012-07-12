#include "StdAfx.h"
#include "IDatabase.h"
#include <iostream>


IDatabase::IDatabase()
{
	std::cout << "Constructor" <<std::endl;
}

IDatabase::~IDatabase()
{
	std::cout << "Destructor" <<std::endl;
}

IQuery::IQuery()
{
	std::cout << "Constructor" <<std::endl;
}

IDBException::IDBException()
{
	std::cout << "Constructor" <<std::endl;
}
