#include <iostream>
#include <vector>
#include <thread>
#include <climits>

void compute(int id) {
    unsigned long long int l = 1;
    while (true) {
        for (int i = 1; i < INT_MAX; i++) {
            l ^= (i * 16876481) % 87126712481;
        }
        if (id == 0 && (l % 1000000000 == 0)) { 
            std::cout << "Thread " << id << " intermediate result: " << l << std::endl;
        }
    }
}

int main() {
    unsigned int numThreads = std::thread::hardware_concurrency();
    std::cout << "Number of available CPU cores: " << numThreads << std::endl;

    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(compute, i));
    }

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}
