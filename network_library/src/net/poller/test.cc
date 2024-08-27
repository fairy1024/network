#include <iostream>
#include <thread>
#include <sys/eventfd.h>
#include <unistd.h>

void notifier(int efd) {
    for(int i = 0; i < 10; i++){
        sleep(1);  // Simulate some work
        uint64_t event = 1;
        write(efd, &event, sizeof(event));  // Notify the event
    }
}

void wait_for_event(int efd, int n) {
    uint64_t event;
    read(efd, &event, sizeof(event));  // Wait for the event
    std::cout << "Waiter: Event received, value = " << n << std::endl;
}

#if 0
int main() {
    int efd = eventfd(0, 0);  // Create an eventfd

    std::thread t1(notifier, efd);
    std::thread tt[10];
    for(int i = 0; i < 10; i++){
        tt[i] = std::thread(wait_for_event, efd, i);
    }
    t1.join();
    for(auto& ts: tt){
        ts.join();
    }
    close(efd);
    return 0;
}
#endlf
