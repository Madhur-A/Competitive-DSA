%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec max_turbulence_size(Arr :: [integer()]) -> integer().

compare(A, B) when A =:= B -> 0;
compare(A, B) when A > B -> 1;
compare(A, B) -> -1.

ascetain(CurrComp, PrevComp, CurrentLength) ->
    case {CurrComp, PrevComp} of
        {0, _}               -> {CurrComp, 1};
        {CurrComp, CurrComp} -> {CurrComp, 2};
        _                    -> {CurrComp, CurrentLength + 1}
    end.

rx([], _, _, _, Res) -> Res;
rx([Current|Rest], PreviousNum, PrevComp, CurrentLength, Res) ->
    CurrComp = compare(Current, PreviousNum),
    {NewComp, NewLen} = ascetain(CurrComp, PrevComp, CurrentLength),
    rx(Rest, Current, NewComp, NewLen, max(Res, NewLen)).

max_turbulence_size(Nums) when length(Nums) < 2 -> length(Nums);
max_turbulence_size(Nums) ->
    [First|Rest] = Nums,
    rx(Rest, First, 0, 1, 1).
