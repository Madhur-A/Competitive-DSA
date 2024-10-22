%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec min_operations(Nums :: [integer()]) -> integer().

set_bit_count(0) -> 0;
set_bit_count(N) -> (N rem 2) + set_bit_count(N div 2).

bit_length(0) -> 0;
bit_length(N) -> 1 + bit_length(N div 2).

rx([]) -> 0;
rx(Nums) -> lists:sum(lists:map(fun(N) -> set_bit_count(N) end, Nums)) + bit_length(lists:max(Nums)) - 1.

min_operations(Nums) -> rx(lists:filter(fun(E) -> E =/= 0 end, Nums)).
