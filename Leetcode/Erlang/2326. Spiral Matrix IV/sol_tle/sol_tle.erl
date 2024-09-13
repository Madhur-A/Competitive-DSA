-define(Dirs, [[0,1],[1,0],[0,-1],[-1,0]]).
-module(sol_tle). % but it is a true blue pure functional, referentially transparent program! alas, it is TLE!
-compile(export_all). % testing phase directive


-record(list_node, {val = 0 :: integer(),
                    next = null :: 'null' | #list_node{}}).

create_node_list([]) -> null; %#list_node{};
create_node_list([H|T]) ->
	#list_node{val = H, next = create_node_list(T)}.

print_nodes(N) when N =/= null ->
	io:format("~p ", [N#list_node.val]),
	print_nodes(N#list_node.next);
print_nodes(_) -> io:format(io_lib:nl()).


%% -spec spiral_matrix(M :: integer(), N :: integer(), Head :: #list_node{} | null) -> [[integer()]].

get_res(R, C) ->
	[[-1 || _ <- lists:seq(1,C)] || _ <- lists:seq(1,R)].

is_valid(I, J, Res) ->
	I >= 1 andalso J >= 1 andalso I < erlang:length(Res) + 1 andalso J < erlang:length(hd(Res)) + 1 andalso lists:nth(J, lists:nth(I, Res)) =:= -1.

modify(I, J, UpdatedValue, Res) ->
	{Upper, Lower} = lists:split(I, Res),
	Row = lists:nth(I, Upper),
	{Head, Rest} = lists:split(J, Row),
	lists:droplast(Upper) ++ [lists:droplast(Head) ++ [UpdatedValue] ++ Rest] ++ Lower.

increment_direction(CurrDirection) ->
	NewDirection = (CurrDirection + 1) rem 4,
	case NewDirection =:= 0 of
			true -> 4;
			false -> NewDirection
    end.

rx(_, _, _, null, Res) -> Res;
rx(I, J, CurrDirection, Root, Res) ->
	NewRes = modify(I, J, Root#list_node.val, Res),
	ChangedDirection = increment_direction(CurrDirection),
	[DirI|DirJ] = lists:nth(CurrDirection, ?Dirs),
	[ChangedI|ChangedJ] = lists:nth(ChangedDirection, ?Dirs),
	{NewI , NewJ} = {DirI + I, hd(DirJ) + J},
	{NewDI , NewDJ} = {ChangedI + I, hd(ChangedJ) + J},
	case is_valid(NewI, NewJ, NewRes) of
		true -> rx(NewI, NewJ, CurrDirection, Root#list_node.next, NewRes);
		false -> rx(NewDI, NewDJ, ChangedDirection, Root#list_node.next, NewRes)
	end.

spiral_matrix(M, N, Head) ->
	Res = get_res(M, N),
	rx(1, 1, 1, Head, Res).


clear() ->
	io:format("\ec").
