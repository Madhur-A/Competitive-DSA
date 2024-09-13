%% -module(sol_improved).
-compile(export_all). % testng phase directive


-spec xor_queries(Arr :: [integer()], Queries :: [[integer()]]) -> [integer()].

prefices([], _, A) -> A;
prefices(N,  I, A) -> prefices(tl(N), I + 1, array:set(I, hd(N) bxor array:get(I-1, A), A)).

xor_queries(Nums, Queries) -> 
	R = array:new(length(Nums) + 1),
	P = prefices(Nums, 1, array:set(0, 0, R)),
    array:to_list(array:map(fun(_, [A, B]) -> array:get(B + 1, P) bxor array:get(A, P) end, array:from_list(Queries))).


clear() ->
    io:format("\ec").

