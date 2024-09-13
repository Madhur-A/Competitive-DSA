%% -module(sol).
-compile(export_all). % testng phase directive


%% -spec xor_queries(Arr :: [integer()], Queries :: [[integer()]]) -> [integer()].

xor_queries(Nums, Queries) -> 
    P = lists:reverse(lists:foldl(fun(E, R) -> [hd(R) bxor E] ++ R end, [0], Nums)),
    lists:map(fun([A, B]) -> lists:nth(B + 2, P) bxor lists:nth(A + 1, P) end, Queries).

clear() ->
    io:format("\ec").
