%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"

-spec rotate_string(S :: unicode:unicode_binary(), Goal :: unicode:unicode_binary()) -> boolean().

fx(S, T) when size(S) =/= size(T) -> false;
fx(T, T) -> true;
fx(S, T) ->
    Doubled = <<S/binary, S/binary>>,
    case binary:match(Doubled, T) of
        nomatch -> false;
        _       -> true
    end.

rotate_string(S, T) -> fx(S, T).
