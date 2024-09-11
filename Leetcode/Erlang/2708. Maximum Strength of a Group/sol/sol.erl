-module(sol).
-compile(export_all). % testing phase directive

-spec max_strength(Nums :: [integer()]) -> integer().

rx([], Curr) -> Curr;
rx([0|Rest], Curr) -> rx(Rest, Curr);
rx([Front|Rest], Curr) -> max(rx(Rest, Curr), max(rx(Rest, Curr * Front), rx(Rest, Front))).


max_strength([Front|[]]) -> Front;
max_strength(Nums) -> rx(Nums, 0).

clear() ->
	io:format("\ec").
