/* { dg-do compile } */
/* { dg-options "-march=rv32g_zacas -mabi=ilp32" } */

void foo1(int rd, int rs2, void *rs1)
{
    __builtin_riscv_amocas32(rd, rs2, rs1, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    __builtin_riscv_amocas32(rd, rs2, rs1, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED);
    __builtin_riscv_amocas32(rd, rs2, rs1, __ATOMIC_RELAXED, __ATOMIC_RELEASE);
    __builtin_riscv_amocas32(rd, rs2, rs1, __ATOMIC_ACQUIRE, __ATOMIC_RELEASE);
    __builtin_riscv_amocas32(rd, rs2, rs1, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
}

void foo2(long rd, long rs2, void *rs1)
{
    __builtin_riscv_amocas64(rd, rs2, rs1, __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    __builtin_riscv_amocas64(rd, rs2, rs1, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED);
    __builtin_riscv_amocas64(rd, rs2, rs1, __ATOMIC_RELAXED, __ATOMIC_RELEASE);
    __builtin_riscv_amocas64(rd, rs2, rs1, __ATOMIC_ACQUIRE, __ATOMIC_RELEASE);
    __builtin_riscv_amocas64(rd, rs2, rs1, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
}

/* { dg-final { scan-assembler-times "amocas.w" 5 } } */
/* { dg-final { scan-assembler-times "amocas.w.aq" 3 } } */
/* { dg-final { scan-assembler-times "amocas.w.rl" 1 } } */
/* { dg-final { scan-assembler-times "amocas.w.aqrl" 2 } } */

/* { dg-final { scan-assembler-times "amocas.d" 5 } } */
/* { dg-final { scan-assembler-times "amocas.d.aq" 3 } } */
/* { dg-final { scan-assembler-times "amocas.d.rl" 1 } } */
/* { dg-final { scan-assembler-times "amocas.d.aqrl" 2 } } */