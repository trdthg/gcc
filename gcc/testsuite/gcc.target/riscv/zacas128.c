/* { dg-do compile } */
/* { dg-options "-march=rv64g_zacas -mabi=lp64d" } */

int var;

void foo1(void *mem, __int128 old, __int128 new)
{
    __builtin_riscv_amocas128(0, old, new, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    __builtin_riscv_amocas128(&var, old, new, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED);
    __builtin_riscv_amocas128((void *)0x111, old, new, __ATOMIC_RELAXED, __ATOMIC_RELEASE);
    __builtin_riscv_amocas128(mem, old, new, __ATOMIC_ACQUIRE, __ATOMIC_RELEASE);
    __builtin_riscv_amocas128(mem, old, new, __ATOMIC_ACQ_REL, __ATOMIC_ACQ_REL);
    __builtin_riscv_amocas128(mem, old, new, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
}

/* { dg-final { scan-assembler-times "amocas.q" 6 } } */
/* { dg-final { scan-assembler-times "amocas.q.aq" 4 } } */
/* { dg-final { scan-assembler-times "amocas.q.rl" 1 } } */
/* { dg-final { scan-assembler-times "amocas.q.aqrl" 3 } } */
