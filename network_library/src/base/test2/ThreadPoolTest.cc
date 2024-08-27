#include "ThreadPool.h"
//#include "Logging.h"
#include "CurrentThread.h"
#include <stdio.h>
#include <unistd.h>
#include <functional>
#include <chrono>
#include <iostream>
#include <unordered_map>
int count = 0;
std::unordered_map<int, int> countMap;
void showInfo()
{
    //printf("%d\n", CurrentThread::tid());
    int ss = 0;
    while(ss < 1000){
        ss++;
    }
     countMap[CurrentThread::tid()]++;
}

void test1()
{
    ThreadPool pool;
    pool.setThreadSize(10);
    for (int i = 0; i < 5000000; i++) 
    {
        //pool.add([]{sleep(1);});
        pool.add(showInfo);
    }
    pool.start();
    
    auto start = std::chrono::steady_clock::now();
    while(pool.queueSize() != 0){

    }
    auto end = std::chrono::steady_clock::now();
    for (const auto& pair : countMap) {
        std::cout << "Number " << pair.first << " occurs " << pair.second << " times." << std::endl;
    }
    printf("%ld\n", countMap.size());
    std::cout << "the time cost " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "us" << std::endl;
}

void initFunc()
{
    printf("Create thread %d\n", ++count);
}
#if 0
int main()
{
    test1();
    
    return 0;
}
#endif