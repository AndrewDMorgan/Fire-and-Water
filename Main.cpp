#include <iostream>
#include <thread>


// ------------------------- general globals -------------------------

// height map stuff

const int SIZE_X = 30480;
const int SIZE_Y = 30480;

float heightMap[SIZE_X][SIZE_Y];

// the properties for water

const int DROPS = 10;



// ------------------------- Simulation Things -------------------------

// runs the simulation on the dropplets

void SimulateDropplets()
{
    // simulating things
}



// ------------------------- Threading Things -------------------------

// A class to wrap up all the random things

class Thread
{
    // the threads being run through
    std::thread *threads;

public:
    // the constructors
    template <typename F>
    Thread(F function)
    {
        // allocating the memory of the threads
        threads = (std::thread*) malloc(sizeof(std::thread) * DROPS);

        // creating the threads
        for (int i = 0; i < DROPS; i++)
        {
            // creating the thread and adding it
            threads[i] = std::thread(function);
        }
    }

    // joining all the threads
    void Join() { for (int i = 0; i < DROPS; i++) threads[i].join(); }

    // freeing the memory
    ~Thread() { free(threads); }
};



// ------------------------- Main Functions -------------------------

// the main function, called on startup
int main()
{
    // creating the queue for the simulation
    Thread threads = Thread(SimulateDropplets);

    // adding the simulation to the main thread
    threads.Join();

    // ending the simulation
    return 0;
}
