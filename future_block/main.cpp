#include <algorithm>
#include <thread>
#include <iostream>
#include <chrono>
#include <future>

using std::cout; using std::endl;

int get_pizza() {
	cout << "start cook pizza" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "pizza finished" << endl;
	int pizza = 2;
	return pizza;	
}

void do_work1() {
	cout << "In work1" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "work1 done" << endl;
}

void do_work2() {
	cout << "In work2" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	cout << "work2 done" << endl;
}


int main() {
	std::async(do_work1); // ~future blocks
	std::async(do_work2); // ~future blocks

	auto pizza = std::async(get_pizza);
	bool need_to_go = true;
 	if(need_to_go) {
		cout << "actually don't need wait" << endl;
        return 0;          // ~future will block
	}
    else {
       pizza.get();
	   cout << "eat pizza" << endl;
	}
	return 0;
}
