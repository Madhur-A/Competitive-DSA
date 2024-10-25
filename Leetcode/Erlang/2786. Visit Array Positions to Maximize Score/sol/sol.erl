%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shōri!"
-define(inf, -(1 bsl 32)).

-spec max_score(Nums :: [integer()], X :: integer()) -> integer().

set_array(Num) ->
	case Num band 1 of
		1 -> array:from_list([?inf, Num]);
		_ -> array:from_list([Num, ?inf])
	end.

%% certainly NOT functional
max_score(Nums, X) ->
	[Head | Tail] = Nums,
	EP = set_array(Head),
	DP = lists:foldl(fun(E, DP) ->
							 {I, J} = {E band 1, (E band 1) bxor 1},
							 {A, B} = {max(array:get(I, DP) + E, array:get(J, DP) + E - X), max(array:get(J, DP), array:get(I, DP) + E - X)},
							 array:set(J, B, array:set(I, A, DP))
					 end, EP, Tail),
	max(array:get(0, DP), array:get(1, DP)).

clear() ->
	io:format("\ec").
