%% -module(sol).
-compile(export_all). % testing phase directive


-spec longest_subarray(Nums :: [integer()]) -> integer().

longest([],      _,      _,     _, Ans) -> Ans;
longest(Nums, MaxE,      _,     _,   _) when hd(Nums) > MaxE -> 
    longest(tl(Nums), hd(Nums), true, 1, 1);
longest(Nums, MaxE, Streak, Found, Ans) when hd(Nums) =:= MaxE andalso Streak =:= true -> 
    longest(tl(Nums), MaxE, Streak, Found + 1, max(Ans, Found + 1));
longest(Nums, MaxE,      _, Found, Ans) ->
    longest(tl(Nums), MaxE, false, Found, Ans).

longest_subarray(Nums) -> 
    longest(Nums, -1, false, 0, 0).

clear() ->
	io:format("\ec").

