/* { dg-do compile } */
/* { dg-options "-march=rv64g_zacas -mabi=lp64d" } */

void foo1(int rd, int rs2, void *rs1) {
    __builtin_riscv_amocas32(rd, rs2, rs1, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
}

void foo2(long rd, long rs2, void *rs1) {
    __builtin_riscv_amocas64(rd, rs2, rs1, __ATOMIC_ACQUIRE, __ATOMIC_RELEASE);
}

/* { dg-final { scan-assembler-times "amocas.w" 1 } } */
/* { dg-final { scan-assembler-times "amocas.d" 1 } } */