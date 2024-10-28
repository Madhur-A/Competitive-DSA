%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec min_swaps(S :: unicode:unicode_binary()) -> integer().

rx(         [], Res) -> (abs(Res) + 1) div 2;
rx([$[ | Rest], Res) -> rx(Rest, Res - 1);
rx([ _ | Rest], Res) ->
    case Res < 0 of
        true  -> rx(Rest, Res + 1);
        false -> rx(Rest, Res)
    end.

min_swaps(S) ->
    rx(unicode:characters_to_list(S), 0).
