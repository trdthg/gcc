/* { dg-do compile } */
/* { dg-options "-march=rv32g_zacas -mabi=ilp32" } */

void foo1(void *mem, int old, int new)
{
    __builtin_riscv_amocas32(mem, old, new, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    __builtin_riscv_amocas32(mem, old, new, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED);
    __builtin_riscv_amocas32(mem, old, new, __ATOMIC_RELAXED, __ATOMIC_RELEASE);
    __builtin_riscv_amocas32(mem, old, new, __ATOMIC_ACQUIRE, __ATOMIC_RELEASE);
    __builtin_riscv_amocas32(mem, old, new, __ATOMIC_ACQ_REL, __ATOMIC_ACQ_REL);
    __builtin_riscv_amocas32(mem, old, new, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
}

void foo2(void *mem, long long old, long long new)
{
    __builtin_riscv_amocas64(mem, old, new, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    __builtin_riscv_amocas64(mem, old, new, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED);
    __builtin_riscv_amocas64(mem, old, new, __ATOMIC_RELAXED, __ATOMIC_RELEASE);
    __builtin_riscv_amocas64(mem, old, new, __ATOMIC_ACQUIRE, __ATOMIC_RELEASE);
    __builtin_riscv_amocas64(mem, old, new, __ATOMIC_ACQ_REL, __ATOMIC_ACQ_REL);
    __builtin_riscv_amocas64(mem, old, new, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
}

/* { dg-final { scan-assembler-times "amocas.w" 6 } } */
/* { dg-final { scan-assembler-times "amocas.w.aq" 4 } } */
/* { dg-final { scan-assembler-times "amocas.w.rl" 1 } } */
/* { dg-final { scan-assembler-times "amocas.w.aqrl" 3 } } */

/* { dg-final { scan-assembler-times "amocas.d" 6 } } */
/* { dg-final { scan-assembler-times "amocas.d.aq" 4 } } */
/* { dg-final { scan-assembler-times "amocas.d.rl" 1 } } */
/* { dg-final { scan-assembler-times "amocas.d.aqrl" 3 } } */
