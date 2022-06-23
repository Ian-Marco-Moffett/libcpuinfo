#include <cpuinfo/cpuinfo.h>
#include <stdio.h>


int main(void)
{
	// Get CPU vendor ID.
	
	printf("CPU VENDOR: %s\n", cpu_get_vendor());
    printf("MODEL NUMBER: 0x%X\n", cpu_get_model_number());
    printf("FAMILY VALUE: 0x%X\n", cpu_get_family_value());

	return 0;
}
