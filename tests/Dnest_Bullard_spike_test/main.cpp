#include <iostream>
#include "Data.h"
#include "DNest4.h"
#include "BullardSpike.h"

using namespace std;
using namespace DNest4;

int main(int argc, char** argv)
{
	Data::get_instance().load("dat.txt");
	start<BullardSpike>(argc, argv);
	return 0;
}

