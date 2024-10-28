%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

parse(InputString) ->
    [First, Second] = string:split(InputString, ":"),
    {{Hours, _}, {Minutes, _}} = {string:to_integer(First), string:to_integer(Second)},
    Hours * 60 + Minutes.

get_min([First, Second], Res) -> min(Second - First, Res);
get_min([First, Second|Rest], Res) ->
    get_min([Second|Rest], min((Second - First), Res)).

minimum_difference(Points) ->
    P = lists:sort(lists:map(fun(I) -> parse(I) end, Points)),
    get_min(P ++ [hd(P) + 1440], 1 bsl 12).

find_min_difference(TimePoints) when length(TimePoints) > 1440 -> 0;
find_min_difference(TimePoints) ->
    minimum_difference(lists:map(fun(E) -> binary_to_list(E) end, TimePoints)).

clear() ->
    io:format("\ec").
