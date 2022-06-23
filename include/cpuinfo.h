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


#ifndef CPUINFO_H
#define CPUINFO_H

#include <stdint.h>
#include <stdbool.h>


// Feature bits reported in CPUID[EDX].
typedef enum
{
	CPU_FPU			= 	(1 << 0),			// Floating point unit.
	CPU_VME 		= 	(1 << 1), 			// Virtual mode exntension.
	CPU_DE 			= 	(1 << 2), 			// Debugging extension.
	CPU_PSE 		= 	(1 << 3),			// Page size extension.
	CPU_TSC 		= 	(1 << 4), 			// Time Stamp Counter.
	CPU_MSR 		= 	(1 << 5),			// Model specific registers.
	CPU_PAE 		= 	(1 << 6),			// Physical address extension.
	CPU_MSE 		= 	(1 << 7), 			// Machine check exception.
	CPU_CX8 		= 	(1 << 8), 			// CMPXCHG8 instruction.
	CPU_APIC 		= 	(1 << 9), 			// APIC.
	CPU_SEP 		= 	(1 << 11), 			// Fast system call.
	CPU_MTRR 		= 	(1 << 12), 			// Memory type range registers.
	CPU_PGE 		= 	(1 << 13),			// Page global enable.
	CPU_MCA 		= 	(1 << 14),			// Machine check architecture.
	CPU_CMOV		=	(1 << 15),			// Conditional move instruction.
	CPU_PAT 		= 	(1 << 16), 			// Page attribute table.
	CPU_PSE36 		= 	(1 << 17), 			// 36-bit page size extension.
	CPU_PSN 		= 	(1 << 18), 			// Processor serial number present and enabled.
	CPU_ACPI		=	(1 << 22), 			// ACPI.
	CPU_MMX 		= 	(1 << 23), 			// MMX.
	CPU_FXSR		= 	(1 << 24), 			// FXSAVE and FXSTOR instructions.
	CPU_SSE 		= 	(1 << 25), 			// Streaming SIMD extensions.
	CPU_SSE2 		= 	(1 << 26), 			// Streaming SIMD extensions 2.
	CPU_SS			=	(1 << 27), 			// Self snoop.
	CPU_HTT			=	(1 << 28),			// Multi-threading.
	CPU_TM			=	(1 << 29),			// Thermal monitor.
	CPU_PBE			=	(1 << 31),			// Pending break enable.
} CPU_FEATURE;


// CPU feature flags from CPUID[ECX].
// Got tired of aligning the text lol.
typedef enum {
	CPU_SSE3 = (1 << 0),		// Streaming SIMD extensions 3.
	CPU_PCLMULDQ = (1 << 1),	// PCMULDQ instruction.
	CPU_DTES64 = (1 << 2),		// 64-Bit Debug Store.
	CPU_MONITOR = (1 << 3),	// MONITOR/MWAIT instructions.
	CPU_DSCPL = (1 << 4),	// CPL Qualified Debug Store.
	CPU_VMX	= (1 << 5),	// Virtual machine extensions.
	CPU_SMX	= (1 << 6),	// Safer mode extensions.
	CPU_EST = (1 << 7),	// Enhanced Intel SpeedStep(R) technology.
	CPU_TM2 = (1 << 8),	// Terminal monitor 2.
} CPU_FEATURE_ECX;


/*
 *  CPU vendor (i.e intel).
 */
char* cpu_get_vendor(void);

// For CPUID:1[EDX]
bool cpu_has_feature(CPU_FEATURE feat);

// For CPUID:1[ECX] (basically just more features).
bool cpu_has_feature_ecx(CPU_FEATURE_ECX feat);

// Counts how many thermal control circuits there is.
uint8_t cpu_get_n_tcc_count(void);

// Fetches model number.
uint8_t cpu_get_model_number(void);

// Get family value.
uint32_t cpu_get_family_value(void);

#endif
