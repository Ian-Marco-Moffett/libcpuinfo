/*
 *  MIT License
 *
 *  Copyright (c) 2022 Nexus-C, Ian Marco Moffett
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */


#include <string.h>
#include <stdint.h>
#include <vendors.h>


static uint32_t eax, ebx, ecx, edx;


static inline void cpuid(uint32_t leaf, uint32_t* eax, uint32_t* ebx, uint32_t* ecx, uint32_t* edx)
{
  __asm__ __volatile__("cpuid"
               : "=a"(*eax), "=b"(*ebx), "=c"(*ecx), "=d"(*edx)
               : "a"(leaf), "c"(0x0)
               : "memory");
}


static char* get_vendor_string(void)
{
	cpuid(0, &eax, &ebx, &ecx, &edx);

	// An array to store vendor string.
	// String is stored in EBX, ECX, and EDX.
	static char vendor_string[13];

	// Vendor string index.
	uint64_t vendor_str_idx = 0;
	
	// Fetch vendor string.
	for (uint8_t i = 0; i < sizeof(ebx); ++i, ebx >>= 8)
	{
		vendor_string[vendor_str_idx++] = ebx;
	}

	for (uint8_t i = 0; i < sizeof(edx); ++i, edx >>= 8)
	{
		vendor_string[vendor_str_idx++] = edx;
	}

	for (uint8_t i = 0; i < sizeof(ecx); ++i, ecx >>= 8)
	{
		vendor_string[vendor_str_idx++] = ecx;
	}

	vendor_string[vendor_str_idx] = '\0';

	return vendor_string;
}


char* get_vendor(void)
{
	char* vendor_str = get_vendor_string();

	if (strcmp(vendor_str, CPUID_VENDOR_AMD) == 0)
    {
        return "AMD";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_INTEL) == 0)
    {
        return "INTEL";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_VIA) == 0)
    {
        return "VIA";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_TRANSMETA) == 0)
    {
        return "TRANSMETA";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_CYRIX) == 0)
    {
        return "CYRIX";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_CENTAUR) == 0)
    {
        return "CENTUAR";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_NEXGEN) == 0)
    {
        return "NEXTGEN";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_UMC) == 0)
    {
        return "UMC";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_SIS) == 0)
    {
        return "SIS";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_RISE) == 0)
    {
        return "RISE";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_VORTEX) == 0)
    {
        return "VORTEX";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_AO486) == 0)
    {
        return "AO486";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_ZHAOXIN) == 0)
    {
        return "ZHAOXIN";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_HYGON) == 0)
    {
        return "HYGON";
    }
    else if (strcmp(vendor_str, CPUID_VENDOR_ELBRUS) == 0)
    {
        return "ELBRUS";
    }
    else
    {
        return "UNKNOWN";
    }
}
