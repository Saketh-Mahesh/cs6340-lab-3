/*
 * Copyright Â© 2021 Georgia Institute of Technology (Georgia Tech). All Rights Reserved.
 * Template code for CS 6340 Software Analysis
 * Instructors: Mayur Naik and Chris Poch
 * Head TAs: Kelly Parks and Joel Cooper
 *
 * Georgia Tech asserts copyright ownership of this template and all derivative
 * works, including solutions to the projects assigned in this course. Students
 * and other users of this template code are advised not to share it with others
 * or to make it available on publicly viewable websites including repositories
 * such as GitHub and GitLab. This copyright statement should not be removed
 * or edited. Removing it will be considered an academic integrity issue.
 *
 * We do grant permission to share solutions privately with non-students such
 * as potential employers as long as this header remains in full. However, 
 * sharing with other current or future students or using a medium to share
 * where the code is widely available on the internet is prohibited and 
 * subject to being investigated as a GT honor code violation.
 * Please respect the intellectual ownership of the course materials 
 * (including exam keys, project requirements, etc.) and do not distribute them 
 * to anyone not enrolled in the class. Use of any previous semester course 
 * materials, such as tests, quizzes, homework, projects, videos, and any other 
 * coursework, is prohibited in this course. */
#include "Extractor.h"

#include "llvm/IR/Instruction.h"

void Extractor::initialize(AnalysisMode Mode) {
  Solver->register_relation(Kill);
  Solver->register_relation(Gen);
  Solver->register_relation(Next);
  Solver->register_relation(In);
  Solver->register_relation(Out);

  /* Variables for Rules 
   * You may reuse X, Y, Z in all your rules expressions further down
   * You can also define more variables like these if you need
   * These variables are bitvectors of length 32, matching our instruction IDs created in Constraint.cpp's main()
   */
  z3::expr X = C.bv_const("X", 32);
  z3::expr Y = C.bv_const("Y", 32);
  z3::expr Z = C.bv_const("Z", 32);

  if (Mode == ReachDef) {
    // TODO: Create z3::expr rules with z3::forall and z3::implies
    // TODO: Call Solver->add_rule for all your z3::expr rules
  }
  else if (Mode == Liveness) {
    // TODO: Create z3::expr rules with z3::forall and z3::implies
    // TODO: Call Solver->add_rule for all your z3::expr rules
  }
}

void Extractor::addGen(const InstMapTy &InstMap, Instruction *X, Value *Y) {
  unsigned int Arr[2] = {InstMap.at(X), InstMap.at(Y)};
  Solver->add_fact(Gen, Arr);
}
void Extractor::addKill(const InstMapTy &InstMap, Instruction *X, Value *Y) {
  unsigned int Arr[2] = {InstMap.at(X), InstMap.at(Y)};
  Solver->add_fact(Kill, Arr);
}
void Extractor::addNext(const InstMapTy &InstMap, Instruction *X, Instruction *Y) {
  unsigned int Arr[2] = {InstMap.at(X), InstMap.at(Y)};
  Solver->add_fact(Next, Arr);
}

void Extractor::extractConstraints(const InstMapTy &InstMap, Instruction *I, AnalysisMode Mode) {
  if (Mode == ReachDef) {
    // TODO: Call addGen, addKill, addNext as needed 
  }
  else if (Mode == Liveness) {
    // TODO: Call addGen, addKill, addNext as needed 
  }
}
