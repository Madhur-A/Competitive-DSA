%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec calculate_tax(Brackets :: [[integer()]], Income :: integer()) -> float().

no_negatives(N) when N =< 0 -> 0;
no_negatives(N) -> N.

fx([],                  _,    _, Res) -> Res;
fx( _,                  0,    _, Res) -> Res;
fx([First | Rest], Income, Prev, Res) ->
    [Curr, Rate] = First,
    TaxableIncome   = min(Curr - Prev, Income),
    RemainingIncome = Income - TaxableIncome,
    fx(Rest, no_negatives(RemainingIncome), Curr, Res + (TaxableIncome * (Rate / 100.0))).

calculate_tax(Brackets, Income) -> fx(Brackets, Income, 0, 0.0).
