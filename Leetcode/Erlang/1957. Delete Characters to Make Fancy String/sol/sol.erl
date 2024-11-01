%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec make_fancy_string(S :: unicode:unicode_binary()) -> unicode:unicode_binary().

no_three(        [], _, _, Res) -> Res;
no_three([F | Rest], F, F, Res) ->
    no_three(Rest, F, F, Res);
no_three([F | Rest], A, _, Res) ->
    no_three(Rest, F, A, [F] ++ Res).

make_fancy_string(S) ->
    list_to_binary(lists:reverse(no_three(unicode:characters_to_list(S), "", "\n", []))).
