%% -module(sol).
-compile(export_all). % testing phase directive

-spec max_strength(Nums :: [integer()]) -> integer().

rx(Nums, Curr) when Nums == [] -> Curr;
rx([Front|Rest], Curr) when Front == 0 -> rx(Rest, Curr);
rx([Front|Rest], Curr) -> max(rx(Rest, Curr), max(rx(Rest, Curr * Front), rx(Rest, Front))).

max_strength([Front|Rest]) when Rest == [] -> Front;
max_strength(Nums) -> rx(Nums, 0).

