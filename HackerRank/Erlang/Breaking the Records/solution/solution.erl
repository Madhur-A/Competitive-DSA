-module(solution).
-export([main/0]).
% "Ooarai Joshigakuin Shori!"

int(true) -> 1;
int(_) -> 0.

main() ->
    io:get_line(""),
    Line = io:get_line(""),
    case Line =/= oef of
        true  ->
            [E | Nums] = lists:map(fun(E) -> element(1, string:to_integer(E)) end, string:tokens(Line, " ")),
            {Hi, Lo, _, _} = lists:foldl(fun(Score, {H, L, M, N}) -> {H + int(Score > M), L + int(Score < N), max(M, Score), min(N, Score)} end, {0, 0, E, E}, Nums),
            io:format("~p ~p", [Hi, Lo]);
        false -> ok
    end.
