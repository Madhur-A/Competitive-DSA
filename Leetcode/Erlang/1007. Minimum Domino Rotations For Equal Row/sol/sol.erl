%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"
-define(Inf, 1 bsl 31).

-spec min_domino_rotations(Tops :: [integer()], Bottoms :: [integer()]) -> integer().

add(X, X) -> 0;
add(_, _) -> 1.

check([],               [], _, A, B) -> min(A, B);
check([U|Upper], [L|Lower], T, A, B) ->
    case U =/= T andalso L =/= T of
        true  -> ?Inf;
        false -> check(Upper, Lower, T, A + add(U, T), B + add(L, T))
    end.

min_domino_rotations(Tops, Bottoms) ->
    A = check(Tops, Bottoms, hd(Tops), 0, 0),
    B = check(Tops, Bottoms, hd(Bottoms), 0, 0),
    R = min(A, B),
    case R =:= ?Inf of
        true  -> -1;
        false ->  R
    end.
