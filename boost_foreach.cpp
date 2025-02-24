#include <boost/foreach.hpp>
#include <iostream>

using namespace std;

int main()
{
	int data[3] = {1,2,3};
	BOOST_FOREACH(int &v, data) {
		cout<<"Value : "<<v<<endl;
	}
	return 0;
}