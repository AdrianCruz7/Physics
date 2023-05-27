#include "Tests/ParticleTest.h"
#include "Tests/ForceTest.h"
#include "Tests/JointTest.h"
#include "Tests/CollisionTest.h"

int main(int argc, char* args[])
{
    Test* test = new ForceTest();

    test->Initialize();
    while (!test->IsQuit()) test->Run();
    delete test;
    
    return 0;
}