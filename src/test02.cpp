#include <stdio.h>
#include <unistd.h>
#include <iostream>

#define INCREMENTS  10

using namespace std;

void progress_bar(unsigned int progress) {
    if (progress > 100)
        progress = 100;
    
    if (progress < 100)
        progress = (progress / INCREMENTS) * INCREMENTS;

    cout << "\r" << string(16, ' ');            
    cout << "\r";                               

    cout << "|";
    cout << string(progress/INCREMENTS, '=');   
    if (progress < 100) {
        cout << ">";                                               
        cout << string(100/INCREMENTS-1-progress/INCREMENTS, ' ');  
    }
    
    cout << "|";
}

int main() {
    
    for (int p=0; p<=100; p+=5) {
        progress_bar(p);
        cout << " " << p << "%" << flush;
        sleep(1);   
    }
    cout << endl;
}

