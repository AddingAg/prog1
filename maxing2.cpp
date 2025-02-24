#include <iostream>
#include <vector>

int main() {
    std::vector<char*> memoryChunks;

    size_t chunkSize = 1024 * 1024 * 10;
    size_t totalMemory = 0;

    while (true) {
        char* chunk = new char[chunkSize];
        memoryChunks.push_back(chunk);

        totalMemory += chunkSize;

        std::cout << "Allocated memory: " << totalMemory / (1024 * 1024) << " MB" << std::endl;
    }

    return 0;
}
