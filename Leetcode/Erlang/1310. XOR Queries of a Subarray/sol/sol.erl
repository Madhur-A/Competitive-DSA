%% -module(sol).
-compile(export_all). % testng phase directive

-spec xor_queries(Arr :: [integer()], Queries :: [[integer()]]) -> [integer()].

xor_queries(Nums, Queries) -> 
	P = lists:foldl(fun(E, R) -> R ++ [lists:last(R) bxor E] end, [0], Nums),
	lists:map(fun(Q) -> lists:nth(hd(tl(Q)) + 2, P) bxor lists:nth(hd(Q) + 1, P) end, Queries).

clear() ->
	io:format("\ec").
