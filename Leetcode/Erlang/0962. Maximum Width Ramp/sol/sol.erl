-module(sol).
-compile(export_all). % testing phase directive
-author("Miho Nishizumi"). % "Ooarai Joshigakuin Shōri!"

%% -spec max_width_ramp(Nums :: [integer()]) -> integer().

indices(Stop,  Stop,    _,   Res) -> Res;
indices(Index, Stop, Nums, [F|R]) ->
    case element(Index, Nums) =< element(F, Nums) of
		true  -> indices(Index + 1, Stop, Nums, [Index] ++ [F|R]);
		false -> indices(Index + 1, Stop, Nums, [F|R])
	end.

rx(Stop,  Stop,    _,       _, Res) -> Res;
rx(Index, Stop, Nums, Indices, Res) ->
	case Indices =/= [] andalso element(hd(Indices), Nums) =< element(Index, Nums) of
		true  -> rx(Index, Stop, Nums, tl(Indices), max(Res, Index - hd(Indices)));
		false -> rx(Index - 1, Stop, Nums, Indices, Res)
	end.

max_width_ramp(Nums) ->
	TupledNums = list_to_tuple(Nums),
	AllIndices = indices(2, length(Nums) + 1, TupledNums, [1]),
	rx(length(Nums), 0, TupledNums, AllIndices, 0).

clear() ->
	io:format("\ec").
