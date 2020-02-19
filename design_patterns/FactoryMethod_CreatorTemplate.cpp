/**
 *        File:  FactoryMethod_CreatorTemplate.cpp
 * Description:  The Factory Method with Creator template example.
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

/* Creator is an abstract class, subclasses have a template parameter
 * and can handle many concrete products.
 */
class Creator
{
public:
	virtual std::unique_ptr<Product> Create() = 0;
};

template<class TheProduct>
class StandardCreator : public Creator
{
public:
	std::unique_ptr<Product> Create() override
	{
		return std::make_unique<TheProduct>();
	}
};

int main(void)
{
	StandardCreator<ConcreteProductA> ca;
	StandardCreator<ConcreteProductB> cb;

	//...

	return 0;
}
