%% -module(sol).
-compile(export_all). % testng phase directive
% "Ooarai Joshigakuin Shōri!"

-spec xor_queries(Arr :: [integer()], Queries :: [[integer()]]) -> [integer()].

xor_queries(Nums, Queries) ->
    P = lists:foldl(fun(E, R) -> [hd(R) bxor E] ++ R end, [0], Nums),
    N = length(P),
    lists:map(fun([A, B]) -> lists:nth(N - B - 1, P) bxor lists:nth(N - A, P) end, Queries).

clear() ->
    io:format("\ec").
