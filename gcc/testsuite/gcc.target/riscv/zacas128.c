/* { dg-do compile } */
/* { dg-options "-march=rv64g_zacas -mabi=lp64d" } */

void foo1(__int128 rd, __int128 rs2, void *rs1) {
    __builtin_riscv_amocas128(rd, rs2, rs1);
}

/* { dg-final { scan-assembler-times "amocas.q" 1 } } */