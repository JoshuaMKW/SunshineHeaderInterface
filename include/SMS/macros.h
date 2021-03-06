#pragma once

#include <Dolphin/OS.h>
#include <Dolphin/PPCArch.h>
#include <Dolphin/printf.h>

#define SMS_STRINGIZE_(x) #x
#define SMS_STRINGIZE(x)  SMS_STRINGIZE_(x)

#define SMS_WIDE_(s) L##s
#define SMS_WIDE(s)  SMS_WIDE_(s)

#define SMS_CONCATENATE_(a, b) a##b
#define SMS_CONCATENATE(a, b)  SMS_CONCATENATE_(a, b)

#if !defined(NTSCU) && !defined(PAL) && !defined(NTSCJ) && !defined(NTSCK)
#define NTSCU
#endif

#if defined(NTSCU)
#define SMS_PORT_REGION(ntscu, pal, ntscj, ntsck) ntscu
#elif defined(PAL)
#define SMS_PORT_REGION(ntscu, pal, ntscj, ntsck) pal
#elif defined(NTSCJ)
#define SMS_PORT_REGION(ntscu, pal, ntscj, ntsck) ntscj
#elif defined(NTSCK)
#define SMS_PORT_REGION(ntscu, pal, ntscj, ntsck) ntsck
#else
#error "No region provided!"
#endif

#define SMS_FROM_GPR(reg, var) asm volatile("mr %0, " #reg : "=r"(var))
#define SMS_TO_GPR(reg, var)   asm volatile("mr " #reg ", %0" : : "r"(var))
#define SMS_FROM_FPR(reg, var) asm volatile("fmr %0, " #reg : "=r"(var))
#define SMS_TO_FPR(reg, var)   asm volatile("fmr " #reg ", %0" : : "r"(var))

#ifdef __cplusplus
#if __cplusplus >= 201103L
#define offsetof(t, d) ((size_t) & (((t *)0)->d))
//#define offsetof(t, d) __builtin_offsetof(t, d)
#else
#define offsetof(t, d) ((size_t) & (((t *)0)->d))
#endif
#define SMS_EXTERN_C extern "C"
#else
#define SMS_EXTERN_C extern
#endif

#define SMS_NO_INLINE __attribute__((noinline))

#define SMS_ATOMIC_CODE(code)                                                                      \
    u32 __atomic_interrupt_state = OSDisableInterrupts();                                          \
    code OSRestoreInterrupts(__atomic_interrupt_state);

#ifdef __MWERKS__
#define SMS_REGISTER register
#define SMS_PURE_ASM asm
#else
#define SMS_REGISTER
#define SMS_PURE_ASM __attribute__((naked))
#endif

#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) ||                        \
    (defined(__ICC) && (__ICC >= 600))
#define SMS_FUNC_SIG __PRETTY_FUNCTION__
#elif defined(__FUNCSIG__)
#define SMS_FUNC_SIG __FUNCSIG__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#define SMS_FUNC_SIG __func__
#else
#define SMS_FUNC_SIG "UNDEFINED"
#endif

#define SMS_CALL_NAIVE(addr, ...) ((void (*)(...))addr)(__VA_ARGS__)