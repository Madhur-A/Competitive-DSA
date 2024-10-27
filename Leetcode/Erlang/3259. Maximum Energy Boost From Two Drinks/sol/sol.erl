%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec max_energy_boost(EnergyDrinkA :: [integer()], EnergyDrinkB :: [integer()]) -> integer().

rx(_, _, MaxA, MaxB,     N, N) -> max(MaxA, MaxB);
rx(A, B, MaxA, MaxB, Index, N) ->
    rx(A, B, max(MaxB, MaxA + array:get(Index, B)), max(MaxA, MaxB + array:get(Index, A)), Index + 1, N).

max_energy_boost(A, B) ->
    rx(array:from_list(A), array:from_list(B), 0, 0, 0, length(A)).
