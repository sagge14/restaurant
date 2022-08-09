//
// Created by Sg on 09.08.2022.
//
#include <thread>
#include <mutex>
#include <iostream>
using namespace std;
extern int countReady;
extern int countDelivered;
string nameOder();
static mutex kitchen_access;
static mutex oderCount_access;
void orderCreate();
void delivery();
void order(int i, string name);
