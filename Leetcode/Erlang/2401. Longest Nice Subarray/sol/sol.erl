%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec longest_nice_subarray(Nums :: [integer()]) -> integer().

lns(_,              [],    _,   0, _, _) -> 1;
lns(_,              [],    _, Res, _, _) -> Res;
lns([], [First | Rest], Curr, Res, L, R) ->
    lns([First], Rest, Curr bor First, Res, L, R + 1);
lns(Prefix, [First | Rest], Curr, Res, L, R) when Curr band First == 0 ->
    lns(Prefix ++ [First], Rest, First bor Curr, max(Res, R - L  + 1), L, R + 1);
lns([Seen | RestOfSeen], Nums, Curr, Res, L, R) ->
    lns(RestOfSeen, Nums, Curr bxor Seen, Res, L + 1, R).

longest_nice_subarray(Nums) -> lns([], Nums, 0, 0, 0, 0).
