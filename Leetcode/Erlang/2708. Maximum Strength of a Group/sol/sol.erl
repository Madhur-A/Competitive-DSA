%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec max_strength(Nums :: [integer()]) -> integer().

rx(       [], Curr) -> Curr;
rx([0 |Rest], Curr) -> rx(Rest, Curr);
rx([F |Rest], Curr) -> max(rx(Rest, Curr), max(rx(Rest, Curr * F), rx(Rest, F))).

max_strength([F |[]]) -> F;
max_strength(Numbers) -> rx(Numbers, 0).

clear() ->
    io:format("\ec").
