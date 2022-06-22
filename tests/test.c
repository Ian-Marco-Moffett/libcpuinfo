#include <cpuinfo/cpuinfo.h>
#include <stdio.h>


int main(void)
{
	// Get CPU vendor ID.
	
	printf("CPU VENDOR: %s\n", cpu_get_vendor());
    printf("MODEL NUMBER: 0x%X\n", cpu_get_model_number());

	return 0;
}
