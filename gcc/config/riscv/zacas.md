(define_c_enum "unspec" [
    ;; Zacas
    UNSPEC_AMOCAS
])

(define_insn "riscv_amocas32<SIDI:mode>"
  [(unspec_volatile [(match_operand:SIDI 0 "register_operand" "+r")
                    (match_operand:SIDI 1 "register_operand" "r")
                    (match_operand:SI 2 "memory_operand" "+A")]
                    UNSPEC_AMOCAS)]
  "TARGET_ZACAS && !TARGET_64BIT"
  "amocas.<SIDI:amocas>\t%0,%1,%2"
  [(set_attr "type" "zacas")])

(define_insn "riscv_amocas64<SIDITI:mode>"
  [(unspec_volatile [(match_operand:SIDITI 0 "register_operand" "+r")
                    (match_operand:SIDITI 1 "register_operand" "r")
                    (match_operand:DI 2 "memory_operand" "+A")]
                    UNSPEC_AMOCAS)]
  "TARGET_ZACAS && TARGET_64BIT"
  "amocas.<SIDITI:amocas>\t%0,%1,%2"
  [(set_attr "type" "zacas")])
