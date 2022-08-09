#include <iostream>
#include <thread>
#include "restoran.h"
using namespace std;
int main() {
    std::cout << "---Restaurant---" << std::endl;
    thread myThread1(orderCreate);
    myThread1.detach();
    thread myThread2(delivery);
    myThread2.join();
    cout << "---Bye, bye---" << endl;
    return 0;
}
