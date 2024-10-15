%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec minimum_steps(S :: unicode:unicode_binary()) -> integer().

minimum_steps(S) ->
    element(1, lists:foldl(fun(Char, {Res, Count}) ->
                               case Char =:= $1 of
                                    true  -> {Res, Count + 1};
                                    false -> {Res + Count, Count}
                                end
                            end, {0, 0},
                            lists:dropwhile(fun(C) -> C =:= $0 end, unicode:characters_to_list(S)))).
