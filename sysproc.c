#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "vga.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
void
sys_modeswitch(void)
{
  int mode;
  argint(0, &mode);
  modeswitch(mode);
}

void
sys_plotpixel(void)
{
  int x;
  int y;
  int color;
  argint(0, &x);
  argint(1, &y);
  argint(2, &color);
  plotpixel(x,y,color);
}

void
sys_plotrectangle(void)
{
  int x1;
  int y1;
  int x2;
  int y2;
  int color;
  argint(0, &x1);
  argint(1, &y1);
  argint(2, &x2);
  argint(3, &y2);
  argint(4, &color);
  plotrectangle(x1, y1, x2, y2, color);
}