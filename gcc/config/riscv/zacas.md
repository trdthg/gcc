(define_c_enum "unspec" [
    ;; Zacas
    UNSPEC_AMOCAS
])

(define_insn "riscv_amocas_<SIDITI:mode>_<X:mode>"
  [(unspec_volatile [(match_operand:SIDITI 0 "register_operand" "+r")
                    (match_operand:SIDITI 1 "register_operand" "r")
                    (match_operand:X 2 "memory_operand" "+A")]
                    UNSPEC_AMOCAS)]
  "TARGET_ZACAS"
  "amocas.<SIDITI:amocas>\t%0,%1,%2"
  [(set_attr "type" "zacas")])
