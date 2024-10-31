-module(solution).
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shori!"
-compile(export_all). % testing phase directive

% https://www.hackerrank.com/challenges/kangaroo/problem

process([_, U, _, V]) when U =< V -> "NO";
process([A, U, B, V]) ->
    case (B - A) rem (U - V) of
        0 -> "YES";
        _ -> "NO"
    end.

main() ->
    Incoming = io:get_line(""),
    [Line | _ ] = string:replace(Incoming, "\n", ""),
    case Incoming =/= eof of
        true  ->
            Res = process(lists:map(fun(E) -> element(1, string:to_integer(E)) end, string:tokens(Line, " "))),
            io:format("~s~n", [Res]);
        false -> io:format("")
    end.
