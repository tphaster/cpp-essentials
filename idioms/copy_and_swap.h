/**
 *        File:  copy_and_swap.h
 * Description:  The copy-and-swap idiom example. It avoids code duplication
 *               and provides a strong exception guarantee in the assignment
 *               operator and move constructor implementations.
 *
 *      Author:  Tomasz Pieczerak <tphaster AT gmail.com>
 */

#include <algorithm>    // std::copy
#include <cstddef>      // std::size_t

class DumbArray
{
public:
	/* (default) constructor */
	DumbArray(std::size_t size = 0)
		: mSize(size), mArray(mSize ? new int[mSize]() : nullptr)
	{
	}

	/* copy-constructor */
	DumbArray(const DumbArray& other)
		: mSize(other.mSize), mArray(mSize ? new int[mSize] : nullptr)
	{
		// note: this one is non-throwing only because of the data types
		// used, in general case exceptions will need some attention
		std::copy(other.mArray, other.mArray + mSize, mArray);
	}

	/* assignment operator */
	DumbArray& operator=(DumbArray other)   // let the compiler make a copy
	{
		// there is no need for a self-assignment check
		swap(*this, other);

		return *this;
	}

	/* move constructor */
	DumbArray(DumbArray&& other)
		: DumbArray()   // initialize via default constructor, C++11 only
	{
		swap(*this, other);
	}

	/* destructor */
	~DumbArray()
	{
		delete [] mArray;
	}

	/* swap() - public friend function */
	friend void swap(DumbArray& first, DumbArray& second) // nothrow
	{
		// enable ADL (not necessary in our case, but good practice and also
		// an established idiom)
		using std::swap;

		// by swapping the members of two objects,
		// the two objects are effectively swapped
		swap(first.mSize, second.mSize);
		swap(first.mArray, second.mArray);
	}

private:
	std::size_t mSize;
	int* mArray;
};
