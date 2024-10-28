%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec subset_xor_sum(Nums :: [integer()]) -> integer().

reduce(          [], Res) -> Res;
reduce([First|Rest], Res) -> reduce(Rest, First bxor Res).

rx(   _, Upper, Upper, Res) -> Res;
rx(Nums, Upper, Index, Res) ->
    Indices = lists:filter(fun(J) -> ((1 bsl J) band Index) == 0 end, lists:seq(0, length(Nums))),
    Values  = lists:map(fun(I) -> case Nums == [] of
                                     true  -> 0;
                                     false -> lists:nth(I + 1, Nums)
                                 end
                       end , lists:droplast(Indices)),
    rx(Nums, Upper, Index + 1, Res + reduce(Values, 0)).

subset_xor_sum(Nums) ->
    rx(Nums, 1 bsl length(Nums), 0, 0).
