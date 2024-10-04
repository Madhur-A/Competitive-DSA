%% -module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

-spec divide_players(Skill :: [integer()]) -> integer().

rx(S, Left, Right, Req, Res) when Left < Right ->
    {A, B} = {element(Left, S), element(Right, S)},
    case A + B =:= Req of
        true  -> rx(S, Left + 1, Right - 1, Req, Res + A * B);
        false -> -1
    end;
rx(S, Left, Right, Req, Res) -> Res.

divide_players(Skills) ->
    S = list_to_tuple(lists:sort(Skills)),
    R = element(1, S) + element(size(S), S),
    rx(S, 1, size(S), R, 0).
