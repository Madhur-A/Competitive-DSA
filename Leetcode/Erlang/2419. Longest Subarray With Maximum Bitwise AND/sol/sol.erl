%% -module(sol).
-compile(export_all). % testing phase directive


-spec longest_subarray(Nums :: [integer()]) -> integer().

longest(        [],    _,      _, _, R) -> R;
longest([Num|Rest], MaxE,      _, _, R) when Num < MaxE -> longest(Rest, MaxE, false, 0, R);    
longest([Num|Rest], MaxE,      _, _, _) when Num > MaxE -> longest(Rest, Num, true, 1, 1);
longest([Num|Rest], MaxE, Streak, F, R) when Num =:= MaxE ->
	case Streak =:= true of
		true -> longest(Rest, MaxE, Streak, F + 1, max(R, F + 1));
		_    -> longest(Rest, MaxE, true, 1, R)
	end.

longest_subarray(Nums) ->
    longest(Nums, 0, false, 0, 0).

clear() ->
	io:format("\ec").
