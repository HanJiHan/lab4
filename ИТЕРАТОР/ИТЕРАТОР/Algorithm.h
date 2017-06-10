#include"Iterator.h"
template <class T>
class Algorithm
{

public:

	static void swap(Iterator<T> *it1, Iterator<T> *it2)
	{

		Iterator<T> it3;
		it3 = *it1;
		*it1 = *it2;
		*it2 = it3;
	}

	static void sort(Iterator<T> it1)
	{

		Iterator<T> bufStatic;
		Iterator<T> bufStatic2;
		Iterator<T> rememberME;
		Iterator<T> rememberME2;

		bufStatic = it1.getPtr(); 
		bufStatic2 = it1.getPtr();
		bufStatic2++;
		bufStatic++;
		for (bufStatic2; bufStatic2.eos(); bufStatic2++)
		{

			for (bufStatic; bufStatic.eos(); bufStatic++)
			{
				rememberME = bufStatic.getPtr();
				rememberME2 = bufStatic.getPtr();
				rememberME2--;

					if (rememberME2.getPtr()->getData() > rememberME.getPtr()->getData())
						swap(&rememberME, &rememberME2);
			}
			bufStatic = it1.getPtr();
			bufStatic++;
		}
	}

	static void find(Iterator<T> it1, Product &pr)
	{
		for (it1; it1.eos(); it1++)
		{
			if (it1.getPtr()->getData() == pr)
				cout << it1;
		}
	}
};