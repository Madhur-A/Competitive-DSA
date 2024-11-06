%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec can_sort_array(Nums :: [integer()]) -> boolean().

popcount(N) -> popcount(N, 0).

popcount(0, R) -> R;
popcount(N, R) -> popcount(N bsr 1, R + (N band 1)).

rx([]) -> [];
rx([A]) -> [A];
rx([A, B | Rest]) when A > B ->
    case popcount(A) == popcount(B) of
        true  -> rx([B, A | Rest]);
        false -> rx([]) % shorting execution
    end;
rx([A, B | Rest]) ->
    [A] ++ rx([B | Rest]).

ux([]) -> [];
ux([A]) -> [A];
ux([A, B | Rest]) when A < B ->
    case popcount(A) == popcount(B) of
        true  -> ux([B, A | Rest]);
        false -> ux([])
    end;
ux([A, B | Rest]) ->
    [A] ++ ux([B | Rest]).


decide(N) ->
    L = length(N),
    F = rx(N),
    case length(F)  of
        L ->
            B = ux(lists:reverse(F)),
            case length(B) of
                L -> true;
                _ -> false
            end;
        _ -> false
    end.

can_sort_array(Nums) -> decide(Nums).
