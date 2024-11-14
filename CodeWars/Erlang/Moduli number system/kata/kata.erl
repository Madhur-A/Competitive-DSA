-module(kata).
-export([fromNb2Str/2]).
% "Ooarai Joshigakuin Shōri!"

-spec fromNb2Str(integer(), [integer]) -> string.

gcd(A, 0) -> A;
gcd(A, B) -> gcd(B, A rem B).

lcm(A, B) -> (A * B) div gcd(A, B).

fromNb2Str(N, Nums) ->
    P = lists:foldl(fun(E, Res) -> Res * E end, 1, Nums),
    L = lists:foldl(fun(E, Res) -> lcm(E, Res) end, 1, Nums),
    case N < P andalso P == L of
        false -> "Not applicable";
        true  -> lists:foldl(fun(E, Res) -> Res ++ "-" ++ integer_to_list(E) ++ "-" end, "", [N rem Num || Num <- Nums])
    end.
