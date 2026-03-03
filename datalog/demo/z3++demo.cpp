#include <z3++.h>

int main(int argc, char **argv) {
    z3::context Ctx;
    z3::fixedpoint *Solver = new z3::fixedpoint(Ctx);
    z3::params *Params = new z3::params(Ctx);
    Params->set("engine", "datalog");
    Solver->set(*Params);

    z3::sort Int32Type = Ctx.bv_sort(32);
    z3::sort BooleanType = Ctx.bool_sort();

    z3::func_decl A = Ctx.function("A", Int32Type, Int32Type, BooleanType);
    Solver->register_relation(A);
    z3::func_decl B = Ctx.function("B", Int32Type, Int32Type, BooleanType);
    Solver->register_relation(B);
    z3::func_decl C = Ctx.function("C", Int32Type, Int32Type, BooleanType);
    Solver->register_relation(C);

    z3::expr X = Ctx.bv_const("X", 32);
    z3::expr Y = Ctx.bv_const("Y", 32);
    z3::expr Z = Ctx.bv_const("Z", 32);

    std::cout << "define A(X, Y) :- B(X, Z), C(Z, Y)." << std::endl;
    z3::expr R0 = z3::forall(X, Y, Z, z3::implies(B(X,Z) && C(Z, Y), A(X,Y)));
    Solver->add_rule(R0, Ctx.str_symbol("R0"));

    enum { FOO, BAR, BAZ };

    std::cout << "add fact B(FOO, BAR)" << std::endl;
    unsigned int FooBar[2] = {FOO, BAR};
    Solver->add_fact(B, FooBar);

    std::cout << "add fact C(BAR, BAZ)" << std::endl;
    unsigned int BarBaz[2] = {BAR, BAZ};
    Solver->add_fact(C, BarBaz);

    std::cout << "query A(FOO, BAZ)? (Expect 'sat'): ";
    z3::expr Q = A(Ctx.bv_val(FOO, 32), Ctx.bv_val(BAZ, 32));
    z3::check_result Result = Solver->query(Q);
    std::cout << Result << std::endl;

    return 0;
}