/* { dg-do compile } */
/* { dg-options "-march=rv64g_zacas -mabi=lp64d" } */

int var;

void foo1(void *mem, __int128 old, __int128 new)
{
    __builtin_riscv_amocas128(0, old, new, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    __builtin_riscv_amocas128(&var, old, new, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    __builtin_riscv_amocas128((void *)0x111, old, new, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    __builtin_riscv_amocas128(mem, old, new, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
}

/* { dg-final { scan-assembler-times "amocas.q" 4 } } */
