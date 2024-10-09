%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec min_add_to_make_valid(S :: unicode:unicode_binary()) -> integer().

rx([],    Res, Total) -> Res + Total;
rx([H|T], Res, Total) ->
    case H =:= 40 of
        true  -> rx(T, Res + 1, Total);
        false ->
            case Res > 0 of
                true  -> rx(T, Res - 1, Total);
                false -> rx(T, Res, Total + 1)
            end
    end.

min_add_to_make_valid(S) -> rx(unicode:characters_to_list(S), 0, 0).
