%% -module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

-spec minimum_mountain_removals(Nums :: [integer()]) -> integer().

find_left(Nums, Target, Left, Right) when Left < Right ->
    Mid = Left + ((Right - Left) bsr 1),
    Have = array:get(Mid, Nums),
    case Have < Target of
        true  -> find_left(Nums, Target, Mid + 1, Right);
        false -> find_left(Nums, Target, Left, Mid)
    end;
find_left(   _,      _, Left,     _) -> Left.

rx_lis_forward(_,     N, N,    _,    _, Res) -> Res;
rx_lis_forward(X, Index, N, Nums, Curr, Res) ->
    MostRecent = array:get(Index, Nums),
    case array:size(Curr) =/= 0 andalso array:get(array:size(Curr) - 1, Curr) >= MostRecent of
        true  ->
            InsertionIndex = find_left(Curr, MostRecent, 0, array:size(Curr)),
            NewCurr = array:set(InsertionIndex, MostRecent, Curr),
            rx_lis_forward(X, Index + 1, N, Nums, NewCurr, array:set(Index, InsertionIndex + 1, Res));
        false ->
            NewCurr = array:set(X, MostRecent, Curr),
            rx_lis_forward(X + 1, Index + 1, N, Nums, NewCurr, array:set(Index, X + 1, Res))
    end.

rx_lis_reverse(_,     N, N,    _,    _, Res) -> Res;
rx_lis_reverse(X, Index, N, Nums, Curr, Res) ->
    MostRecent = array:get(Index, Nums),
    case array:size(Curr) =/= 0 andalso array:get(array:size(Curr) - 1, Curr) >= MostRecent of
        true  ->
            InsertionIndex = find_left(Curr, MostRecent, 0, array:size(Curr)),
            NewCurr = array:set(InsertionIndex, MostRecent, Curr),
            rx_lis_reverse(X, Index - 1, N, Nums, NewCurr, array:set(Index, InsertionIndex + 1, Res));
        false ->
            NewCurr = array:set(X, MostRecent, Curr),
            rx_lis_reverse(X + 1, Index - 1, N, Nums, NewCurr, array:set(Index, X + 1, Res))
    end.

solve(    N, _, _, N, Res) -> Res;
solve(Index, L, R, N, Res) ->
    {P, S} = {array:get(Index, L), array:get(Index, R)},
    case P > 1 andalso S > 1 of
        true  -> solve(Index + 1, L, R, N, min(Res, N - P - S + 1));
        false -> solve(Index + 1, L, R, N, Res)
    end.

rx(Nums) ->
    N = length(Nums),
    Res = array:new([{size, N}, {fixed, true}, {default, 0}]),
    Left  = rx_lis_forward(0, 0,      N, array:from_list(Nums), array:new(), Res),
    Right = rx_lis_reverse(0, N - 1, -1, array:from_list(Nums), array:new(), Res),
    io:format("left  : ~p ~n", [Left]),
    io:format("right : ~p ~n", [Right]),
    solve(0, Left, Right, N, 1 bsl 32).


minimum_mountain_removals(Nums) -> rx(Nums).

clear() ->
    io:format("\ec").
