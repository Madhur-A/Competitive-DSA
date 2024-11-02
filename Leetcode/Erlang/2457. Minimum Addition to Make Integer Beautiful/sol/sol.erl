%% -module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

-spec make_integer_beautiful(N :: integer(), Target :: integer()) -> integer().

add_digits(0) -> 0;
add_digits(N) -> add_digits(N div 10) + (N rem 10).

rx(N, _, T) when N =< T -> 0;
rx(N, M, T) ->
    Sum = add_digits(N),
    case Sum =< T of
        true  -> 0;
        false -> M * (10 - N rem 10) + rx(1 + (N div 10), M * 10, T)
    end.

make_integer_beautiful(N, Target) -> rx(N, 1, Target).
