%% -module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

-spec min_non_zero_product(P :: integer()) -> integer().

power_mod(_,        0,   _, Res) -> Res;
power_mod(Base, Power, Mod, Res) ->
    case (Power rem 2) =:= 1 of 
        true  -> power_mod((Base * Base) rem Mod, Power bsr 1, Mod, (Res * Base) rem Mod);
        false -> power_mod((Base * Base) rem Mod, Power bsr 1, Mod, Res)
    end.

rx(P) ->
    Num = (1 bsl P) - 1,
    Mod = 1000000007,
    (power_mod(Num - 1, Num bsr 1, Mod, 1) * Num) rem Mod.

min_non_zero_product(P) -> rx(P).
