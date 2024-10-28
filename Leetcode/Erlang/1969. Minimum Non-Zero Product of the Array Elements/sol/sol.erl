%% -module(sol).
-compile(export_all). % testing phase directive
-define(MOD, 1000000007).
% "Ooarai Joshigakuin Shōri!"

-spec min_non_zero_product(P :: integer()) -> integer().

power_mod(   _,     0, Res) -> Res;
power_mod(Base, Power, Res) ->
    case (Power rem 2) =:= 1 of
        true  -> power_mod((Base * Base) rem ?MOD, Power bsr 1, (Res * Base) rem ?MOD);
        false -> power_mod((Base * Base) rem ?MOD, Power bsr 1, Res)
    end.

rx(P) ->
    Num = (1 bsl P) - 1,
    (power_mod(Num - 1, Num bsr 1, 1) * Num) rem ?MOD.

min_non_zero_product(P) -> rx(P).
