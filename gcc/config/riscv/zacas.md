(define_c_enum "unspec" [
    ;; Zacas
    UNSPEC_AMOCAS
])

(define_insn "riscv_amocas32<SIDI:mode>"
  [(unspec_volatile [(match_operand:SI 0 "memory_operand" "+A")     ;; memory
                    (match_operand:SIDI 1 "register_operand" "r")  ;; expected value
                    (match_operand:SIDI 2 "register_operand" "r")   ;; desired value
                    (match_operand:SI 3 "const_int_operand")        ;; mod_s
                    (match_operand:SI 4 "const_int_operand")]       ;; mod_f
                    UNSPEC_AMOCAS)]
  "TARGET_ZACAS && !TARGET_64BIT"
  {
    enum memmodel model_success = (enum memmodel) INTVAL (operands[3]);
    enum memmodel model_failure = (enum memmodel) INTVAL (operands[4]);
    enum memmodel model = riscv_union_memmodels (model_success, model_failure);

    if (model == MEMMODEL_SEQ_CST || model == MEMMODEL_ACQ_REL)
      return "amocas.<SIDI:amocas>.aqrl\t%0,%1,%2";
    else if (model == MEMMODEL_ACQUIRE)
      return "amocas.<SIDI:amocas>.aq\t%0,%1,%2";
    else if (model == MEMMODEL_RELEASE)
      return "amocas.<SIDI:amocas>.rl\t%0,%1,%2";
    else
      return "amocas.<SIDI:amocas>\t%0,%1,%2";
  }
  [(set_attr "type" "zacas")])

(define_insn "riscv_amocas64<SIDITI:mode>"
  [(unspec_volatile [(match_operand:DI 0 "memory_operand" "+A")       ;; memory
                    (match_operand:SIDITI 1 "register_operand" "r")  ;; expected value
                    (match_operand:SIDITI 2 "register_operand" "r")   ;; desired value
                    (match_operand:SI 3 "const_int_operand")          ;; mod_s
                    (match_operand:SI 4 "const_int_operand")]         ;; mod_f
                    UNSPEC_AMOCAS)]
  "TARGET_ZACAS && TARGET_64BIT"
  {
    enum memmodel model_success = (enum memmodel) INTVAL (operands[3]);
    enum memmodel model_failure = (enum memmodel) INTVAL (operands[4]);
    enum memmodel model = riscv_union_memmodels (model_success, model_failure);

    if (model == MEMMODEL_SEQ_CST || model == MEMMODEL_ACQ_REL)
      return "amocas.<SIDITI:amocas>.aqrl\t%0,%1,%2";
    else if (model == MEMMODEL_ACQUIRE)
      return "amocas.<SIDITI:amocas>.aq\t%0,%1,%2";
    else if (model == MEMMODEL_RELEASE)
      return "amocas.<SIDITI:amocas>.rl\t%0,%1,%2";
    else
      return "amocas.<SIDITI:amocas>\t%0,%1,%2";
  }
  [(set_attr "type" "zacas")])
