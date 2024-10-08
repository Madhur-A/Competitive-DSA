%% -module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

-spec min_swaps(S :: unicode:unicode_binary()) -> integer().

rx([],          Res) -> ceil(abs(Res) / 2);
rx([Head|Rest], Res) when Head =:= 93 -> rx(Rest, Res - 1);
rx([Head|Rest], Res) ->
    case Res < 0 of
        true  -> rx(Rest, Res + 1);
        false -> rx(Rest, Res)
    end.

min_swaps(S) -> rx(lists:reverse(unicode:characters_to_list(S)), 0).
