#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

const int WIDTH = 40;
const int HEIGHT = 30;


int ballX = WIDTH / 2;
int ballY = HEIGHT / 2;
int dirX = 1;  
int dirY = 1;  


void draw() {
    
    system("cls"); 

    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1) {
                cout << "#"; 
            }
            else if (x == 0 || x == WIDTH - 1) {
                cout << "#"; 
            }
            else if (x == ballX && y == ballY) {
                cout << "o"; 
            }
            else {
                cout << " "; 
            }
        }
        cout << endl;
    }
}

int main() {
    while (true) {
        draw();

        
        ballX += dirX;
        ballY += dirY;

        
        if (ballX <= 1 || ballX >= WIDTH - 2) dirX = -dirX;
        if (ballY <= 1 || ballY >= HEIGHT - 2) dirY = -dirY;

        
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    return 0;
}
