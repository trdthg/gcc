/* { dg-do compile } */
/* { dg-options "-march=rv64g_zacas -mabi=lp64d" } */

void foo1(void *mem, int old, int new) {
    __builtin_riscv_amocas32(mem, old, new, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
}

void foo2(void *mem, long long old, long long new) {
    __builtin_riscv_amocas64(mem, old, new, __ATOMIC_ACQUIRE, __ATOMIC_RELEASE);
}

/* { dg-final { scan-assembler-times "amocas.w" 1 } } */
/* { dg-final { scan-assembler-times "amocas.d" 1 } } */