#include <stdio.h>
#include <cpuinfo/cpuinfo.h>

int main(void) {
	printf("%s\n", get_vendor());
}
