-module(sol).
%% -compile(export_all). % testing phase directive
-export([main/0, clear/0]).
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

% at the time of posting this I couldn't run this on Kattis

process(Line) ->
    N = length(Line),
    {Sum, Seen, _} = lists:foldl(fun(E, {Acc, Seen, Beat}) ->
                                         {Acc + (E - $0), ordsets:add_element((Beat + (E - $0)) rem N, Seen), Beat + 1}
                                 end, {0, ordsets:new(), 1}, Line),
    Rem = Sum rem N,
    case Rem =/= 0 of
        true  -> io:format("~s: invalid # of balls~n", [Line]);
        false ->
            case ordsets:size(Seen) == N of
                false -> io:format("~s: invalid pattern~n", [Line]);
                true  -> io:format("~s: valid with ~p balls~n", [Line, Sum div N])
            end
    end.

main() ->
    Incoming = io:get_line(""),
    case Incoming =/= eof of
        true  ->
            [Line | _ ] = string:replace(Incoming, "\n", ""),
            process(Line),
            main();
        false -> ok
    end.

clear() ->
    io:format("\ec").
