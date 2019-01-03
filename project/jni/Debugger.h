/********************************
*
* @file          Debugger.h
* @brief        基于ptrace的Debugger库
* @author     预知未来
* @email       2350867013@qq.com
* @version    1.0.0.1
* @date         2018-8-5
********************************/
#include <asm/ptrace.h>

typedef unsigned char    u1;
typedef unsigned short   u2;
typedef unsigned int     u4;
typedef unsigned long    u8;

#if defined(__arm__)
#define regs uregs
#define PC ARM_pc
#define LR ARM_lr
#define SP ARM_sp
#define CPSR ARM_cpsr

#elif defined(__aarch64__)
#define pt_regs user_pt_regs
#define PC pc
#define LR regs[30]
#define SP sp
#define CPSR pstate

#endif

extern int Debugger_Attach(u2);
extern int Debugger_Detach(u2);
extern int Debugger_Start(u2, u4);
extern int Debugger_Stop(u2);
extern int Debugger_getRegs(u2, struct pt_regs*);
extern int Debugger_setRegs(u2, struct pt_regs*);
extern void Debugger_getMemory(u2, u8, u1*, u4);
extern void Debugger_setMemory(u2, u8, u1*, u4);
extern int Debugger_Wait(u2, u4);
extern u8 Debugger_Call(u2, u8, u1, ...);

extern u8 RemoteCall_GetMemoryAddr(u2, const char*, const char*);
extern u8 RemoteCall_malloc(u2, u4);
extern u8 RrmoteCall_calloc(u2, u4, u4);
extern u8 RemoteCall_free(u2, u8);
extern u8 RemoteCall_NewString(u2, const char*);
extern u8 RemoteCall_puts(u2, const char*);
extern u8 RemoteCall_dlopen(u2, u8, int);
extern u8 RemoteCall_dlsym(u2, u8, u8);
extern u8 RemoteCall_dlclose(u2, u8);
extern int RemoteCall_SoInject(u2, const char*);
