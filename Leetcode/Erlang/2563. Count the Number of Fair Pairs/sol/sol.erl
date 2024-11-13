%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec count_fair_pairs(Nums :: [integer()], Lower :: integer(), Upper :: integer()) -> integer().

find_right(Nums, Left, Right, Target) when Left < Right ->
    Mid = (Left + Right) div 2,
    case array:get(Mid, Nums) >= Target of
        true  -> find_right(Nums, Left, Mid, Target);
        false -> find_right(Nums, Mid + 1, Right, Target)
    end;
find_right(_,    Left,     _,     _) -> Left.


count_fair_pairs(Nums, Lower, Upper) ->
    N = lists:sort(Nums),
    S = array:from_list(N),
    L = length(Nums),
    element(1, lists:foldl(fun(E, {Res, I}) ->
                               {Res +
                                    find_right(S, I + 1, L, Upper - E + 1) -
                                    find_right(S, I + 1, L, Lower - E),
                                I + 1}
                           end, {0, 0}, N)).
