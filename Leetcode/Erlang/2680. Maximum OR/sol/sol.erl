%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec maximum_or(Nums :: [integer()], K :: integer()) -> integer().

maximum_or(Nums, K) ->
    {PList, _} = lists:mapfoldl(fun(E, Res) -> {Res, E bor Res} end, 0, Nums),
    {SList, _} = lists:mapfoldr(fun(E, Res) -> {Res, E bor Res} end, 0, Nums),
    {P,     S} = {array:from_list(PList), array:from_list(SList)},
    {Res,  _ } = lists:foldl(
                   fun(Num, {Res, Index}) ->
                           {
                             max(Res, array:get(Index, P) bor (Num bsl K) bor array:get(Index, S)),
                             Index + 1
                           }
                   end, {0, 0}, Nums),
    Res.
