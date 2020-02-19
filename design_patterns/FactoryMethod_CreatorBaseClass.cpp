/**
 *        File:  FactoryMethod_CreatorBaseClass.cpp
 * Description:  The Factory Method with Creator base class example.
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

class ConcreteProductA : public Product
{
	void print() override { std::cout << "ProductA\n"; }
};

class ConcreteProductB : public Product
{
	void print() override { std::cout << "ProductB\n"; }
};

/* First approach: Creator class is an abstract class,
 * subclasses are required to provide Create() method implementation.
 */
class CreatorAbstract
{
public:
	void NewProduct()
	{
		m_product = Create();
	}

protected:
	virtual std::unique_ptr<Product> Create() = 0;

public:
	std::unique_ptr<Product> m_product;
};

class CustomCreatorA : public CreatorAbstract
{
protected:
	std::unique_ptr<Product> Create() override
	{
		return std::make_unique<ConcreteProductA>();
	}
};

/* Second approach: Creator class provides default Create() method
 * implementation, subclasses may override its behaviour.
 */
class Creator
{
public:
	void NewProduct()
	{
		m_product = Create();
	}

protected:
	virtual std::unique_ptr<Product> Create()
	{
		return std::make_unique<ConcreteProductA>();
	}

public:
	std::unique_ptr<Product> m_product;
};

class CustomCreatorB : public Creator
{
protected:
	std::unique_ptr<Product> Create() override
	{
		return std::make_unique<ConcreteProductB>();
	}
};
