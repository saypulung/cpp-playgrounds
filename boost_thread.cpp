#include <iostream>
#include <boost/foreach.hpp>
#include <vector>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
using namespace std;
void wait(int seconds)
{
boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}
void thread()
{
  for (int i = 0; i < 5; ++i)
  {
    wait(1);
    std::cout << i << '\n';
  }
}

int main(int argc, char** argv) {
	vector<int> test = {0,5,10,3,};
	BOOST_FOREACH(int &val, test) {
		cout<<val<<endl;
	}
	boost::thread t{thread};
  	t.join();
	return 0;
}
