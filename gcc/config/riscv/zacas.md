(define_c_enum "unspec" [
    ;; Zacas
    UNSPEC_AMOCAS32
    UNSPEC_AMOCAS64
    UNSPEC_AMOCAS128
])

(define_insn "riscv_amocas_si_32"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec_volatile:SI [(match_operand:SI 1 "register_operand" "r")
                            (match_operand:SI 2 "memory_operand" "+A")]
                            UNSPEC_AMOCAS32))]
  "TARGET_ZACAS && !TARGET_64BIT"
  "amocas.w\t%0,%1,%2"
  [(set_attr "type" "zacas")])

(define_insn "riscv_amocas_si_64"
  [(set (match_operand:SI 0 "register_operand" "+r")
        (unspec_volatile:SI [(match_operand:SI 1 "register_operand" "r")
                            (match_operand:DI 2 "memory_operand" "+A")]
                            UNSPEC_AMOCAS32))]
  "TARGET_ZACAS && TARGET_64BIT"
  "amocas.w\t%0,%1,%2"
  [(set_attr "type" "zacas")])

(define_insn "riscv_amocas_di_32"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec_volatile:DI [(match_operand:DI 1 "register_operand" "r")
                            (match_operand:SI 2 "memory_operand" "+A")]
                            UNSPEC_AMOCAS32))]
  "TARGET_ZACAS && !TARGET_64BIT"
  {
    return "amocas.d\t%0,%1,%2";
  }
  [(set_attr "type" "zacas")])

(define_insn "riscv_amocas_di_64"
  [(set (match_operand:DI 0 "register_operand" "+r")
        (unspec_volatile:DI [(match_operand:DI 1 "register_operand" "r")
                            (match_operand:DI 2 "memory_operand" "+A")]
                            UNSPEC_AMOCAS32))]
  "TARGET_ZACAS && TARGET_64BIT"
  {
    return "amocas.d\t%0,%1,%2";
  }
  [(set_attr "type" "zacas")])

(define_insn "riscv_amocas_ti_<mode>"
  [(unspec_volatile:X [(match_operand:TI 0 "register_operand" "+r")
                    (match_operand:TI 1 "register_operand" "r")
                    (match_operand:X 2 "memory_operand" "+A")]
                    UNSPEC_AMOCAS128)]
  "TARGET_ZACAS && TARGET_64BIT"
  "amocas.q\t%0,%1,%2"
  [(set_attr "type" "zacas")])
