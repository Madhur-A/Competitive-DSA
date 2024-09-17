%% -module(sol).
-compile(export_all). % testing phase directive
%% "Ooarai Joshigakuin Shori!"

% -spec uncommon_from_sentences(S1 :: unicode:unicode_binary(), S2 :: unicode:unicode_binary()) -> [unicode:unicode_binary()].

uncommon_from_sentences(S1, S2) ->
    S = string:tokens(binary:bin_to_list(S1) ++ " " ++ binary:bin_to_list(S2), " "),
    lists:map(fun({First, _}) -> binary:list_to_bin(First) end, dict:to_list(
											  dict:filter(fun(_, V) -> V =:= 1 end, 
														  lists:foldl(fun(E, D) -> dict:update(E, fun(V) -> V + 1 end, 1, D) end, dict:new(), S)
														 ))).

clear() ->
	io:format("\ec").
