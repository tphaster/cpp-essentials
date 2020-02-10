/**
 *        File:  pass_by_value_and_move.h
 * Description:  The pass-by-value-and-move idiom example and other ways to
 *               consider. Generic rule is to pass by value for copyable
 *               parameters that are cheap to move and always copied. In other
 *               cases use overloading for lvalues/rvalues or forwarding
 *               reference.
 *         Ref:  Scott Meyers, Effective Modern C++, Item 41
 *
 *      Author:  Tomasz Pieczerak <tphaster AT gmail.com>
 */

#include <vector>
#include <string>

class WidgetPassByValue
{
public:
	// Passing by value and moving gives the simplest code, but there is one
	// additional move operation for both lvalues and rvalues. May be used for
	// arguments that are:
	//  - copyable - if not, single function with rvalue argument is enough
	//  - always copied - if not, use Forwarding Reference
	//  - cheaply movable - if not use Overload or Forwarding Reference
	//  - parameter is copied via construction - if not, use Overload
	//  - parameter is NOT a base class type (slicing problem!)
	void addName(std::string newName)
	{ names.push_back(newName); }

private:
	std::vector<std::string> names;
};

class WidgetOverload
{
public:
	// Most efficient approach, but requires two functions to maintain and
	// gets complicated as more arguments are added.
	void addName(const std::string& newName)
	{ names.push_back(newName); }

	void addName(std::string&& newName)
	{ names.push_back(std::move(newName)); }

private:
	std::vector<std::string> names;
};

class WidgetForwardingReference
{
public:
	// Most universal solution, but may generate a lot of functions in the
	// object code and give intimidating error messages with improper arguments.
	template<typename T>
	void addName(T&& newName)
	{ names.push_back(std::forward<T>(newName)); }

private:
	std::vector<std::string> names;
};
