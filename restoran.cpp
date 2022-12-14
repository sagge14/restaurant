//
// Created by Sg on 09.08.2022.
//
#include <cstdlib>
#include "restoran.h"
int countReady = 0;
int countDelivered = 0;
string nameOder(){

    srand(time(nullptr));
    int r = rand() % 5;

    if(r == 0)
        return "pizza";
    else if (r == 1)
        return  "soup";
    else if (r == 2)
        return  "steak";
    else if (r == 3)
        return  "salad";
    else
        return  "sushi";
}
void order(int i, string name)
{

    srand(time(nullptr));
    const lock_guard<std::mutex> lock(kitchen_access);
        this_thread::sleep_for(chrono::seconds(rand() % 6 + 10));
        {
            const lock_guard<std::mutex> lock2(oderCount_access);
            countReady++;
            cout << "Oder N" << i <<" - "<< name << " ready!"<< endl;
            cout << countReady << " orders are ready for delivery!"<< endl;
        }

}
void orderCreate()
{
    srand(time(nullptr));
    int i = 1;
    while(countDelivered < 10)
    {
        string name = nameOder();
        this_thread::sleep_for(chrono::seconds(rand() % 6 + 5));
        cout << "Oder N" << i <<" - "<< name << " has been received" << endl;
        thread myOder(order, i, name);
        myOder.detach();
        i++;
    }
}
void delivery()
{
    while(countDelivered < 10)
    {
        this_thread::sleep_for(chrono::seconds(30));
        const lock_guard<std::mutex> lock(oderCount_access);
            countDelivered += countReady;
            cout << "The courier took " << countReady << " orders." << " Total delivered orders count " <<  countDelivered << endl;
            countReady = 0;
    }

}