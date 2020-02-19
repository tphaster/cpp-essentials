/**
 *        File:  FactoryMethod-ParametrisedCreator.cpp
 * Description:  The Factory Method with a parametrised Creator class example.
 *
 *      Author:  Tomasz Pieczerak <tphaster AT gmail.com>
 */

#include <iostream>     // std::cout, std::operator<<
#include <memory>       // std::unique_ptr

/* A family of classes with an interface defined by a base class Product */
class Product
{
public:
	virtual void print() = 0;
	virtual ~Product() {};
};

class ProductOne : public Product
{
public:
	void print() override { std::cout << "ProductOne\n"; }
};

class ProductTwo : public Product
{
public:
	void print() override { std::cout << "ProductTwo\n"; }
};

class CustomProductOne : public Product
{
public:
	void print() override { std::cout << "CustomProductOne\n"; }
};

/* Enumeration class to identify concrete products */
enum class ProductId
{
	ONE,
	TWO,
	// ...
};

/* Creator base class provides default Create() method implementation */
class Creator
{
public:
	static std::unique_ptr<Product> Create(ProductId id)
	{
		if (id == ProductId::ONE)
			return std::make_unique<ProductOne>();
		else if (id == ProductId::TWO)
			return std::make_unique<ProductTwo>();
		else
			return nullptr;
	}
};

/* Custom Creator alters Creator base class behaviour */
class CustomCreator : public Creator
{
public:
	static std::unique_ptr<Product> Create(ProductId id)
	{
		if (id == ProductId::ONE)
			return std::make_unique<CustomProductOne>();
		else
			return Creator::Create(id);
	}
};
