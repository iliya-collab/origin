#include "IShape.h"

void printInfo(IShape* sh)
{
    sh->printInfo();
    delete sh;
}