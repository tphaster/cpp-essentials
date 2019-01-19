/**
 *        File:  covariant_return.cpp
 * Description:  The covariant return types idiom example.
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
    virtual Derived* clone() const override
    {
        return new Derived(*this);
    }
};

int main (void)
{
    Derived *d1 = new Derived();
    Derived *d2 = d1->clone();

    if (d2 != nullptr) {
        // use d2 here
    }
}
