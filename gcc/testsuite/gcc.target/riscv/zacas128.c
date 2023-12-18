/* { dg-do compile } */
/* { dg-options "-march=rv64g_zacas -mabi=lp64d" } */

int var;

void foo1(long long rd, long long rs2, void *rs1)
{
    __builtin_riscv_amocas128(rd, rs2, 0);
    __builtin_riscv_amocas128(rd, rs2, &var);
    __builtin_riscv_amocas128(rd, rs2, (void *)0x111);
    __builtin_riscv_amocas128(rd, rs2, rs1);
}

/* { dg-final { scan-assembler-times "amocas.q" 4 } } */
