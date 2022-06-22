#include <cpuinfo/cpuinfo.h>
#include <stdio.h>


int main(void)
{
	// Get CPU vendor ID.
	
	printf("CPU VENDOR: %s\n", get_vendor());

	return 0;
}
