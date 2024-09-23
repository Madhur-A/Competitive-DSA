%% -module(sol).
-compile(export_all). % testing phase directive
% "Ooarai Joshigakuin Shori!"

%% Definition for singly-linked list.
%%
%% -record(list_node, {val = 0 :: integer(),
%%                     next = null :: 'null' | #list_node{}}).

-spec next_larger_nodes(Head :: #list_node{} | null) -> [integer()].

get_values(null, Res) -> Res;
get_values(Head, Res) ->
	get_values(Head#list_node.next, [Head#list_node.val] ++ Res).

curtail_r([],     _) -> [];
curtail_r([First|Rest],  Value) ->
	case First =< Value of
		true  -> curtail_r(Rest, Value);
		false -> [First|Rest]
	end.

monotonic_fetch([], _, Ans) -> Ans;
monotonic_fetch(V,  R, Ans) ->
	[Top|Rest] = V,
	NewR = curtail_r(R, Top),
	case NewR =:= [] of
		true  -> monotonic_fetch(Rest, [Top] ++ R, [0] ++ Ans);
		false -> monotonic_fetch(Rest, [Top] ++ R, [hd(NewR)] ++ Ans)
	end.

next_greater(Node) ->
	Values = get_values(Node, []),
	monotonic_fetch(Values, [], []).

next_larger_nodes(Head) -> next_greater(Head).
