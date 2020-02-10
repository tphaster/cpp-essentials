/**
 *        File:  covariant_return.cpp
 * Description:  The covariant return types idiom example. Avoid unnecessary
 *               casting of the derived value returned from an overridden
 *               method in a derived class.
 *         Ref:  https://www.lwithers.me.uk/articles/covariant.html
 *
 *      Author:  Tomasz Pieczerak (tph) <tphaster AT gmail.com>
 */

class Base
{
public:
	virtual Base* clone() const
	{
		return new Base(*this);
	}
};

class Derived : public Base
{
public:
	/* override base class method - return Derived pointer, not Base pointer */
	virtual Derived* clone() const override
	{
		return new Derived(*this);
	}
};

int main (void)
{
	Derived *d1 = new Derived();
	// now we can avoid this:
	//   Base *b = d1->clone();
	//   Derived *d2 = dynamic_cast<Derived*>(b);
	Derived *d2 = d1->clone();

	if (d2 != nullptr) {
		// use d2 here
	}
}
