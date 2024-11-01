-module(solution).
-export([main/0]).
% "Ooarai Joshigakuin Shori!"

rrx(            [], _, _, Ret) -> Ret;
rrx([First | Rest], H, K, Ret) ->
    case ((First + H) rem K) =:= 0 of
        true  -> rrx(Rest, H, K, Ret + 1);
        false -> rrx(Rest, H, K, Ret)
    end.

rx(            [], _, Res) -> Res;
rx([First | Rest], K, Res) ->
    rx(Rest, K, Res + rrx(Rest, First, K, 0)).

pairs_count(Nums, K) -> rx(Nums, K, 0).

main() ->
    Line = string:trim(io:get_line("")),
    [N, K] = lists:map(fun(E) -> element(1, string:to_integer(E)) end, string:tokens(Line, " ")),
    NLine = string:trim(io:get_line("")),
    Nums = lists:map(fun(E) -> element(1, string:to_integer(E)) end, string:tokens(NLine, " ")),
    io:format("~p", [pairs_count(Nums, K)]).
