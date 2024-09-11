-define(Dirs, [[0,1],[1,0],[0,-1],[-1,0]]).
%% -module(sol).
-compile(export_all). % testing phase directive

%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec spiral_matrix(M :: integer(), N :: integer(), Head :: #list_node{} | null) -> [[integer()]].

get_res(R, C) ->
	TempList = [[-1 || _ <- lists:seq(1, C)] || _ <- lists:seq(1, R)],
	Intermediate = lists:map(fun(Row) -> array:from_list(Row) end, TempList),
	array:from_list(Intermediate).

set_at(I, J, Value, Res) ->
	array:set(I, array:set(J, Value, array:get(I, Res)), Res).

is_valid(I, J, R, C, Res) ->
	I >= 0 andalso J >= 0 andalso I < R andalso J < C andalso array:get(J, array:get(I, Res)) =:= -1.

rx(_, _, _, _,             _, Root, Res) when Root =:= null -> lists:map(fun(Row) -> array:to_list(Row) end, array:to_list(Res));
rx(I, J, M, N, CurrDirection, Root, Res) ->
	NewRes = set_at(I, J, Root#list_node.val, Res),
	IncrementedDirection = ((CurrDirection + 1) rem 4),
	[DirI|DirJ] = lists:nth(CurrDirection + 1, ?Dirs),
	[ChangedI|ChangedJ] = lists:nth(IncrementedDirection + 1, ?Dirs),
	{NewI , NewJ} = {DirI + I, hd(DirJ) + J},
	{NewDI , NewDJ} = {ChangedI + I, hd(ChangedJ) + J},
	case is_valid(NewI, NewJ, M, N, NewRes) of
		true -> rx(NewI, NewJ, M, N, CurrDirection, Root#list_node.next, NewRes);
		false -> rx(NewDI, NewDJ, M, N, IncrementedDirection, Root#list_node.next, NewRes)
	end.

spiral_matrix(M, N, Head) ->
	Res = get_res(M, N),
	rx(0, 0, M, N, 0, Head, Res).
