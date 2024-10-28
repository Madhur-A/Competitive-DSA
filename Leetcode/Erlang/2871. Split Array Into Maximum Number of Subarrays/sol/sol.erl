%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec max_subarrays(Nums :: [integer()]) -> integer().

rx(            [],    _,     1) -> 1;
rx(            [],    _, Count) -> Count - 1;
rx([First | Rest], Curr, Count) ->
    case (Curr band First) of
        0 -> rx(Rest, -1, Count + 1);
        _ -> rx(Rest, First band Curr, Count)
    end.

max_subarrays(Nums) -> rx(Nums, -1, 1).
